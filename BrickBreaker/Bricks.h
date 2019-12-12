#pragma once
#include "Grid.h"

class Bricks
{
public:
Bricks();
Bricks(Grid* g);

void ResetBricks();

bool CheckBrick(int x, int y);

bool DestroyBrick(int x , int y);

private:

Grid* grid;

bool bricks[8][8];

int brickCount;

void Clear();

};