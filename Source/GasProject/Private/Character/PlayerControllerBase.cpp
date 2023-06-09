// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerControllerBase.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

APlayerControllerBase::APlayerControllerBase()
{
	bReplicates = true;

}

void APlayerControllerBase::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}

void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
	check(DefaultContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(DefaultContext, 0);
	
}

void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Look);

}

void APlayerControllerBase::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
	
}

void APlayerControllerBase::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisValue = InputActionValue.Get<FVector2D>();

	AddYawInput(LookAxisValue.X);
	AddPitchInput(LookAxisValue.Y);
}