// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "UMyAnimInstance.generated.h"

/**
 * 
 */

UCLASS()
class MGP_2526_API UMyAnimInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Arm")
	float AimX = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Arm")
	float AimY = 0.f;

};
