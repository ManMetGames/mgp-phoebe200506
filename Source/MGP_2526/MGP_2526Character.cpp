// Copyright Epic Games, Inc. All Rights Reserved.

#include "MGP_2526Character.h"
#include "ArmMovementR.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "MGP_2526.h"
#include "Animation/AnimInstance.h"

AMGP_2526Character::AMGP_2526Character()
{
	PrimaryActorTick.bCanEverTick = true;
	bool bIsDragging = false;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	PrimaryActorTick.bCanEverTick = true;
	bIsDragging = false;
	AimX = 0.f;
	AimY = 0.f;
	MouseDelta = FVector2D::ZeroVector;
}

void AMGP_2526Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);


	//bindings for clicking and releasing the right mouse button
	PlayerInputComponent->BindAction("RightMouse", EInputEvent::IE_Pressed, this, &AMGP_2526Character::OnRightMouseButtonPressed); //right button pressed
	PlayerInputComponent->BindAction("RightMouse", EInputEvent::IE_Released, this, &AMGP_2526Character::OnRightMouseButtonReleased); //right button released

	PlayerInputComponent->BindAxis("MouseX", this, &AMGP_2526Character::OnMouseMoveX); //moving mouse on X axis
	PlayerInputComponent->BindAxis("MouseY", this, &AMGP_2526Character::OnMouseMoveY); //moving mouse on Y axis

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMGP_2526Character::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AMGP_2526Character::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMGP_2526Character::Look);
	}
	else
	{
		UE_LOG(LogMGP_2526, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}

	


}

void AMGP_2526Character::OnRightMouseButtonPressed()
{
	//sets the boolean to true when holding the right mouse button down
	bIsDragging = true;
	UE_LOG(LogTemp, Warning, TEXT("right mouse clicked"));
}

void AMGP_2526Character::OnRightMouseButtonReleased()
{
	//sets the boolean to false when not the right mouse button down/ when releasing the right mouse button
	bIsDragging = false;
	MouseDelta = FVector2D::ZeroVector; //resets the mouse delta to zero when we stop dragging
}

void AMGP_2526Character::OnMouseMoveX(float AxisValue)
{
	//if we are holding the right mouse button, get the mouse movement on the X axis and add it to MouseDelta.X
	if (bIsDragging)
	{
		MouseDelta.X += AxisValue;
	}
}
void AMGP_2526Character::OnMouseMoveY(float AxisValue)
{
	//if we are holding the right mouse button, get the mouse movement on the Y axis and add it to MouseDelta.Y
	if (bIsDragging)
	{
		MouseDelta.Y += AxisValue;
	}
}

void AMGP_2526Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if we are dragging, update the AimX and AimY values based on the MouseDelta and Sensitivity, then reset MouseDelta to zero
	if (bIsDragging)
	{
		//updates aim values based on mouse movement, sensitivity, and delta time, and clamps them between -1 and 1
				// Add mouse delta to Aim values
		AimX += MouseDelta.X * Sensitivity;
		AimY += MouseDelta.Y * Sensitivity;

		// Clamp values to BlendSpace range
		AimX = FMath::Clamp(AimX, -1.f, 1.f);
		AimY = FMath::Clamp(AimY, -1.f, 1.f);


		MouseDelta = FVector2D::ZeroVector;

		UArmMovementR* AnimInstance = Cast<UArmMovementR>(GetMesh()->GetAnimInstance());
		if (AnimInstance)
		{
			AnimInstance->AimX = AimX;
			AnimInstance->AimY = AimY;
		}
	}
}


void AMGP_2526Character::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void AMGP_2526Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void AMGP_2526Character::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void AMGP_2526Character::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AMGP_2526Character::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void AMGP_2526Character::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}


