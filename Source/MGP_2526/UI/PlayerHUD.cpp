#include "UI/PlayerHUD.h"




void UPlayerHUD::NativeConstruct()
{
	Super::NativeConstruct();
	HungerBar->SetPercent(1.0f); //sets bar to be full at the start of the game
	HungerText->SetText(FText::FromString("100/100")); //sets text to be 100% at the start of the game
}

void UPlayerHUD::SetHungerBar(float CurrentHunger, float MaxHunger)
{
	//creating colours for my hunger bar to change to as the player gets hungrier
	constexpr FLinearColor RedColor = FLinearColor(1.0f, 0.0f, 0.0f); //red - low hunger
	constexpr FLinearColor OrangeColor = FLinearColor(1.0f, 0.15f, 0.0f);//orange- medium hunger
	constexpr FLinearColor GreenColor = FLinearColor(0.0f, 1.0f, 0.0f);//green- high hunger

	if (CurrentHunger <= 30)
	{
		HungerBar->SetFillColorAndOpacity(RedColor); //if hunger bar is below 30 it turns red
	}
	else if (CurrentHunger > 30 && CurrentHunger < 70)
	{
		HungerBar->SetFillColorAndOpacity(OrangeColor); //if hunger bar is between 31 and 69 it turns orange
	}
	else if (CurrentHunger >= 70)
	{
		HungerBar->SetFillColorAndOpacity(GreenColor);//if hunger bar is 70 or above it turns green
	}

	HungerBar->SetPercent(CurrentHunger / MaxHunger); //sets the percentage of the hunger bar based on the current hunger and max hunger

	FString currentHungerString = FString::FromInt(CurrentHunger); //creates a string for the current health value
	FString maxHungerString = FString::FromInt(MaxHunger);//creates a string for the max health value

	HungerText->SetText(FText::FromString(currentHungerString + "/" + maxHungerString));
}
