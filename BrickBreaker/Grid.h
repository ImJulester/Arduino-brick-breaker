#pragma once
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"


class Grid
{

public:

Grid();

void SetPixel(int x, int y, bool lightOn);

void Clear();

void Draw();

void Begin();

void WinSequence();
void LoseSequence();
private:

bool pixelGrid [8][8];
Adafruit_8x8matrix matrix;
int timeBetweenText = 200;
};