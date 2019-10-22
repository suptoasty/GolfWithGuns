// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Widget.h"
#include "GolfGameState.generated.h"

/**
 * Singleton class for managing player data between levels
 */
UCLASS()
class GOLFWITHGUNS_API UGolfGameState : public UGameInstance {
  GENERATED_BODY()

private:
  int level_stroke = 0;
  int total_strokes = 0;

  UPROPERTY(EditAnywhere, Category = "Golf Game State")
  UWidget *score_card = nullptr;

public:
  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  static UGolfGameState *GetInstance();

  virtual void Init() override;
  virtual void BeginDestroy() override;
  virtual void FinishDestroy() override;

  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  bool ShouldPersistData() const { return true; }

  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  void add_stroke() { level_stroke += 1; }
  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  void reset_strokes() { level_stroke = 0; }
  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  int get_level_strokes() const { return level_stroke; }
  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  void set_total_strokes(int value) { total_strokes = value; }
  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  int get_total_strokes() const { return total_strokes; }

  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  UWidget *get_score_card() const { return score_card; }
  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  void set_score_card(UWidget *object) { score_card = object; }

  UFUNCTION(BlueprintCallable, Category = "Golf Game State")
  void ClearData();
};
