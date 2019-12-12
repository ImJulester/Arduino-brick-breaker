#pragma once
#include "Grid.h"
#include "Bricks.h"
#include "Platform.h"

class Ball
{
    public:

    Ball();
    Ball(int x , int y);
    Ball(int x , int y,Grid* g);
    Ball(int x , int y,Grid* g,Platform* p,Bricks* b);
    void Move();

    void Play();

    void SetPosition(int x, int y);
    bool isPlaying(){return playing;}
    bool Win(){return win;}
    bool Lose(){return lose;}
    private:

    void BounceRight();
    void BounceLeft();
    void BounceUp();
    void BounceDown();


    int xPos;
    int yPos;
    int xDir;
    int yDir;
    
    Grid* grid;
    Platform* platform;
    Bricks* bricks;

    bool playing;
    bool win;
    bool lose;
};