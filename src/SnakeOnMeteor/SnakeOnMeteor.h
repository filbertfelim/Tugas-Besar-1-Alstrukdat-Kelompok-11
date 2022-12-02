#ifndef Snake_On_Meteor_H
#define Snake_On_Meteor_H

#include "../ADT/LinkedList/listdp.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include <time.h>
#include <stdlib.h>
#include "displayColor.h"

Point GenerateRandomPos();

int isInputValid(List Snake, char Movement, List Meteor);

void CreateSnake(List *Snake, Point StartingPoint);

void PrintGameSnake(List Snake, List Food, List Meteor, List Obstacles, int turn);

void SpawnObstacle(List *Obstacle, List Snake, int numberOfObstacles);

void IsObstacleHit(List Snake, List Obstacle, boolean *GameOver, int *loseFlag);

void SpawnMakanan(List Snake, List *Food, List Meteor, List Obstacles);

char ValidateMovementInput(char *Input, List Snake, List Meteor, int turn);

void MoveSnake(char Input, List *Snake, int *turn);

void HandlePosOverflow(List *Snake);

void AdjustBody(List *Snake);

void IsFoodHit(List *Snake, List *Food, boolean *GameOver, int *snakeLength, int *loseFlag);

void IsStuck(List Snake, List Meteor, boolean *isGameOver, int *loseFlag);

void SpawnMeteor(List *Meteor);

void IsMeteorHit(List *Snake, List Meteor, boolean *GameOver, boolean *hitbyMeteor, int *loseFlag);

void GameUpdate(List *Snake, List *Food, List *Meteor, List Obstacles, boolean *isGameOver, int *turn, int *snakeLength, int *loseFlag);

void SnakeOnMeteor(int *score);

#endif