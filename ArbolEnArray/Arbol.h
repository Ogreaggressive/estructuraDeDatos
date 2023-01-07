#pragma once

#include <iostream>
#include <string>

#include "Valor.h"

#define tam 20

template<class T>
class Arbol
{
private:
	Valor<T> arr[tam] = { NULL };
public:
	Arbol();
	~Arbol();
	void insertar(T dato, T padre);
	bool insertarElementoRecursivo(T elem, T papi, int posRaiz);
	int contar();
	int contarRecursivo(int posicion);
	int calcularAltura();
	int calcularAlturaRecursivo(int posicion);
	void recorrerInOrder();
	void recorrerInOrderRecursivo(int posicion);
	void recorrerPostOrder();
	void recorrerPostOrderRecursivo(int posicion);
	void recorrerPreOrder();
	void recorrerPreOrderRecursivo(int posicion);
};

template<class T>
Arbol<T>::Arbol()
{

}

template<class T>
Arbol<T>::~Arbol()
{

}

template<class T>
bool Arbol<T>::insertarElementoRecursivo(T elem, T papi, int posRaiz)
{
	bool res = false;
	if (arr[posRaiz].existe() == false)
	{
		arr[posRaiz].setDato(elem);
		arr[posRaiz].setExistente();
		res = true;
	}
	else
	{
		if (arr[posRaiz].getDato() == papi)
		{
			if (arr[posRaiz * 2].existe() == false)
			{
				arr[posRaiz * 2].setDato(elem);
				arr[posRaiz * 2].setExistente();
				res = true;
			}
			else
			{
				if (arr[(posRaiz * 2)+1].existe() == false)
				{
					arr[(posRaiz * 2) + 1].setDato(elem);
					arr[(posRaiz * 2) + 1].setExistente();
					res = true;
				}
			}
		}
		else
		{
			res = insertarElementoRecursivo(elem,papi, posRaiz *2);
			if (res == false)
			{
				res = insertarElementoRecursivo(elem, papi, (posRaiz * 2)+1);
			}
		}
	}
	return res;
}

template<class T>
void Arbol<T>::insertar(T dato, T padre)
{
	int pos = 1;
	bool resp;
	resp = insertarElementoRecursivo(dato, padre, pos);
}

template<class T>
int Arbol<T>::contar()
{
	int pos = 1;
	int resp;
	resp = contarRecursivo(pos);
	return resp;
}

template<class T>
int Arbol<T>::contarRecursivo(int posicion)
{
	int res;
	int res1, res2;
	if (arr[posicion].existe() == false)
	{
		res = 0;
	}
	else
	{
		res1= contarRecursivo(posicion * 2);
		res2 = contarRecursivo((posicion * 2) + 1);
		res = res1 + res2+1;
	}
	return res;
}


template<class T>
int Arbol<T>::calcularAltura()
{
	int pos = 1;
	int resp;
	resp = calcularAlturaRecursivo(pos);
	return resp;
}

template<class T>
int Arbol<T>::calcularAlturaRecursivo(int posicion)
{
	int res;
	int res1, res2;
	if (arr[posicion].existe() == false)
	{
		res = 0;
	}
	else
	{
		res1 = calcularAlturaRecursivo(posicion * 2);
		res2 = calcularAlturaRecursivo((posicion * 2) + 1);
		if (res1 > res2)
		{
			res = res1 + 1;
		}
		else
		{
			res = res2 + 1;
		}
	}
	return res;
}

template<class T>
void Arbol<T>::recorrerInOrder()
{
	int pos = 1;
	recorrerInOrderRecursivo(pos);
	cout << endl;
}

template<class T>
void Arbol<T>::recorrerInOrderRecursivo(int posicion)
{
	if (arr[posicion].existe() == false)
	{
		return;
	}
	else
	{
		recorrerInOrderRecursivo(posicion * 2);
		cout << (arr[posicion].getDato())<<" ";
		recorrerInOrderRecursivo((posicion * 2) + 1);
	}
}

template<class T>
void Arbol<T>::recorrerPostOrder()
{
	int pos = 1;
	recorrerPostOrderRecursivo(pos);
	cout << endl;
}

template<class T>
void Arbol<T>::recorrerPostOrderRecursivo(int posicion)
{
	int res;
	int res1, res2;
	if (arr[posicion].existe() == false)
	{

	}
	else
	{
		recorrerPostOrderRecursivo(posicion * 2);
		recorrerPostOrderRecursivo((posicion * 2) + 1);	
		cout << (arr[posicion].getDato())<<" ";
	}
}

template<class T>
void Arbol<T>::recorrerPreOrder()
{
	int pos = 1;
	recorrerPreOrderRecursivo(pos);
	cout << endl;
}

template<class T>
void Arbol<T>::recorrerPreOrderRecursivo(int posicion)
{
	int res;
	int res1, res2;
	if (arr[posicion].existe() == false)
	{

	}
	else
	{
		cout << (arr[posicion].getDato()) << " ";
		recorrerPreOrderRecursivo(posicion * 2);
		recorrerPreOrderRecursivo((posicion * 2) + 1);
	}
}

/*
template<class T>
void Arbol<T>::addBack(T* dato)
{

	if (primer == NULL && ultimo == NULL)
	{
		primer = new Valor<T>(dato);
		ultimo = primer;
	}
	else
	{
		Valor<T>* aux = primer;
		primer = new Valor<T>(dato);
		primer->crearSiguiente(aux);
		aux->crearAnterior(primer);
	}
}*/