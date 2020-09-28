// Fill out your copyright notice in the Description page of Project Settings.


#include "RubicCube.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ARubicCube::ARubicCube()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Side1.Init(NULL, 8);
	//Side2.Init(NULL, 8);
	//Side3.Init(NULL, 8);
	//Side4.Init(NULL, 8);
	//Side5.Init(NULL, 8);
	//Side6.Init(NULL, 8);

	CubeA = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("A"));
	CubeB = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("B"));
	CubeC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("C"));
	CubeD = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("D"));

	CubeE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("E"));
	CubeF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("F"));
	CubeABE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ABE"));
	CubeACE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ACE"));

	CubeABF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ABF"));
	CubeACF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ACF"));
	CubeDCE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DCE"));
	CubeDBE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DBE"));

	CubeDCF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DCF"));
	CubeDBF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DBF"));
	CubeAB = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AB"));
	CubeAC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AC"));

	CubeAE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AE"));
	CubeAF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AF"));
	CubeBD = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BD"));
	CubeBF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BF"));

	CubeBE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BE"));
	CubeCD = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CD"));
	CubeCE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CE"));
	CubeCF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CF"));

	CubeDE = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DE"));
	CubeDF = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DF"));

	RootComp1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Side1"));
	RootComp2 = CreateDefaultSubobject<UBoxComponent>(TEXT("Side2"));
	RootComp3 = CreateDefaultSubobject<UBoxComponent>(TEXT("Side3"));
	RootComp4 = CreateDefaultSubobject<UBoxComponent>(TEXT("Side4"));
	RootComp5 = CreateDefaultSubobject<UBoxComponent>(TEXT("Side5"));
	RootComp6 = CreateDefaultSubobject<UBoxComponent>(TEXT("Side6"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

	RootComponent = Root;

	CubeA->SetupAttachment(RootComponent);
	CubeB->SetupAttachment(RootComponent);
	CubeC->SetupAttachment(RootComponent);
	CubeD->SetupAttachment(RootComponent);
	CubeE->SetupAttachment(RootComponent);
	CubeF->SetupAttachment(RootComponent);
	
	RootComp1->SetupAttachment(RootComponent);
	RootComp2->SetupAttachment(RootComponent);
	RootComp3->SetupAttachment(RootComponent);
	RootComp4->SetupAttachment(RootComponent);
	RootComp5->SetupAttachment(RootComponent);
	RootComp6->SetupAttachment(RootComponent);

	CubeABE->SetupAttachment(RootComponent);
	CubeACE->SetupAttachment(RootComponent);

	CubeABF->SetupAttachment(RootComponent);
	CubeACF->SetupAttachment(RootComponent);
	CubeDCE->SetupAttachment(RootComponent);
	CubeDBE->SetupAttachment(RootComponent);

	CubeDCF->SetupAttachment(RootComponent);
	CubeDBF->SetupAttachment(RootComponent);
	CubeAB->SetupAttachment(RootComponent);
	CubeAC->SetupAttachment(RootComponent);

	CubeAE->SetupAttachment(RootComponent);
	CubeAF->SetupAttachment(RootComponent);
	CubeBD->SetupAttachment(RootComponent);
	CubeBF->SetupAttachment(RootComponent);

	CubeBE->SetupAttachment(RootComponent);
	CubeCD->SetupAttachment(RootComponent);
	CubeCE->SetupAttachment(RootComponent);
	CubeCF->SetupAttachment(RootComponent);

	CubeDE->SetupAttachment(RootComponent);
	CubeDF->SetupAttachment(RootComponent);

	//Camera->SetupAttachment(RootComponent);
	Side1.Add(CubeA);
	Side1.Add(CubeABE);
	Side1.Add(CubeABF);
	Side1.Add(CubeACE);
	Side1.Add(CubeACF);
	Side1.Add(CubeAE);
	Side1.Add(CubeAF);
	Side1.Add(CubeAB);
	Side1.Add(CubeAC);

	Side2.Add(CubeB);
	Side2.Add(CubeABE);
	Side2.Add(CubeABF);
	Side2.Add(CubeDBE);
	Side2.Add(CubeDBF);
	Side2.Add(CubeAB);
	Side2.Add(CubeBD);
	Side2.Add(CubeBE);
	Side2.Add(CubeBF);

	Side3.Add(CubeC);
	Side3.Add(CubeACE);
	Side3.Add(CubeDCE);
	Side3.Add(CubeACF);
	Side3.Add(CubeDCF);
	Side3.Add(CubeAC);
	Side3.Add(CubeCF);
	Side3.Add(CubeCE);
	Side3.Add(CubeCD);

	Side4.Add(CubeD);
	Side4.Add(CubeDCE);
	Side4.Add(CubeDCF);
	Side4.Add(CubeDBE);
	Side4.Add(CubeDBF);
	Side4.Add(CubeCD);
	Side4.Add(CubeBD);
	Side4.Add(CubeDE);
	Side4.Add(CubeDF);

	Side5.Add(CubeE);
	Side5.Add(CubeDCE);
	Side5.Add(CubeDBE);
	Side5.Add(CubeACE);
	Side5.Add(CubeABE);
	Side5.Add(CubeAE);
	Side5.Add(CubeBE);
	Side5.Add(CubeDE);
	Side5.Add(CubeCE);

	Side6.Add(CubeF);
	Side6.Add(CubeDCF);
	Side6.Add(CubeDBF);
	Side6.Add(CubeACF);
	Side6.Add(CubeABF);
	Side6.Add(CubeAF);
	Side6.Add(CubeBF);
	Side6.Add(CubeCF);
	Side6.Add(CubeDF);

	CameraBoom->TargetArmLength = 400;
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->SetupAttachment(RootComponent);
	Camera->SetupAttachment(CameraBoom);

	bRotateLeft = false;
	bRotateRight = false;
}

// Called when the game starts or when spawned
void ARubicCube::BeginPlay()
{
	Super::BeginPlay();
	RootComp1->OnComponentBeginOverlap.AddDynamic(this, &ARubicCube::OnOverlapBegin);
	RootComp2->OnComponentBeginOverlap.AddDynamic(this, &ARubicCube::OnOverlapBegin);
	RootComp3->OnComponentBeginOverlap.AddDynamic(this, &ARubicCube::OnOverlapBegin);
	RootComp4->OnComponentBeginOverlap.AddDynamic(this, &ARubicCube::OnOverlapBegin);
	RootComp5->OnComponentBeginOverlap.AddDynamic(this, &ARubicCube::OnOverlapBegin);
	RootComp6->OnComponentBeginOverlap.AddDynamic(this, &ARubicCube::OnOverlapBegin);

	RootComp1->OnComponentEndOverlap.AddDynamic(this, &ARubicCube::OnOverlapEnd);
	RootComp2->OnComponentEndOverlap.AddDynamic(this, &ARubicCube::OnOverlapEnd);
	RootComp3->OnComponentEndOverlap.AddDynamic(this, &ARubicCube::OnOverlapEnd);
	RootComp4->OnComponentEndOverlap.AddDynamic(this, &ARubicCube::OnOverlapEnd);
	RootComp5->OnComponentEndOverlap.AddDynamic(this, &ARubicCube::OnOverlapEnd);
	RootComp6->OnComponentEndOverlap.AddDynamic(this, &ARubicCube::OnOverlapEnd);
	
}

// Called every frame
void ARubicCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRotateLeft || bRotateRight)
		MakeRotation(CurrentSide, DeltaTime);
}

