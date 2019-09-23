#include "SinhTailor.h"

HWND getWindowHWND()
{
	HWND hwnd; //типо корень окна
	char Title[1024];
	GetConsoleTitle(Title, 1024); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна

	return hwnd;
}

HDC getContextForDrawing(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);    // Получаем контекст для рисования
	return hdc;
}

int getWorkingWidth(HWND hwnd)
{
	RECT rc;
	GetClientRect(hwnd, &rc); //Функция GetClientRect извлекает координаты рабочей области окна
	int width = rc.right;

	return width;
}

int getWorkingHeight(HWND hwnd)
{
	RECT rc;
	GetClientRect(hwnd, &rc); //Функция GetClientRect извлекает координаты рабочей области окна
	int height = rc.bottom;

	return height;
}

HPEN createPen(COLORS color)
{
	HPEN pen;

	if (color == RED) {
		pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	}
	else if (color == GREEN) {
		pen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	}
	else if (color == BLUE) {
		pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	}
	else {
		pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	}

	return pen;
}

void releaseContext(HWND hwnd, HDC hdc)
{
	ReleaseDC(hwnd, hdc);    // Освобождаем контекст рисования
}

void deletePen(HPEN pen)
{
	DeleteObject(pen);
}

float degreesToRadians(float degree)
{
	float result = degree * (PI / 180);
	return result;
}

void drawDot(COLORS color, int x, int y, HDC hdc)
{	

	if (color == RED) {
		SetPixel(hdc, x, y, RGB(255, 0, 0));
	}
	else if (color == GREEN) {
		SetPixel(hdc, x, y, RGB(0, 255, 0));
	}
	else if (color == BLUE) {
		SetPixel(hdc, x, y, RGB(0, 0, 255));
	}
	else {
		SetPixel(hdc, x, y, RGB(255, 255, 255));
	}
}

void drawCenter(int xOffset,int yOffset)
{
	HWND hwnd = getWindowHWND();
	HDC hdc = getContextForDrawing(hwnd);

	int width = getWorkingWidth(hwnd);
	int height = getWorkingHeight(hwnd);

	HPEN pen1 = createPen(WHITE);
	HPEN pen2 = createPen(WHITE);


	pen1 = (HPEN)SelectObject(hdc, pen2);

	MoveToEx(hdc, width/2 + xOffset, 0, NULL);  //рисую вертикальную линию
	LineTo(hdc, width / 2 + xOffset, height);

	MoveToEx(hdc, 0, height/2 + yOffset, NULL);  //рисую горизонтальную линию
	LineTo(hdc, width, height/2 + yOffset);


	SelectObject(hdc, pen1);
	releaseContext(hwnd, hdc);
	DeleteObject(pen2);
}

void drawSin()
{

	HWND hwnd = getWindowHWND();
	HDC hdc = getContextForDrawing(hwnd);

	int width = getWorkingWidth(hwnd);
	int height = getWorkingHeight(hwnd);

	HPEN pen1 = createPen(BLUE);
	HPEN pen2 = createPen(BLUE);

	int xOffset = PI * 100;
	int yOffset = 200;

	int coef = -100;

	drawCenter((-1 * width / 2) + (PI * coef * -1), (-1 * height / 2) + coef * 1 + 300);

	pen1 = (HPEN)SelectObject(hdc, pen2);

	
	//DRAW HERE
	float x = -1 * PI;
	float y = sin(x);

	MoveToEx(hdc, (x * coef) + xOffset, (y * coef) + yOffset, NULL);

	do
	{
		LineTo(hdc, (x * coef) + xOffset, (y  * coef) + yOffset);

		x += 0.01f;
		y = sin(x);
		
		MoveToEx(hdc, (x * coef) + xOffset, (y * coef) + yOffset, NULL);


	} while (x <= PI);
	

	SelectObject(hdc, pen1);
	releaseContext(hwnd,hdc);
	DeleteObject(pen2);       
	_getch();
}

