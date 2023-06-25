// Asante 2023


#include "AsanteCharacter.h"

AAsanteCharacter::AAsanteCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Health = HealthMax = 100.f;
}

// Called when the game starts or when spawned
void AAsanteCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsanteCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAsanteCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

