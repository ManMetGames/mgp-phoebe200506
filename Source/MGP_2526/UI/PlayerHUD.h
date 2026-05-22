#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class MGP_2526_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> HungerText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UProgressBar> HungerBar;

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

public:

	UFUNCTION()
	virtual void NativeConstruct() override;

	UFUNCTION()
	void SetHungerBar(float CurrentHunger, float MaxHunger);

};
