#ifndef Snake_On_Meteor_H
#define Snake_On_Meteor_H

#include "listdp.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include <time.h>
#include <stdlib.h>

Point GenerateRandomPos();

boolean isInputValid(List Snake, char Movement);

void CreateSnake(List *Snake, Point StartingPoint);

void PrintGame(List Snake, List Food);

void SpawnMakanan(List Snake, List *Food);

void ValidateMovementInput(char *Input, int *turn);

void MoveSnake(char Input, List *Snake);

void AdjustBody(List *Snake);

void IsFoodHit(List *Snake, List Food, boolean *GameOver);

void RemoveSnakePart(List *Snake);

void SnakeOnMeteor();

#endif