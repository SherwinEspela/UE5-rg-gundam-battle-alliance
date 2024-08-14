// Copyright 2024 Sherwin Espela. All rights reserved.

#include "Characters/GundamRX93Character.h"
#include "Camera/CameraComponent.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Items/Weapons/RX93Rifle.h"
#include "Items/Weapons/RX93Shield.h"
#include "RGGAAnimations/RX93AnimInstance.h"
#include "ActorComponents/GroundHeightDetectorAC.h"
#include "ActorComponents/JumpGravityController.h"
#include "ActorComponents/ThrusterVfxController.h"
#include "Particles/ParticleSystemComponent.h"

AGundamRX93Character::AGundamRX93Character()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bInheritPitch = true;
	CameraBoom->bInheritYaw = true;
	CameraBoom->bInheritRoll = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxAcceleration = 2900.f;
	GetCharacterMovement()->MaxWalkSpeed = 2900.f;

	GroundHeightDetector = CreateDefaultSubobject<UGroundHeightDetectorAC>(TEXT("Ground Height Detector"));
	JumpGravityController = CreateDefaultSubobject<UJumpGravityController>(TEXT("Jump Gravity Controller"));
	ThrusterVfxController = CreateDefaultSubobject<UThrusterVfxController>(TEXT("Thruster Controller"));

	FXBackpackFXLT = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXBackpackFXLT"));
	FXBackpackFXLT->SetupAttachment(GetMesh(), FName("SocketBackpackVfxLT"));

	FXBackpackFXRT = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXBackpackFXRT"));
	FXBackpackFXRT->SetupAttachment(GetMesh(), FName("SocketBackpackVfxRT"));

	FXBackpackFXLB = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXBackpackFXLB"));
	FXBackpackFXLB->SetupAttachment(GetMesh(), FName("SocketBackpackVfxLB"));

	FXBackpackFXRB = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXBackpackFXRB"));
	FXBackpackFXRB->SetupAttachment(GetMesh(), FName("SocketBackpackVfxRB"));

	FXCalfFXL = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXCalfFXL"));
	FXCalfFXL->SetupAttachment(GetMesh(), FName("SocketCalfVfxL"));

	FXCalfFXR = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXCalfFXR"));
	FXCalfFXR->SetupAttachment(GetMesh(), FName("SocketCalfVfxR"));

	FXFootFXL = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXFootFXL"));
	FXFootFXL->SetupAttachment(GetMesh(), FName("SocketFootVfxL"));

	FXFootFXR = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXFootFXR"));
	FXFootFXR->SetupAttachment(GetMesh(), FName("SocketFootVfxR"));

	FXBackpackFXLT->SetWorldScale3D(FVector(15.f, 15.f, 15.f));
	FXBackpackFXRT->SetWorldScale3D(FVector(15.f, 15.f, 15.f));
	FXBackpackFXLB->SetWorldScale3D(FVector(15.f, 15.f, 15.f));
	FXBackpackFXRB->SetWorldScale3D(FVector(15.f, 15.f, 15.f));
	FXCalfFXL->SetWorldScale3D(FVector(15.f, 15.f, 15.f));
	FXCalfFXR->SetWorldScale3D(FVector(15.f, 15.f, 15.f));
	FXFootFXL->SetWorldScale3D(FVector(15.f, 15.f, 15.f));
	FXFootFXR->SetWorldScale3D(FVector(15.f, 15.f, 15.f));
}

void AGundamRX93Character::BeginPlay()
{
	Super::BeginPlay();

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bInheritPitch = true;
	CameraBoom->bInheritYaw = true;
	CameraBoom->bInheritRoll = true;

	FollowCamera->bUsePawnControlRotation = true;

	RX93AnimInstance = Cast<URX93AnimInstance>(GetMesh()->GetAnimInstance());

	AttachWeapons();

	GroundHeightDetector->OnDistanceToGroundReached.AddDynamic(this, &AGundamRX93Character::HandleDistanceToGroundReached);

	SetThrusterVFXActive(false);
}

void AGundamRX93Character::AttachWeapons()
{
	FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);

	if (RifleClass)
	{
		Rifle = GetWorld()->SpawnActor<ARX93Rifle>(RifleClass);
		Rifle->AttachToComponent(GetMesh(), TransformRules, FName("RightHandWeaponSocket"));
	}

	if (ShieldClass)
	{	
		Shield = GetWorld()->SpawnActor<ARX93Shield>(ShieldClass);
		Shield->AttachToComponent(GetMesh(), TransformRules, FName("ShieldSocket"));
	}
}

void AGundamRX93Character::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
		MovementStopped(false);
	}
}

void AGundamRX93Character::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGundamRX93Character::MovementStopped(bool Value)
{
	if (RX93AnimInstance)
	{
		RX93AnimInstance->MovementStopped(Value);
	}
}

void AGundamRX93Character::Jump()
{
	Super::Jump();
	GetCharacterMovement()->bNotifyApex = true;
	JumpGravityController->HandleJumpStarted();
	SetThrusterVFXActive(true);
}

void AGundamRX93Character::HandleReachedJumpApex()
{
	if (GroundHeightDetector) GroundHeightDetector->MeasureGroundDistance();
	if (JumpGravityController)
	{
		JumpGravityController->HandleJumpApexReached();
	}

	SetThrusterVFXActive(false);
}

void AGundamRX93Character::HandleDistanceToGroundReached()
{
	if (JumpGravityController)
	{
		JumpGravityController->Reset();
	}
}

void AGundamRX93Character::SetThrusterVFXActive(bool Value)
{
	FXBackpackFXLT->SetActive(Value);
	FXBackpackFXRT->SetActive(Value);
	FXBackpackFXLB->SetActive(Value);
	FXBackpackFXRB->SetActive(Value);
	FXCalfFXL->SetActive(Value);
	FXCalfFXR->SetActive(Value);
	FXFootFXL->SetActive(Value);
	FXFootFXR->SetActive(Value);
}