// Called to bind functionality to input
void ARubicCube::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ChooseSide1"), EInputEvent::IE_Pressed, this, &ARubicCube::AttachToRootCubeA);
	PlayerInputComponent->BindAction(TEXT("ChooseSide2"), EInputEvent::IE_Pressed, this, &ARubicCube::AttachToRootCubeB);
	PlayerInputComponent->BindAction(TEXT("ChooseSide3"), EInputEvent::IE_Pressed, this, &ARubicCube::AttachToRootCubeC);
	PlayerInputComponent->BindAction(TEXT("ChooseSide4"), EInputEvent::IE_Pressed, this, &ARubicCube::AttachToRootCubeD);
	PlayerInputComponent->BindAction(TEXT("ChooseSide5"), EInputEvent::IE_Pressed, this, &ARubicCube::AttachToRootCubeE);
	PlayerInputComponent->BindAction(TEXT("ChooseSide6"), EInputEvent::IE_Pressed, this, &ARubicCube::AttachToRootCubeF);

	PlayerInputComponent->BindAction(TEXT("Random"), EInputEvent::IE_Pressed, this, &ARubicCube::Random);

	PlayerInputComponent->BindAction(TEXT("RotateLeft"), EInputEvent::IE_Pressed, this, &ARubicCube::RotateLeft);
	PlayerInputComponent->BindAction(TEXT("RotateRight"), EInputEvent::IE_Pressed, this, &ARubicCube::RotateRight);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
}

void ARubicCube::RayCast(UStaticMeshComponent* SideRoot)
{
}

