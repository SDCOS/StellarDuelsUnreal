// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu_Pawn.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AMenu_Pawn::AMenu_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(TEXT("/Game/MultiplayerMenu/WB_MainMenu.WB_MainMenu_C"));
    if (WidgetClassFinder.Succeeded())
    {
        MyWidgetClass = WidgetClassFinder.Class;
        UE_LOG(LogTemp, Warning, TEXT("found widget class"));
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("couldn't find the widget class"));
    }

}

// Called when the game starts or when spawned
void AMenu_Pawn::BeginPlay()
{
	Super::BeginPlay();
    if (UUserWidget* MyWidget = CreateWidget<UUserWidget>(GetWorld(), MyWidgetClass))
    {
        // Add it to the viewport
        MyWidget->AddToViewport();

        // Optional: Set input mode for UI interaction
        APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
        if (PlayerController)
        {
            FInputModeUIOnly InputMode;
            InputMode.SetWidgetToFocus(MyWidget->TakeWidget());
            PlayerController->SetInputMode(InputMode);
            PlayerController->bShowMouseCursor = true;
        }
    }
	
}

// Called every frame
void AMenu_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMenu_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