void drawCos()
{

	HWND hwnd = getWindowHWND();
	HDC hdc = getContextForDrawing(hwnd);

	int width = getWorkingWidth(hwnd);
	int height = getWorkingHeight(hwnd);

	HPEN pen1 = createPen(RED);
	HPEN pen2 = createPen(RED);

	int xOffset = PI * 100;
	int yOffset = 200;

	int coef = -100;

	drawCenter((-1 * width / 2) + (PI * coef * -1), (-1 * height / 2) + coef * 1 + 300);

	pen1 = (HPEN)SelectObject(hdc, pen2);


	//DRAW HERE
	float x = -1.5f * PI;
	float y = cos(x);

	MoveToEx(hdc, (x * coef) + xOffset, (y * coef) + yOffset, NULL);

	do
	{
		LineTo(hdc, (x * coef) + xOffset, (y  * coef) + yOffset);

		x += 0.01f;
		y = cos(x);

		MoveToEx(hdc, (x * coef) + xOffset, (y * coef) + yOffset, NULL);


	} while (x <= PI);


	SelectObject(hdc, pen1);
	releaseContext(hwnd, hdc);
	DeleteObject(pen2);
	_getch();

}

void drawSinHLib()
{
	HWND hwnd = getWindowHWND();
	HDC hdc = getContextForDrawing(hwnd);

	int width = getWorkingWidth(hwnd);
	int height = getWorkingHeight(hwnd);

	HPEN pen1 = createPen(RED);
	HPEN pen2 = createPen(RED);

	int xOffset = PI * 100;
	int yOffset = 200;

	int coef = -100;

	drawCenter((-1 * width / 2) + (PI * coef * -1), (-1 * height / 2) + coef * 1 + 300);

	pen1 = (HPEN)SelectObject(hdc, pen2);


	//DRAW HERE
	float x = -1.5f * PI;
	float y = sinh(x);

	MoveToEx(hdc, (x * coef) + xOffset, (y * coef * -1) + yOffset, NULL);

	do
	{
		LineTo(hdc, (x * coef) + xOffset, (y  * coef * -1) + yOffset);

		x += 0.01f;
		y = sinh(x);

		MoveToEx(hdc, (x * coef) + xOffset, (y * coef * -1) + yOffset, NULL);


	} while (x <= PI);


	SelectObject(hdc, pen1);
	releaseContext(hwnd, hdc);
	DeleteObject(pen2);
	_getch();
}

void drawSinHTailor()
{
	HWND hwnd = getWindowHWND();
	HDC hdc = getContextForDrawing(hwnd);

	int width = getWorkingWidth(hwnd);
	int height = getWorkingHeight(hwnd);

	HPEN pen1 = createPen(GREEN);
	HPEN pen2 = createPen(GREEN);

	int xOffset = PI * 100;
	int yOffset = 200;

	int coef = -100;

	drawCenter((-1 * width / 2) + (PI * coef * -1), (-1 * height / 2) + coef * 1 + 300);

	pen1 = (HPEN)SelectObject(hdc, pen2);


	//DRAW HERE
	float x = -1 * PI;
	float y = sinhHTailor(x,3);

	MoveToEx(hdc, (x * coef) + xOffset, (y * coef * -1) + yOffset, NULL);

	do
	{
		LineTo(hdc, (x * coef) + xOffset, (y  * coef * -1) + yOffset);

		x += 0.01f;
		y = sinhHTailor(x,3);

		MoveToEx(hdc, (x * coef) + xOffset, (y * coef * -1) + yOffset, NULL);


	} while (x <= PI);


	SelectObject(hdc, pen1);
	releaseContext(hwnd, hdc);
	DeleteObject(pen2);
	_getch();
}

float sinhHTailor(float arg, int accuracy)
{
	float res = 0;
	float resTemp = 0;

	float temp1, temp2 = 0;

	for (int i = 0; i < accuracy; i++)
	{
		temp1 = numToPositivePower(arg,(2 * i) + 1);
		temp2 = factorial((2 * i) + 1);
		resTemp = temp1 / temp2;
		res += resTemp;
	}


	return res;
}

int factorial(int num)
{
	if (num < 1) {
		return -1;
	}

	int result = 1;

	for (int i = 1; i <= num; i++)
	{
		result *= i;
	}

	return result;
}

float numToPositivePower(float num, int power)
{
	if (power < 0) {
		return -1;
	}
	else if (power == 0) {
		return 1;
	}

	float res = num;
	
	for (int i = 0; i < power - 1; i++)
	{
		res *= num;
	}

	return res;
}

void simpleCompare(float degree, int accuracy) {
	float yLib = sinh(degreesToRadians(degree));
	float yTailor = sinhHTailor(degreesToRadians(degree), accuracy);

	std::cout << "Math.h sinh = " << yLib << "\n" << "Tailor sin = " << yTailor << "\n";
}