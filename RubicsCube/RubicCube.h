// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RubicCube.generated.h"

enum class ECurrentSide : uint8
{
	ECS_Side1 UMETA(DisplayName = "Side1"),
	ECS_Side2 UMETA(DisplayName = "Side2"),
	ECS_Side3 UMETA(DisplayName = "Side3"),
	ECS_Side4 UMETA(DisplayName = "Side4"),
	ECS_Side5 UMETA(DisplayName = "Side5"),
	ECS_Side6 UMETA(DisplayName = "Side6")
};

UCLASS()
class RUBICSCUBE_API ARubicCube : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARubicCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeA;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeB;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeC;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeD;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeF;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeABE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeACE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeABF;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeACF;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeDCE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeDBE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeDCF;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeDBF;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeAB;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeAC;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeAE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeAF;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeBD;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeBF;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeBE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeCD;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeCE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeCF;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeDE;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cubes")
	class UStaticMeshComponent* CubeDF;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Root")
	class USphereComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sides")
	class UBoxComponent* RootComp1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sides")
	class UBoxComponent* RootComp2;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sides")
	class UBoxComponent* RootComp3;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sides")
	class UBoxComponent* RootComp4;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sides")
	class UBoxComponent* RootComp5;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sides")
	class UBoxComponent* RootComp6;

	TArray<UStaticMeshComponent*> Side1;
	TArray<UStaticMeshComponent*> Side2;
	TArray<UStaticMeshComponent*> Side3;
	TArray<UStaticMeshComponent*> Side4;
	TArray<UStaticMeshComponent*> Side5;
	TArray<UStaticMeshComponent*> Side6;

	void RayCast(class UStaticMeshComponent* SideRoot);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* Camera;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void AttachToRootCubeA();
	void AttachToRootCubeB();
	void AttachToRootCubeC();
	void AttachToRootCubeD();
	void AttachToRootCubeE();
	void AttachToRootCubeF();

	void RotateLeft();
	void RotateRight();

	void Random();

	void Start();

	bool bStartRandom = false;

	int32 RandomIterations1 = 0;
	int32 RandomIterations2 = 0;
	int32 RandomIterations3 = 0;
	int32 RandomIterations4 = 0;
	int32 RandomIterations5 = 0;
	int32 RandomIterations6 = 0;

	ECurrentSide CurrentSide;

	void MakeRotation(ECurrentSide Side, float dt);

	bool bRotateLeft;
	bool bRotateRight;
	float CubeCurrentRotation = 0.f;
	float MaxDegree = 0.f;
	float AddRotation = 0.f;
	float MaxAngle = 90.f;
	float CurrentAngle = 0.0f;

	FTimerHandle Timer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class USpringArmComponent* CameraBoom;
};
