// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramworks/UserWidget.h"
#include "HungerBar.generated.h"

UCLASS()
class MGP_2526_API AHungerBar : public ACharacter
{
	GENERATED_BODY()

	


public:
	// Sets default values for this character's properties
	AHungerBar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void UpdateHungerBar(float* value,float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Hunger = 100.0f;


	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, category = "HUD")
	TSubclassOf<UUSERWidget> HUDTYPE;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, category = "HUD")
	HungerBar* HUD;



};
