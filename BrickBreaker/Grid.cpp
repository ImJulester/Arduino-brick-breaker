#include "Grid.h"

static const uint8_t PROGMEM
heart[] ={ B00000000,B01100110,B10011001,B10011001,B10000001,B01000010,B00100100,B00011000 },
number0[]  = {B00000000,B00111100,B01100110,B01101110,B01110110,B01100110,B01100110,B00111100},
number1[] = {B00000000,B00011000,B00011000,B00111000,B00011000,B00011000,B00011000,B01111110},
number2[]= {B00000000,B00111100,B01100110,B00000110,B00001100,B00110000,B01100000,B01111110},
number3[]= {B00000000,B00111100,B01100110,B00000110,B00011100,B00000110,B01100110,B00111100},
number4[]= {B00000000,B00001100,B00011100,B00101100,B01001100,B01111110,B00001100,B00001100},
number5[]= {B00000000,B01111110,B01100000,B01111100,B00000110,B00000110,B01100110,B00111100},
number6[]= {B00000000,B00111100,B01100110,B01100000,B01111100,B01100110,B01100110,B00111100},
number7[]= {B00000000,B01111110,B01100110,B00001100,B00001100,B00011000,B00011000,B00011000},
number8[]= {B00000000,B00111100,B01100110,B01100110,B00111100,B01100110,B01100110,B00111100},
number9[] = {B00000000,B00111100,B01100110,B01100110,B00111110,B00000110,B01100110,B00111100},
number10[] = {B00000000,B00100110,B11101001,B00101001,B00101001,B00101001,B00101001,B01110110},

//letters
A[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110},
W[] = {B00000000,B01100011,B01100011,B01100011,B01101011,B01111111,B01110111,B01100011},
I[] = {B00000000,B00111100,B00011000,B00011000,B00011000,B00011000,B00011000,B00111100},
N[] = { B00000000,B01100011,B01110011,B01111011,B01101111,B01100111,B01100011,B01100011},
E[] = {B00000000,B01111110,B01100000,B01100000,B01111100,B01100000,B01100000,B01111110},
R[] = { B00000000,B01111100,B01100110,B01100110,B01111100,B01111000,B01101100,B01100110},
D[] = { B00000000,B01111100,B01100110,B01100110,B01100110,B01100110,B01100110,B01111100},
F[] = {B00000000,B01111110,B01100000,B01100000,B01111100,B01100000,B01100000,B01100000},
C[] = {B00000000,B00111100,B01100110,B01100000,B01100000,B01100000,B01100110,B00111100},
U[] = {B00000000,B01100110,B01100110,B01100110,B01100110,B01100110,B01100110,B00111110},
L[] = {B00000000,B01100000,B01100000,B01100000,B01100000,B01100000,B01100000,B01111110},
T[] = {B00000000,B01111110,B01011010,B00011000,B00011000,B00011000,B00011000,B00011000},
Y[] = {B00000000,B01100110,B01100110,B01100110,B00111100,B00011000,B00011000,B00011000},
G[] = {B00000000,B00111100,B01100110,B01100000,B01100000,B01101110,B01100110,B00111100},
M[] = {B00000000,B01100011,B01110111,B01111111,B01101011,B01100011,B01100011,B01100011},
V[] = {B00000000,B01100110,B01100110,B01100110,B01100110,B01100110,B00111100,B00011000},
EMPTY[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000},
O[]= {B00000000,B00111100,B01100110,B01100110,B01100110,B01100110,B01100110,B00111100},
X[] = {B10000001,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B10000001};


 const uint8_t PROGMEM fireworks[][8]=
 {
    {B00000000,B00000000,B00100000,B00000000,B00000000,B00000000,B00000000,B00000000},
    {B00000000,B00100000,B01110000,B00100000,B00000000,B00000000,B00000000,B00000000},
    {B00100000,B01100000,B11011000,B00110000,B00100000,B00000000,B00000100,B00000000},
    {B10101000,B01110000,B11011100,B01110000,B10101000,B00100000,B00000100,B00000000},
    {B10101000,B00000000,B10001100,B00000000,B10001000,B00100100,B00001110,B00000100},
    { B00000000,B00000000,B00000000,B00000000,B00000100,B00000110,B00011011,B00001100},
    {B00000000,B00000000,B00000000,B00001100,B00010101,B00001110,B00111011,B00001110},
    {B00000000,B00000000,B00001000,B00011100,B00001001,B00000000,B00100000,B00001000},
    {B00000000,B00001000,B00011000,B00110110,B00001100,B00001000,B00000000,B00000000},
    {B00001000,B00101010,B00011100,B01110111,B00011100,B00101010,B00001000,B00000000},
    {B01001001,B00101010,B00010000,B11000011,B00000000,B00100010,B01001001,B00001000},
    {B01001001,B00000000,B00000000,B10000001,B00000000,B00000000,B01000001,B00001000}
 };

 const int FIREWORKS_LENGTH = sizeof(fireworks)/8;