void ARubicCube::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UStaticMeshComponent* CubeToAdd;
	UE_LOG(LogTemp, Warning, TEXT("You Overlap"));

	if (Cast<UBoxComponent>(OverlappedComponent) == RootComp1) {
		if ((Cast<UStaticMeshComponent>(OtherComp) != CubeA) && OtherComp && OtherComp->GetClass()->IsChildOf(UStaticMeshComponent::StaticClass()))
		{
			CubeToAdd = Cast<UStaticMeshComponent>(OtherComp);
			Side1.Add(CubeToAdd);
		}
	}
	if (Cast<UBoxComponent>(OverlappedComponent) == RootComp2) {
		if ((Cast<UStaticMeshComponent>(OtherComp) != CubeB) && OtherComp && OtherComp->GetClass()->IsChildOf(UStaticMeshComponent::StaticClass()))
		{
			CubeToAdd = Cast<UStaticMeshComponent>(OtherComp);
			Side2.Add(CubeToAdd);
		}
	}
	if (Cast<UBoxComponent>(OverlappedComponent) == RootComp3) {
		if ((Cast<UStaticMeshComponent>(OtherComp) != CubeC) && OtherComp && OtherComp->GetClass()->IsChildOf(UStaticMeshComponent::StaticClass()))
		{
			CubeToAdd = Cast<UStaticMeshComponent>(OtherComp);
			Side3.Add(CubeToAdd);
		}
	}
	if (Cast<UBoxComponent>(OverlappedComponent) == RootComp4) {
		if ((Cast<UStaticMeshComponent>(OtherComp) != CubeD) && OtherComp && OtherComp->GetClass()->IsChildOf(UStaticMeshComponent::StaticClass()))
		{
			CubeToAdd = Cast<UStaticMeshComponent>(OtherComp);
			Side4.Add(CubeToAdd);
		}
	}
	if (Cast<UBoxComponent>(OverlappedComponent) == RootComp5) {
		if ((Cast<UStaticMeshComponent>(OtherComp) != CubeE) && OtherComp && OtherComp->GetClass()->IsChildOf(UStaticMeshComponent::StaticClass()))
		{
			CubeToAdd = Cast<UStaticMeshComponent>(OtherComp);
			Side5.Add(CubeToAdd);
		}
	}
	if (Cast<UBoxComponent>(OverlappedComponent) == RootComp6) {
		if ((Cast<UStaticMeshComponent>(OtherComp) != CubeF) && OtherComp && OtherComp->GetClass()->IsChildOf(UStaticMeshComponent::StaticClass()))
		{
			CubeToAdd = Cast<UStaticMeshComponent>(OtherComp);
			Side6.Add(CubeToAdd);
		}
	}
}

void ARubicCube::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UStaticMeshComponent* RemovedCube = Cast<UStaticMeshComponent>(OtherComp);
	if (RemovedCube) {
		if (Cast<UBoxComponent>(OverlappedComponent) == RootComp1) {
			Side1.RemoveSingle(RemovedCube);
		}
		if (Cast<UBoxComponent>(OverlappedComponent) == RootComp2) {
			Side2.RemoveSingle(RemovedCube);
		}
		if (Cast<UBoxComponent>(OverlappedComponent) == RootComp3) {
			Side3.RemoveSingle(RemovedCube);
		}
		if (Cast<UBoxComponent>(OverlappedComponent) == RootComp4) {
			Side4.RemoveSingle(RemovedCube);
		}
		if (Cast<UBoxComponent>(OverlappedComponent) == RootComp5) {
			Side5.RemoveSingle(RemovedCube);
		}
		if (Cast<UBoxComponent>(OverlappedComponent) == RootComp6) {
			Side6.RemoveSingle(RemovedCube);
		}
	}
}

void ARubicCube::AttachToRootCubeA()
{
	FAttachmentTransformRules Rules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	for (auto& c : Side1)
	{
		if (c != CubeA)
			c->AttachToComponent(CubeA, Rules);
	}
	CurrentSide = ECurrentSide::ECS_Side1;
}

void ARubicCube::AttachToRootCubeB()
{
	FAttachmentTransformRules Rules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	for (auto& c : Side2)
	{
		if (c != CubeB)
			c->AttachToComponent(CubeB, Rules);
	}
	CurrentSide = ECurrentSide::ECS_Side2;
}

void ARubicCube::AttachToRootCubeC()
{
	FAttachmentTransformRules Rules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	for (auto& c : Side3)
	{
		if (c != CubeC)
			c->AttachToComponent(CubeC, Rules);
	}
	CurrentSide = ECurrentSide::ECS_Side3;
}

