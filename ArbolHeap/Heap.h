#pragma once

#include "Nodo.h"
#include <fstream>
#define TAM 17000

template<class T>
class Heap
{
private:
	Nodo<T> vec[TAM];
	int ultimaHoja;
public:
	Heap();
	~Heap();

	//T operator[](int i);

	void insertar(T elem);
	void recuperarAbajo_Arriba(int i);

	T eliminarMayor();
	void recuperarArriba_Abajo(int i);

	void recorrerHeap();
	T getMayor();
	T getMenor();

	int getTam();
};

template<class T>
Heap<T>::Heap()
{
	/*for (int i = 0; i < TAM; i++)
	{
		vec[i] = new Nodo;
	}*/
	ultimaHoja = NULL;
}

template<class T>
Heap<T>::~Heap()
{

}
/*
template<class T>
T Heap<T>::operator[](int i)
{
	return vec[i];
}*/

template<class T>
void Heap<T>::recuperarArriba_Abajo(int i)
{
	int mayor;
	if (i * 2 + 1 <= ultimaHoja)
	{
		if (vec[i * 2].getDato() > vec[i * 2 + 1].getDato())
		{
			mayor = i * 2;
		}
		else
		{
			mayor = i * 2 + 1;
		}
		if (vec[mayor].getDato() > vec[i].getDato())
		{
			T aux = vec[mayor].getDato();
			vec[mayor].setDato(vec[i].getDato());
			vec[i].setDato(aux);
			recuperarArriba_Abajo(mayor);
		}
	}
	if (i * 2 <= ultimaHoja)
	{
		mayor = i * 2;
		if (vec[mayor].getDato() > vec[i].getDato())
		{
			T aux = vec[mayor].getDato();
			vec[mayor].setDato(vec[i].getDato());
			vec[i].setDato(aux);
			recuperarArriba_Abajo(mayor);
		}
	}
}

template<class T>
void Heap<T>::recuperarAbajo_Arriba(int i)
{
	if (i!=1)
	{
		if (vec[i].getDato() > vec[i/2].getDato())
		{
			T aux = vec[i/2].getDato();
			vec[i / 2].setDato(vec[i].getDato());
			vec[i].setDato(aux);
			recuperarAbajo_Arriba(i/2);
		}
		/*if (vec[i].getDato() > vec[i / 2].getDato())
		{
			T aux = vec[(i / 2)+1].getDato();
			vec[(i / 2)+1].setDato(vec[i].getDato());
			vec[i].setDato(aux);
			recuperarAbajo_Arriba((i / 2)+1);
		}*/
	}
}

template<class T>
void Heap<T>::insertar(T elem)
{
	if (ultimaHoja == NULL)
	{
		ultimaHoja = 1;

		vec[ultimaHoja].setDato(elem);
		vec[ultimaHoja].Presente(true);
	}
	else
	{
		ultimaHoja = ultimaHoja + 1;
		vec[ultimaHoja].setDato(elem);
		vec[ultimaHoja].Presente(true);
		recuperarAbajo_Arriba(ultimaHoja);
	}
}


template<class T>
void Heap<T>::recorrerHeap()
{
	for (int i = 1; i <= ultimaHoja; i++)
	{
		cout << vec[i].getDato() << endl;
	}
}

template<class T>
T Heap<T>::eliminarMayor()
{
	T mayor;
	if (ultimaHoja == NULL)
	{
		mayor = NULL;
	}
	else
	{
		mayor = vec[1].getDato();
		vec[1].setDato(vec[ultimaHoja].getDato());
		vec[ultimaHoja].Presente(false);
		ultimaHoja = ultimaHoja - 1;
		if (ultimaHoja == 0)
		{
			ultimaHoja = NULL;
		}
		else
		{
			recuperarArriba_Abajo(1);
		}
		
	}
	return mayor;
}

template<class T>
T Heap<T>::getMayor()
{
	return vec[1].getDato();
}

template<class T>
T Heap<T>::getMenor()
{
	return vec[ultimaHoja].getDato();
}

template<class T>
int Heap<T>::getTam()
{
	return ultimaHoja;
}