const uint8_t PROGMEM upAnim[][8]= 
{
    {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011100},
    {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011100,B00011100},
    {B00000000,B00000000,B00000000,B00000000,B00000000,B00011100,B00011100,B00011100},
    {B00000000,B00000000,B00000000,B00000000,B01111111,B00011100,B00011100,B00011100},
    {B00000000,B00000000,B00000000,B00111110,B01111111,B00011100,B00011100,B00011100},
    {B00000000,B00000000,B00011100,B00111110,B01111111,B00011100,B00011100,B00011100},
    {B00000000,B00001000,B00011100,B00111110,B01111111,B00011100,B00011100,B00011100}
};
const int UPANIM_LENGTH = sizeof(upAnim) / 8;

const uint8_t PROGMEM HEARTBREAK[][8]= 
{
    {B00000000,B00100010,B01110111,B01111111,B01111111,B00111110,B00011100,B00001000},
    {B00000000,B00000001,B01000011,B11100111,B01110111,B00110110,B00001100,B00001000},
    { B00000000,B00000000,B10000001,B10000111,B11000011,B11100011,B01110100,B00001000},
    {B00000000,B00000000,B00000000,B00000000,B10000011,B10000001,B11100001,B01100010},
    {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10000001,B11100011}
};

const int HEARTBREAK_LENGTH = sizeof(HEARTBREAK)/8;

const uint8_t PROGMEM SMILETOSAD[][8]= 
{
    { B00000000,B00100100,B00100100,B00000000,B00000000,B01000010,B00111100,B00000000},
    {B00000000,B00100100,B00100100,B00000000,B00000000,B00000000,B00111100,B00000000},
    { B00000000,B00100100,B00100100,B01000000,B00000000,B00111100,B01000010,B00000000}
};
    const int SMILETOSAD_LENGTH = sizeof(SMILETOSAD) / 8;

Grid::Grid()
{
    matrix = Adafruit_8x8matrix();
}

void Grid::Begin()
{
     matrix.begin(0x70);
}
void Grid::SetPixel(int x, int y, bool lightOn)
{
    pixelGrid[x][y] = lightOn;
}


void Grid::Clear()
{
    for(int x= 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            pixelGrid[x][y] = false;
        }
    }
}

void Grid::Draw()
{
    matrix.clear();
    for(int x= 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            matrix.drawPixel(x,y,(int)pixelGrid[x][y]);
        }    
    }
    matrix.writeDisplay();
}


void Grid::WinSequence()
{
    for(int x = 0; x < 2; x++)
    {
        for(int i =0; i < FIREWORKS_LENGTH; i ++)
        {
         matrix.clear();
            matrix.drawBitmap(0, 0, fireworks[i], 8, 8, LED_ON);
            matrix.writeDisplay();
            delay(100);
        }
        matrix.setRotation(1);
    }

     matrix.setRotation(0);
     
    matrix.clear();
    matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
    matrix.writeDisplay();

    delay(timeBetweenText);

    matrix.clear();
    matrix.drawBitmap(0, 0, W, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
    matrix.clear();
    matrix.drawBitmap(0, 0, I, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
    matrix.clear();
    matrix.drawBitmap(0, 0, N, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
    matrix.clear();
    matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(50);
    matrix.clear();
    matrix.drawBitmap(0, 0, N, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
    matrix.clear();
    matrix.drawBitmap(0, 0, E, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
    matrix.clear();
    matrix.drawBitmap(0, 0, R, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
    matrix.clear();
    matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText * 2);


    matrix.clear();
    matrix.drawBitmap(0, 0, D, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, I, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0,F, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
    matrix.clear();
    matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(50);
     matrix.clear();
    matrix.drawBitmap(0, 0, F, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, I, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, C, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
 matrix.clear();
    matrix.drawBitmap(0, 0, U, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, L, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, T, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, Y, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);

    for(int i =0; i < UPANIM_LENGTH; i ++)
        {
            matrix.clear();
            matrix.drawBitmap(0, 0, upAnim[i], 8, 8, LED_ON);
            matrix.writeDisplay();
            delay(200);
        }
    delay(200);

}


void Grid::LoseSequence()
{
    matrix.clear();
    matrix.drawBitmap(0, 0, X, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);

    matrix.clear();
    matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);

    matrix.clear();
    matrix.drawBitmap(0, 0, X, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);

    matrix.clear();
    matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);

    for(int i =0; i < HEARTBREAK_LENGTH; i ++)
        {
            matrix.clear();
            matrix.drawBitmap(0, 0, HEARTBREAK[i], 8, 8, LED_ON);
            matrix.writeDisplay();
            delay(250);
        }
        matrix.clear();
        matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
        matrix.writeDisplay();

        delay(timeBetweenText);
    
     for(int i =0; i < SMILETOSAD_LENGTH; i ++)
        {
            matrix.clear();
            matrix.drawBitmap(0, 0, SMILETOSAD[i], 8, 8, LED_ON);
            matrix.writeDisplay();
            delay(400);
        }
        matrix.clear();
        matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
        matrix.writeDisplay();

     delay(200);
    matrix.clear();
    matrix.drawBitmap(0, 0, G, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, A, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, M, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, E, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, EMPTY, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, O, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, V, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, E, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(timeBetweenText);
     matrix.clear();
    matrix.drawBitmap(0, 0, R, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(500);
}
