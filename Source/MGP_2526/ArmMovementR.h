#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ArmMovementR.generated.h"

UCLASS(Blueprintable)
class MGP_2526_API UArmMovementR : public UAnimInstance
{
    GENERATED_BODY()

public:
    // Horizontal arm aim
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Arm")
    float AimX = 0.f;

    // Vertical arm aim
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Arm")
    float AimY = 0.f;

    // Constructor
    UArmMovementR();
};