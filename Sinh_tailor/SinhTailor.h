#pragma once

#include <math.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <iostream>

#define PI 3.1415

enum COLORS {RED,GREEN,BLUE, WHITE};

HWND getWindowHWND();//HWND корень окон
HDC getContextForDrawing(HWND hwnd); //получить контекст для рисования

int getWorkingWidth(HWND hwnd);
int getWorkingHeight(HWND hwnd);

HPEN createPen(COLORS color); //создать перо


void releaseContext(HWND hwnd, HDC hdc);
void deletePen(HPEN pen);

float degreesToRadians(float degree);

void drawDot(COLORS color, int x, int y, HDC hdc);

void drawCenter(int xOffset, int yOffset);

void drawSin();
void drawCos();

void drawSinHLib();
void drawSinHTailor();

float sinhHTailor(float arg, int accuracy);

int factorial(int num);
float numToPositivePower(float num, int power);
 
void simpleCompare(float degree, int accuracy);