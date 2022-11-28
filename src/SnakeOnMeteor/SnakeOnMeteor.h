#ifndef Snake_On_Meteor_H
#define Snake_On_Meteor_H

#include "listdp.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include <time.h>
#include <stdlib.h>

Point GenerateRandomPos();

int isInputValid(List Snake, char Movement, List Meteor);

void CreateSnake(List *Snake, Point StartingPoint);

void PrintGame(List Snake, List Food, List Meteor, int turn);

void SpawnMakanan(List Snake, List *Food, List Meteor);

char ValidateMovementInput(char *Input, List Snake, List Meteor);

void MoveSnake(char Input, List *Snake, int *turn);

void HandlePosOverflow(List *Snake);

void AdjustBody(List *Snake);

void IsFoodHit(List *Snake, List *Food, boolean *GameOver, int *snakeLength, int *loseFlag);

void SpawnMeteor(List *Meteor);

void IsMeteorHit(List *Snake, List Meteor, boolean *GameOver, boolean *hitbyMeteor, int *loseFlag);

void GameUpdate(List *Snake, List *Food, List *Meteor, boolean *isGameOver, int *turn, int *snakeLength, int *loseFlag);

void SnakeOnMeteor();

#endif