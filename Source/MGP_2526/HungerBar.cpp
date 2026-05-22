// Fill out your copyright notice in the Description page of Project Settings.


#include "HungerBar.h"

// Sets default values
AHungerBar::AHungerBar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHungerBar::BeginPlay()
{
	Super::BeginPlay();
	
	if (HUDTYPE)
	{
		HUD = CreateWidget<UUSERWidget>(GetWorld(), HUDTYPE);
		if (HUD)
		{
			HUD->AddToViewport();
		}
	}
}

// Called every frame
void AHungerBar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateHungerBar(&Hunger, DeltaTime);
}

// Called to bind functionality to input
void AHungerBar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AHungerBar::UpdateValue()
{
	if (Hunger > 0)
	{
		Hunger -= 0.1f;
	}
	else
	{
		Hunger = 0;
	}
	
}

