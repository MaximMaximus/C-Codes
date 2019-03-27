// simple loop geometry

#include <stdio.h>
#include <math.h>

int drawRectangle()
{
	int size = 4;
	int i;
	int j;

	for(i=0; i<=size; i++)
	{
		for(j=0; j<=size; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

int drawtriangle()
{
	int size = 4;
	int i;
	int j;

	for(i=0; i<=size; i++)
	{
		for(j=0; j<=size-i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

int drawtriangledown()
{
	int size = 4;
	int i;
	int j;

	for(i=0; i<=size; i++)
	{
		for(j=0; j<=i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

int sidewaystriangle()
{
	int size = 7;
	int high = 4;

	int i;
	int j;

	for(i=1; i <= size; i++)
	{
		for(j=1; j <= high - abs(high - i); j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

int main()
{
	drawRectangle();
	drawtriangle();
	drawtriangledown();
	sidewaystriangle();

	return 0;
}