void ARubicCube::AttachToRootCubeD()
{
	FAttachmentTransformRules Rules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	for (auto& c : Side4)
	{
		if (c != CubeD)
			c->AttachToComponent(CubeD, Rules);
	}
	CurrentSide = ECurrentSide::ECS_Side4;
}

void ARubicCube::AttachToRootCubeE()
{
	FAttachmentTransformRules Rules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	for (auto& c : Side5)
	{
		if (c != CubeE)
			c->AttachToComponent(CubeE, Rules);
	}
	CurrentSide = ECurrentSide::ECS_Side5;
}

void ARubicCube::AttachToRootCubeF()
{
	FAttachmentTransformRules Rules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	for (auto& c : Side6)
	{
		if (c != CubeF)
			c->AttachToComponent(CubeF, Rules);
	}
	CurrentSide = ECurrentSide::ECS_Side6;
}

void ARubicCube::RotateLeft()
{
	bRotateLeft = true;
	bRotateRight = false;
	if (CurrentSide == ECurrentSide::ECS_Side1) {
		MaxDegree = CubeA->GetRelativeRotation().Pitch + 90;
		UE_LOG(LogTemp, Warning, TEXT("Right Side1 %f"), MaxDegree);
	}
	if (CurrentSide == ECurrentSide::ECS_Side2) {
		MaxDegree = CubeB->GetComponentRotation().Yaw + 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side3) {
		MaxDegree = CubeC->GetComponentRotation().Pitch + 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side4) {
		MaxDegree = CubeD->GetComponentRotation().Pitch + 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side5) {
		MaxDegree = CubeE->GetComponentRotation().Yaw + 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side6) {
		MaxDegree = CubeF->GetComponentRotation().Yaw + 90;
	}
}

void ARubicCube::RotateRight()
{
	bRotateRight = true;
	bRotateLeft = false;
	if (CurrentSide == ECurrentSide::ECS_Side1) {
		MaxDegree = CubeA->GetComponentRotation().Pitch - 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side2) {
		MaxDegree = CubeB->GetComponentRotation().Pitch - 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side3) {
		MaxDegree = CubeC->GetComponentRotation().Pitch - 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side4) {
		MaxDegree = CubeD->GetComponentRotation().Pitch - 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side5) {
		MaxDegree = CubeE->GetComponentRotation().Yaw - 90;
	}
	if (CurrentSide == ECurrentSide::ECS_Side6) {
		MaxDegree = CubeF->GetComponentRotation().Yaw - 90;
	}
}

void ARubicCube::Random()
{
	RandomIterations1 = FMath::RandRange(3, 6);
	RandomIterations2 = FMath::RandRange(3, 6);
	RandomIterations3 = FMath::RandRange(3, 6);
	RandomIterations4 = FMath::RandRange(3, 6);
	RandomIterations5 = FMath::RandRange(3, 6);
	RandomIterations6 = FMath::RandRange(3, 6);
	bStartRandom = true;
	Start();
}

void ARubicCube::Start()
{
	int32 SideStart = FMath::RandRange(0, 5);

	switch (SideStart)
	{
	case 0:
	{
		if (RandomIterations1 != 0) {
			AttachToRootCubeA();
			RotateLeft();
			RandomIterations1--;
		}
	}
	break;
	case 1:
	{
		if (RandomIterations2 != 0) {
			AttachToRootCubeB();
			RotateRight();
			RandomIterations2--;
		}
	}
	break;
	case 2:
	{
		if (RandomIterations3 != 0) {
			AttachToRootCubeC();
			RotateLeft();
			RandomIterations3--;
		}
	}
	break;
	case 3:
	{
		if (RandomIterations4 != 0) {
			AttachToRootCubeD();
			RotateRight();
			RandomIterations4--;
		}
	}
	break;
	case 4:
	{
		if (RandomIterations5 != 0) {
			AttachToRootCubeE();
			RotateLeft();
			RandomIterations5--;
		}
	}
	break;
	case 5:
	{
		if (RandomIterations6 != 0) {
			AttachToRootCubeF();
			RotateRight();
			RandomIterations6--;
		}
	}
	break;
	default:
		break;
	}

	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ARubicCube::Start, 2);
}

