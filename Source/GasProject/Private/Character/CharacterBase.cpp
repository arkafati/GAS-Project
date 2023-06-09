// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);

	FirstPersonCam = CreateDefaultSubobject<UCameraComponent>("FirstPersonCam");
	FirstPersonCam->SetupAttachment(RootComponent);

	GetMesh()->SetupAttachment(FirstPersonCam);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);

	ThirdPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ThirdPersonMesh");
	ThirdPersonMesh->SetupAttachment(RootComponent);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(ThirdPersonMesh);

	ThirdPersonCam = CreateDefaultSubobject<UCameraComponent>("ThirdPersonCam");
	ThirdPersonCam->SetupAttachment(CameraBoom);
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


