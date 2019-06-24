/* Load Libraries */
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int eex, int eey)
{
	COORD coord;
	coord.X = eex;
	coord.Y = eey;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int x, y, lastx, lasty;


char a;

int main()
{
	x = 1; y = 1;
	lastx = x; lasty = y;

	while (1 == 1)
	{
		system("CLS");
		hidecursor();

		gotoxy(x, y);
		printf("O");

		a = _getch();
		lastx = x; lasty = y;
		if (a == 80) y = y + 1;
		if (a == 72) y = y - 1;
		if (a == 77) x = x + 1;
		if (a == 75) x = x - 1;

	}
	
	return 0;
}

