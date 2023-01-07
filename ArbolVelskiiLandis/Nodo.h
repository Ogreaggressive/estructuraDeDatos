#pragma once
#include <iostream>
using namespace std;

template <class T>
class Nodo
{
private:
	T Dato;
	int factor;
	Nodo<T>* izquierda;
	Nodo<T>* derecha;
public:
	Nodo(T dato);
	Nodo();
	~Nodo();
	Nodo<T>*& getIzquierda();
	Nodo<T>*& getDerecha();
	T getDato();
	int getFactor();
	void setFactor(int palabra);
	void setDato(T dato);
	void setIzquierda(Nodo<T>* newizquierda);
	void setDerecha(Nodo<T>* newderecha);
};

template<class T>
Nodo<T>::Nodo()
{
	this->izquierda = NULL;
	this->derecha = NULL;
	this->Dato = NULL;
	this->factor = 0;
}

template<class T>
Nodo<T>::Nodo(T dato)
{
	this->izquierda = NULL;
	this->derecha = NULL;
	this->Dato = dato;
	this->factor = 0;
}

template<class T>
Nodo<T>::~Nodo()
{

}

template<class T>
Nodo<T>*& Nodo<T>::getIzquierda()
{
	return izquierda;
}

template<class T>
Nodo<T>*& Nodo<T>::getDerecha()
{
	return derecha;
}

template<class T>
T Nodo<T>::getDato()
{
	return Dato;
}

template<class T>
int Nodo<T>::getFactor()
{
	return factor;
}

template<class T>
void Nodo<T>::setFactor(int palabra)
{
	factor = palabra;
}

template<class T>
void Nodo<T>::setDato(T dato)
{
	Dato = dato;
}

template<class T>
void Nodo<T>::setIzquierda(Nodo<T>* newizquierda)
{
	izquierda = newizquierda;
}

template<class T>
void Nodo<T>::setDerecha(Nodo<T>* newderecha)
{
	derecha = newderecha;
}

