// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UI/PlayerHUD.h"

#include "MGP_2526PlayerController.generated.h"


class UInputMappingContext;
class UUserWidget;

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UCLASS(abstract)
class AMGP_2526PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime,) override;
	
protected:

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;

	/** Pointer to the mobile controls widget */
	TObjectPtr<UUserWidget> MobileControlsWidget;

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	UPROPERTY()
	TObjectPtr<UPlayerHUD> PlayerHUD;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "UI")
	TSubclassOf<UPlayerHUD> PlayerHUDClass;

	UPROPERTY()
	UPlayerHUD* PlayerHUDWidget; // store reference to widget

};
