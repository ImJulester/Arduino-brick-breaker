#pragma once
#include "Grid.h"

class Platform
{
public:

Platform();
Platform(int x , int y);
Platform(int x , int y , Grid* g);

int GetX(){return xPos;}
int GetY(){return yPos;}

void SetX(int value){xPos = value;}
//void SetY(int value){yPos = value;}

void MoveLeft();
void MoveRight();

int HitPlatform(int x , int y);

private:

float xPos;
float yPos;

Grid* grid;

bool moveLeftDown = false;
bool moveRightDown = false;

//int width;

};