#include "Bricks.h"


Bricks::Bricks()
{

}


Bricks::Bricks(Grid* g)
{
    grid = g;
    ResetBricks();
}

void Bricks::Clear()
{
    for(int x= 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            bricks[x][y] = false;
        }
    }
}

void Bricks::ResetBricks()
{
    Clear();
    brickCount = 0;
    for(int x = 3; x < 4; x ++)
    {
        for(int y= 0; y < 3; y++)
        {
            bricks[x][y] = true;
            grid->SetPixel(x,y,true);
            brickCount++;
        }
    }    
}

bool Bricks::DestroyBrick(int x , int y)
{
    bricks[x][y] = false;
    grid->SetPixel(x,y,false);
    brickCount--;
    Serial.print("\n bricks alive\t");
    Serial.print(brickCount);
    if(brickCount <= 0)
    {
        return true;
    }
    return false;
}

bool Bricks::CheckBrick(int x , int y)
{
    return bricks[x][y];
}