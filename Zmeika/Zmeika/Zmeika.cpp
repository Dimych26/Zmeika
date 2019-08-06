#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include <windows.h>

using namespace std;
bool gameOver;
const int Weight = 20,
Height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, RIGHT, LEFT, UP, DOWN };
Direction dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = Weight / 2;
	y = Height / 2;
	fruitX = rand() % Weight;
	fruitY = rand() % Height;
	score = 0;
}
void Draw() {

	system("cls");//очистка
	for (int i = 0; i < Weight + 1; i++)

		cout << "#";
	cout << endl;



	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Weight; j++) {
			if (j == 0 || j == Weight - 1)

				cout << "#";

			if (i == y && j == x)
			{
				cout << "0";

			}
			else if (i == fruitY && j == fruitX)
				cout << "f";
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{

					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
						cout << "o";
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;

	}
	for (int i = 0; i<Weight + 1; i++)

		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}
void Input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT; break;
		case'd':
			dir = RIGHT; break;
		case's':
			dir = DOWN; break;
		case'w':
			dir = UP; break;
		case'x':
			gameOver = true; break;
		}
	}

}
void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	/*if (dir == RIGHT)
	{

	switch (dir)
	{
	case RIGHT:
	x++;
	break;
	case UP:
	y--;
	break;


	case DOWN:
	y++;
	break;
	}
	}
	else if (dir == LEFT)

	{

	switch (dir)
	{
	case UP:
	y--;
	break;
	case LEFT:
	x--;
	break;
	case DOWN:
	y++;
	break;
	}
	}
	else if (dir == UP)

	{

	switch (dir)
	{
	case RIGHT:
	x++;
	break;
	case UP:
	y--;
	break;
	case LEFT:
	x--;
	break;
	}
	}
	else
	{
	*/
	switch (_getch())
	{
	case's':
	dir = DOWN; break;
	case'a':
	dir = LEFT; break;
	case'd':
	dir = RIGHT; break;
	case'w':
		dir = UP; break;
	case'x':
	gameOver = true; break;
	}
	
	switch (dir)
	{
	case RIGHT:
		x++;
		Sleep(10);
		break;
	case UP:
		y--;
		Sleep(10);
		break;
	case LEFT:
		x--;
		Sleep(10);
		break;
	case DOWN:
		y++;
		Sleep(10);
		break;
	}

	/*if (x > Weight-1 || x < 0 || y > Height || y < 0)
	{
	gameOver = true;

	}*/
	if (x >= Weight - 1)
	{
		x = 0;
	}
	else if (x < 0)
	{
		x = Weight - 2;
	}
	if (y >= Height)
	{
		y = 0;
	}
	else if (y < 0)
	{
		y = Height - 1;
	}
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x &&tailY[i] == y)
		{
			gameOver = true;

		}
		if (fruitX == tailX[i] && fruitY == tailY[i])
		{
			fruitX = rand() % Weight;
			fruitY = rand() % Height;
		}
	}
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % Weight;
		fruitY = rand() % Height;
		nTail++;
	}
	
}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}

	return 0;
}