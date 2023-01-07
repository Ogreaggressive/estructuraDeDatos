#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#define TAM 28

using namespace std;

class nodo
{
private:
	bool existe;
	nodo* vec[TAM];
public:
	nodo();
	~nodo();
	void insertar(vector<char> palabra, nodo* raiz);
	bool buscar(vector<char> palabra, nodo* raiz);
	void mostrar(vector<char> palabra, nodo* raiz);
};

nodo::nodo()
{
	existe = false;
	for (int i = 0; i < TAM; i++)
	{
		vec[i] = NULL;
	}
}

nodo::~nodo()
{
}

void nodo::insertar(vector<char> palabra, nodo* raiz)
{
	nodo* caminante = raiz;
	int i = 0, pos =0;
	for (int j = 0; j < palabra.size(); j++)
	{
		pos = int(palabra[i]) - 97; //funcion que saca la posicion
		if (caminante->vec[pos] == NULL) //sino existe
		{
			caminante->vec[pos] = new nodo();
		}
		caminante = caminante->vec[pos];
		i++;
	}
	caminante->existe = true; //indica que la palabra existe
}

bool nodo::buscar(vector<char> palabra, nodo* raiz)
{
	nodo* caminante = raiz;
	int pos = 0;
	bool res = false;
	for (int i = 0; i < palabra.size(); i++)
	{
		pos = int(palabra[i]) - 97;
		if (caminante->vec[pos] != NULL)
		{
			caminante = caminante->vec[pos];
			if (caminante->existe == true)
			{
				res = true;
			}	
		}
	}
	return res;
}

void nodo::mostrar(vector<char> palabra, nodo* raiz)
{
	nodo* caminante = raiz;
	int pos = 0;
	for (int i = 0; i < palabra.size(); i++)
	{
		pos = int(palabra[i]) - 97;
		if (caminante->vec[pos] != NULL)
		{
			caminante = caminante->vec[pos];
			cout << palabra[i];
		}
	}
	cout << endl;
}



