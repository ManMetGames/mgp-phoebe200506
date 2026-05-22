//#pragma once
//
//#include "CoreMinimal.h"
//#include "Blueprint/UserWidget.h"
//#include "GameFramework/Character.h"
//#include "Components/TextBlock.h"
//#include "Components/ProgressBar.h"
//
//#include "PlayerHUD.generated.h"
//
///**
// * 
// */
//UCLASS()
//class MGP_2526_API UPlayerHUD : public ACharacter
//{
//	GENERATED_BODY()
//
//	/*UPROPERTY(EditAnywhere, meta = (BindWidget))
//	TObjectPtr<UTextBlock> HungerText;
//
//	UPROPERTY(EditAnywhere, meta = (BindWidget))
//	TObjectPtr<UProgressBar> HungerBar;*/
//
//protected:
//	virtual void BeginPlay() override;
//	void UpdateValue(float* value, float DeltaTime);
//
//public:
//	UPlayerHUD();
//
//public:
//
//	virtual void Tick(float DeltaTime) override;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
//	float HungerPercentage;
//
//
//	UFUNCTION()
//	void HungerState();
//
//
//
//	UFUNCTION()
//	/*void SetHungerBar(float CurrentHunger, float MaxHunger);*/
//
//	UPROPERTY(EditDefaultOnly, BlueprintReadWrite, Category = "HUD")
//	TSubclassOf<UPlayerHUD> PlayerHUDClass;
//
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD")
//	UUserWidget* PlayerHUDWidget;
//};
