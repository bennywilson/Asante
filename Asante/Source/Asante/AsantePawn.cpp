// Asante 2023


#include "AsantePawn.h"

// Sets default values
AAsantePawn::AAsantePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
//	Mesh3P->SetOnlyOwnerSee(true);
//	Mesh3P->SetupAttachment(FirstPersonCameraComponent);
	Mesh3P->bCastDynamicShadow = false;
	Mesh3P->CastShadow = false;
	//Mesh3P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
//	Mesh3P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
}

// Called when the game starts or when spawned
void AAsantePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsantePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAsantePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

