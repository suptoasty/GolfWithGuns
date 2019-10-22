// Fill out your copyright notice in the Description page of Project Settings.

#include "GolfGameState.h"

static UGolfGameState *Instance = nullptr;

UGolfGameState *UGolfGameState::GetInstance() { return Instance; }

void UGolfGameState::Init() {
  Super::Init();
  Instance = this;
  AddToRoot();
}

void UGolfGameState::BeginDestroy() {
  ClearData();
  Super::BeginDestroy();
}

void UGolfGameState::FinishDestroy() { Super::FinishDestroy(); }

void UGolfGameState::ClearData() { level_stroke = 0; total_strokes = 0; }