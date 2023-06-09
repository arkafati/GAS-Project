// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class GASPROJECT_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;

	UPROPERTY()
		TObjectPtr<UAttributeSet> AttributeSet;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = true))
	class USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = true))
	class UCameraComponent* ThirdPersonCam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = true))
	class UCameraComponent* FirstPersonCam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh", meta = (AllowPrivateAccess = true))
	class USkeletalMeshComponent* ThirdPersonMesh;

public:	
	FORCEINLINE USpringArmComponent* GetCameraBoom() { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetThirdPersonCam() { return ThirdPersonCam; }
	FORCEINLINE UCameraComponent* GetFirstPersonCam() { return FirstPersonCam; }
	FORCEINLINE USkeletalMeshComponent* GetThirdPersonMesh() { return ThirdPersonMesh; }

};
