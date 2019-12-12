#include "Grid.h"
#include "Platform.h"
#include "Bricks.h"
#include "Ball.h"

const int outputA = 4;
const int outputB = 5;
const int buttonPin = 2;

int updateTime = 200;

int difficulty = 1;

int updateTimer = 0;

unsigned long currentTime;
unsigned long oldTime;

int buttonState = 0;

int counter = 0;
int currentState;
int previousState;

Grid grid;
Platform platform;
Bricks bricks;
Ball ball;

bool draw = true;

void setup()
{
    Serial.begin(9600);
    grid.Begin();
    platform = Platform(3,7,&grid);
    bricks = Bricks(&grid);
    ball = Ball(4,6,&grid,&platform,&bricks);
}

void Reset()
{
  grid.Clear();
  platform = Platform(3,7,&grid);
  bricks = Bricks(&grid);
  ball = Ball(3,6,&grid,&platform,&bricks);
}

void loop()
{
  ReadInput();
  oldTime = currentTime;
  currentTime = millis();
  int deltaTime = currentTime - oldTime;

  if(ball.Lose())
  {
    grid.LoseSequence();
    Reset();
    return;
  }

  if(ball.Win())
  {
    if(updateTime > 60)
    {
      difficulty++;
      updateTime -= 25;
    }
    grid.WinSequence();
    Reset();
    
    return;
  }
  if(ball.isPlaying())
  {
    if(updateTimer < updateTime)
    {
      updateTimer += deltaTime;
    }
    else
    {
      ball.Move();
      updateTimer = 0;
    }
    
  }

  grid.Draw();  
}

void ReadInput()
{
    currentState = digitalRead(outputA);

    if(currentState != previousState)
    {
        if(digitalRead(outputB) != currentState)
        {
            platform.MoveLeft();
        }
        else
        {
            platform.MoveRight();
        }    

        if(ball.isPlaying() == false)
        {
            ball.SetPosition(platform.GetX(),6);
        }
    }
    previousState = currentState;


  if(!ball.isPlaying())
  {
    buttonState = digitalRead(buttonPin);
    if(buttonState == LOW)
    {
        ball.Play();
    }
  }
}