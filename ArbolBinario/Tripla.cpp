#include "Tripla.h"

void moverAbajo(int x, int y)
{
	x = x + 1;
}

void moverDerecha(int x, int y)
{
	y = y + 1;
}

void moverFlechaIzquierda(int matriz[5][5], int x, int y)
{
	while (x != 1 || y != 5)
	{
		x = x + 1;
		y = y - 1;
		cout << matriz[x][y] << endl;
	}
	
}

void moverFlechaDerecha(int matriz[5][5], int x, int y)
{
	
	while (x != 1)
	{
		x = x - 1;
		y = y + 1;
		cout << matriz[x][y] << endl;
	}
}

void funcionCompleta()
{
	int matriz[5][5];
	int i = 1, j = 1;
	while (i <= 5 && j <= 5)
	{
		cout << matriz[i][j]<<endl;
		moverAbajo(i,j);
		cout << matriz[i][j] << endl;
		moverFlechaDerecha(matriz,i,j);
		moverDerecha(i, j);
		cout << matriz[i][j] << endl;
		moverFlechaIzquierda(matriz, i, j);
	}
}
