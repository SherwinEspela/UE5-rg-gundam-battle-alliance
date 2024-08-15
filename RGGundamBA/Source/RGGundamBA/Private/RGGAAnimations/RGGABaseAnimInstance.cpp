// Fill out your copyright notice in the Description page of Project Settings.


#include "RGGAAnimations/RGGABaseAnimInstance.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "Characters/RGGBaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Enums/MovementStatesEnum.h"

void URGGABaseAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	BaseCharacter = Cast<ARGGBaseCharacter>(TryGetPawnOwner());
	if (BaseCharacter)
	{
		MovementComponent = BaseCharacter->GetCharacterMovement();
	}
}

void URGGABaseAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (BaseCharacter)
	{
		FRotator AimRotation = BaseCharacter->GetBaseAimRotation();
		MovementRotation = UKismetMathLibrary::MakeRotFromX(BaseCharacter->GetVelocity());
		MovementOffsetYaw = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;

		if (MovementComponent)
		{
			MovementSpeed = UKismetMathLibrary::VSizeXY(MovementComponent->Velocity);
		}
	}
}

void URGGABaseAnimInstance::HandleIdleAnimationStarted()
{
	if (BaseCharacter)
	{
		BaseCharacter->SetMovementState(EMovementStates::EMS_Idle);
	}
}

void URGGABaseAnimInstance::HandleJumpAnimationEnded()
{
	if (BaseCharacter)
	{
		BaseCharacter->SetMovementState(EMovementStates::EMS_Idle);
	}
}
