#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ArmMovementR.generated.h"

UCLASS()
class MGP_2526_API UArmMovementR : public UAnimInstance
{
    GENERATED_BODY()

public:
    // Horizontal arm aim
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Arm")
    float AimX;

    // Vertical arm aim
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Arm")
    float AimY;

    // Optional: constructor to set defaults
    UArmMovementR();
};