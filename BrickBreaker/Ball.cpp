#include "Ball.h"

#define LEFT 1;
#define MIDDLE 2;
#define RIGHT 3;

Ball::Ball(){}

Ball::Ball(int x , int y){}

Ball::Ball(int x , int y, Grid* g)
{
    xPos = x;
    yPos = y;
    grid = g;
    g->SetPixel(x,y,true);
}

Ball::Ball(int x , int y, Grid* g,Platform* p, Bricks* b)
{
    xPos = x;
    yPos = y;
    grid = g;
    platform = p;
    bricks = b;
    g->SetPixel(x,y,true);
    win = false;
    playing = false;
    lose = false;
}


void Ball::Move()
{
    grid->SetPixel(xPos,yPos,false);


    //Can i move to yPox + yDir 
    if(yPos + yDir < 3 )
    {
        //BRICK COLLISION TEST

        //IF HIT BRICK
        //BOUCNE DOWN 

        if(bricks->CheckBrick(xPos+ xDir,yPos+yDir))
        {
            if(bricks->DestroyBrick(xPos+ xDir ,yPos + yDir) == true)
            {
                win = true;
            }
            BounceDown();
        }

    }
    else if (yPos + yDir >6)
    {
        //PLATFORM COLLISION TEST
        //IF HIT PLATFORM
        //BOUNCE UP

        int hitPlatform = platform->HitPlatform(xPos,yPos+ yDir);
        if(hitPlatform != 0)
        {
            
            //left
            if(hitPlatform == 1)
            {
                BounceUp();
                if(xDir == 0)
                {
                    BounceLeft();
                }
            }
            //left edge
            else if (hitPlatform == 4)
            {
                 if(xDir == 1)
                 {
                     BounceUp();
                    BounceLeft();
                 }
                
            }
            //right
            else if (hitPlatform == 3)
            {
                BounceUp();
                if(xDir == 0)
                {
                    BounceRight();
                }
            }
            //Right edge
            else if (hitPlatform == 5)
            {
                if(xDir == -1)
                {
                    BounceUp();
                    BounceRight();
                }
            }
            //middle
            else if (hitPlatform == 2)
            {
                BounceUp();
                xDir = 0;
            }
        }
    }
    yPos += yDir;
    xPos += xDir;

    if(xPos < 1)
    {
        BounceRight();
    }
    if(xPos > 6)
    {
        BounceLeft();
    }

    if(yPos > 7)
    {
        yPos = 6;
        BounceUp();
        Serial.print("hit bottom of screen\n");
        lose = true;
    }
    if(yPos < 0 )
    {
        yPos = 1;
        BounceDown();
        Serial.print("hit top of screen\n");
    }

    //old collision
    /*
    if(yPos < 3)
    {
        if(bricks->CheckBrick(xPos,yPos))
        {
            bricks->DestroyBrick(xPos,yPos);
            yPos +=2;
            Serial.print("hit Brick\n");
            BounceDown();
        }
        //Check brick collision
        //inverse yDir
    }
    if(yPos > 6)
    {
        int hitPlatform = platform->HitPlatform(xPos,yPos);
        if(hitPlatform != 0)
        {
            Serial.print("hit Platform\n");
            yPos-= 2;
            BounceUp();
            if(hitPlatform == 1)
            {
                BounceLeft();
                if(xPos > 0)
                {
                    xPos --;
                }
                
            }
            else if (hitPlatform == 3)
            {
                if(xPos < 6)
                {
                xPos++;
                }
                BounceRight();
            }
            else
            {
                xDir = 0;
            }
        }
        //Check platform collision
        //check what side of the platform you hit 
    }

*/

    grid->SetPixel(xPos,yPos,true);
}

void Ball::Play()
{
    playing = true;
    yDir = -1;
}

void Ball::SetPosition(int x, int y)
{
    grid->SetPixel(xPos,yPos,false);
    xPos = x;
    yPos = y;
    grid->SetPixel(xPos,yPos,true);
}

void Ball::BounceRight()
{
    xDir = 1;
}

void Ball::BounceLeft()
{
    xDir = -1;
}

void Ball::BounceUp()
{
    yDir = -1;
}

void Ball::BounceDown()
{
    yDir = 1;
}