#include "Platform.h"

#define LEFT 1;
#define MIDDLE 2;
#define RIGHT 3;
#define LEFTEDGE 4;
#define RIGHTEDGE 5;

Platform::Platform(){}

Platform::Platform(int x, int y)
{
    xPos = x;
    yPos = y;
}

Platform::Platform(int x, int y, Grid* g)
{
    xPos = x;
    yPos = y;
    grid =g;
    grid->SetPixel(x-1 ,y,true);
    grid->SetPixel(x ,y,true);
   grid->SetPixel(x+1 ,y,true);  
}

void Platform::MoveLeft()
{
    if(moveLeftDown == false)
    {
    if(xPos > 1)
    {
        grid->SetPixel(xPos +1,yPos,false);
        xPos--;
        grid->SetPixel(xPos -1,yPos,true);
    }
        moveLeftDown = true;
    }
    else
    {
        moveLeftDown = false;
    }

    
}



void Platform::MoveRight()
{
    if(moveRightDown == false)
    {
    if(xPos < 6)
    {
        grid->SetPixel(xPos -1,yPos,false);
        xPos++;
        grid->SetPixel(xPos +1,yPos,true);
    }
    moveRightDown = true;
    }
    else
    {
        moveRightDown = false;
    }

    
}

int Platform::HitPlatform(int x , int y)
{
    if(y == yPos)
    {
        if(x == xPos -1)
        {
            return LEFT;
        }
        if(x == xPos -2)
        {
            return LEFTEDGE;
        }
        if(x == xPos)
        {
            return MIDDLE;
        }
        if(x == xPos +1)
        {
            return RIGHT;
        }
        if(x == xPos +2)
        {
            return RIGHTEDGE;
        }
    }
    return 0;
}