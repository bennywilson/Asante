// Asante 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AsanteCharacter.generated.h"

UCLASS()
class ASANTE_API AAsanteCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AAsanteCharacter();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	USkeletalMeshComponent* Mesh3P;
};
