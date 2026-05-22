// Copyright Epic Games, Inc. All Rights Reserved.


#include "MGP_2526PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "MGP_2526.h"
#include "MGP_2526Character.h"	
#include "Widgets/Input/SVirtualJoystick.h"
#include "UI/PlayerHUD.h"

void AMGP_2526PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogMGP_2526, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}

	PlayerHUD = CreateWidget<UPlayerHUD>(this, PlayerHUDClass); //creates the player hud and assigns it to the PlayerHUD variable
	if (PlayerHUDClass)
	{

		PlayerHUD->AddToViewport(); //put the hunger bar onto the screen

	}
	//########################################################################possibnly call here? to make it change but use variable. to make it add every second, ctreate the function in the tivk)#############################################################

	//PlayerHUD->SetHungerBar(CurrentHunger, 100.f); //test to see if bar successfully depletes and changes colour
}

//void AMGP_2526PlayerController::Tick(float DeltaTime, float CurrentHunger)
//{
//	Super::Tick(DeltaTime);
//
//	
//
//
//	PlayerHUD->SetHungerBar(CurrentHunger, 100.f);
//}

//void AMGP_2526PlayerController::Tick(float DeltaTime, float CurrentHunger)
//{
//	Super::Tick(DeltaTime);
//	PlayerHUD->SetHungerBar(CurrentHunger, 100.f);
//}

void AMGP_2526PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Example: use a member variable for hunger instead of passing it as a parameter
	UpdateHunger(Hunger);  // You calculate/update Hunger elsewhere
}


void AMGP_2526PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMC's if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}
