//#include "PlayerHUD.h"
//
//
//
//
//
//UPlayerHUD::UPlayerHUD()
//{
//	PrimaryActorTick.bCanEverTick = true; //enables the tick function for this class
//	HungerPercentage = 1.0f; //sets the hunger percentage to 100% at the start of the game
//}
//
//void UPlayerHUD::BeginPlay()
//{
//	Super::BeginPlay();
//
//	UE_LOG(LogTemp, Warning, TEXT("Player HUD has begun play!")); //logs a message to the output log when the player hud begins play
//
//	if (PlayerHUDClass)
//	{
//		HUD = CreateWidget<UPlayerHUD>(GetWorld(), PlayerHUDClass); //creates the player hud and assigns it to the PlayerHUD variable
//
//		if (HUD)
//		{
//			HUD->AddToViewport(); //put the hunger bar onto the screen
//		}
//	}
//}
//
//
//void UPlayerHUD::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	HungerState(); //calls the hunger state function every tick to update the hunger bar and text
//}
//
//
//
//
//
//void UPlayerHUD::HungerState()
//{
//	//this function is called every tick to update the hunger bar and text based on the current hunger percentage
//	SetHungerBar(HungerPercentage * 100, 100); //calls the SetHungerBar function with the current hunger percentage and max hunger of 100
//}
//
//
//
//
//
//




//	HungerBar->SetPercent(1.0f); //sets bar to be full at the start of the game
//	HungerText->SetText(FText::FromString("100/100")); //sets text to be 100% at the start of the game
//}
//
//void UPlayerHUD::SetHungerBar(float CurrentHunger, float MaxHunger)
//
//{
//	//creating colours for my hunger bar to change to as the player gets hungrier
//	constexpr FLinearColor RedColor = FLinearColor(1.0f, 0.0f, 0.0f); //red - low hunger
//	constexpr FLinearColor OrangeColor = FLinearColor(1.0f, 0.15f, 0.0f);//orange- medium hunger
//	constexpr FLinearColor GreenColor = FLinearColor(0.0f, 1.0f, 0.0f);//green- high hunger
//
//	if (CurrentHunger <= 30)
//	{
//		HungerBar->SetFillColorAndOpacity(RedColor); //if hunger bar is below 30 it turns red
//	}
//	else if (CurrentHunger > 30 && CurrentHunger < 70)
//	{
//		HungerBar->SetFillColorAndOpacity(OrangeColor); //if hunger bar is between 31 and 69 it turns orange
//	}
//	else if (CurrentHunger >= 70)
//	{
//		HungerBar->SetFillColorAndOpacity(GreenColor);//if hunger bar is 70 or above it turns green
//	}
//
//	HungerBar->SetPercent(CurrentHunger / MaxHunger); //sets the percentage of the hunger bar based on the current hunger and max hunger
//
//	FString currentHungerString = FString::FromInt(CurrentHunger); //creates a string for the current health value
//	FString maxHungerString = FString::FromInt(MaxHunger);//creates a string for the max health value
//
//	HungerText->SetText(FText::FromString(currentHungerString + "/" + maxHungerString));
//}

//void UPlayerHUD::NativeTick(const FGeometry& MyGeometry, float DeltaTime, float HungerDepletionRate, float CurrentHunger)
//{
//	
//
//	HungerDepletionRate = 5.f; // Set the hunger depletion rate (adjust this value as needed)
//	CurrentHunger -= HungerDepletionRate * DeltaTime; // Decrease hunger based on the depletion rate and delta time
//
//}