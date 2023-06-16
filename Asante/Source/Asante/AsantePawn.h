// Asante 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AsantePawn.generated.h"

UCLASS()
class ASANTE_API AAsantePawn : public APawn
{
	GENERATED_BODY()

public:

	AAsantePawn();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	USkeletalMeshComponent* Mesh3P;
};