void ARubicCube::MakeRotation(ECurrentSide Side, float dt)
{

	if (Side == ECurrentSide::ECS_Side1) {
		CubeCurrentRotation = CubeA->GetRelativeRotation().Pitch;
		if (bRotateLeft)
		{
			AddRotation = dt * -80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, -(MaxAngle - CurrentAngle) , 0.f);
				
				CubeA->AddLocalRotation(AdditinalRotation);
				bRotateLeft = false;
				CurrentAngle = 0.f;
				//UE_LOG(LogTemp, Warning, TEXT("Left Side1 %f"), CurrentAngle);
			}
			else if (bRotateLeft)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeA->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
		if (bRotateRight)
		{
			AddRotation = dt * 80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, +(MaxAngle - CurrentAngle), 0.f);
				CubeA->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateRight = false;
			}
			else if (bRotateRight)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeA->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
				//UE_LOG(LogTemp, Warning, TEXT("Right Side1 %f %f"), CubeA->GetComponentRotation().Pitch, NewRotation.Yaw);
			}

		}
	}

	if (Side == ECurrentSide::ECS_Side2) {
		CubeCurrentRotation = CubeB->GetRelativeRotation().Yaw;
		if (bRotateLeft)
		{
			AddRotation = dt * -80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, -(MaxAngle - CurrentAngle), 0.f);

				CubeB->AddLocalRotation(AdditinalRotation);
				bRotateLeft = false;
				CurrentAngle = 0.f;
				//UE_LOG(LogTemp, Warning, TEXT("Left Side1 %f"), CurrentAngle);
			}
			else if (bRotateLeft)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeB->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
		if (bRotateRight)
		{
			AddRotation = dt * 80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, +(MaxAngle - CurrentAngle), 0.f);
				CubeB->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateRight = false;
			}
			else if (bRotateRight)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeB->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
	}

	if (Side == ECurrentSide::ECS_Side3) {
		CubeCurrentRotation = CubeC->GetRelativeRotation().Yaw;
		if (bRotateLeft)
		{
			AddRotation = dt * -80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, -(MaxAngle - CurrentAngle), 0.f);
				CubeC->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateLeft = false;
			}
			else if (bRotateLeft)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeC->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
		if (bRotateRight)
		{
			AddRotation = dt * 80;


			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, +(MaxAngle - CurrentAngle), 0.f);
				CubeC->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateRight = false;
			}
			else if (bRotateRight)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeC->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
	}

	if (Side == ECurrentSide::ECS_Side4) {
		CubeCurrentRotation = CubeD->GetRelativeRotation().Yaw;
		if (bRotateLeft)
		{
			AddRotation = dt * 80;


			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, +(MaxAngle - CurrentAngle), 0.f);
				CubeD->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateLeft = false;
			}
			else if (bRotateLeft)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeD->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
		if (bRotateRight)
		{
			AddRotation = dt * -80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, -(MaxAngle - CurrentAngle), 0.f);
				CubeD->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateRight = false;
			}
			else if (bRotateRight)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeD->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
	}

	if (Side == ECurrentSide::ECS_Side5) {
		CubeCurrentRotation = CubeE->GetRelativeRotation().Yaw;
		if (bRotateLeft)
		{
			AddRotation = dt * +80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, +(MaxAngle - CurrentAngle), 0.f);
				CubeE->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateLeft = false;
			}
			else if (bRotateLeft)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeE->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
		if (bRotateRight)
		{
			AddRotation = dt * -80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, -(MaxAngle - CurrentAngle), 0.f);
				CubeE->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateRight = false;
			}
			else if (bRotateRight)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeE->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
	}

	if (Side == ECurrentSide::ECS_Side6) {
		CubeCurrentRotation = CubeF->GetRelativeRotation().Yaw;
		if (bRotateLeft)
		{
			AddRotation = dt * -80;
			UE_LOG(LogTemp, Warning, TEXT("Left Side1 %f"), CurrentAngle);
			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, -(MaxAngle - CurrentAngle), 0.f);
				CubeF->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateLeft = false;
			}
			else if (bRotateLeft)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeF->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
		if (bRotateRight)
		{
			AddRotation = dt * 80;

			if (FMath::IsNearlyEqual(CurrentAngle, MaxAngle, 1.5f)) {
				FRotator AdditinalRotation = FRotator(0.0f, +(MaxAngle - CurrentAngle), 0.f);
				CubeF->AddLocalRotation(AdditinalRotation);
				CurrentAngle = 0.f;
				bRotateRight = false;
			}
			else if (bRotateRight)
			{
				FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
				CubeF->AddLocalRotation(NewRotation);
				CurrentAngle += FMath::Abs(AddRotation);
			}

		}
	}
}

