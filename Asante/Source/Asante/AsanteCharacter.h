// Asante 2023

#pragma once

#include "CoreMinimal.h"
#include "AsanteCharacterBase.h"
#include "GameFramework/Character.h"
#include "AsanteCharacter.generated.h"

UCLASS(Blueprintable)
class ASANTE_API AAsanteCharacter : public AAsanteCharacterBase
{
	GENERATED_BODY()

public:
	AAsanteCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
