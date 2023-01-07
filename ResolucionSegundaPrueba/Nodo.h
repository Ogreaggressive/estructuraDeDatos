#pragma once
#include <iostream>
using namespace std;

template <class T>
class Nodo
{
private:
	T Dato;
	int frecuencia;
	Nodo<T>* izquierda;
	Nodo<T>* derecha;
public:
	Nodo(T dato);
	~Nodo();
	Nodo<T>*& getIzquierda();
	Nodo<T>*& getDerecha();
	T getDato();
	int getFrecuencia();
	void aumentarFrecuencia();
	void setDato(T dato);
	void crearIzquierda(Nodo<T>* newizquierda);
	void crearDerecha(Nodo<T>* newderecha);
};

template<class T>
Nodo<T>::Nodo(T dato)
{
	this->izquierda = NULL;
	this->derecha = NULL;
	Dato = dato;
	this->frecuencia = 1;
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
int Nodo<T>::getFrecuencia()
{
	return frecuencia;
}

template<class T>
void Nodo<T>::aumentarFrecuencia()
{
	frecuencia++;
}

template<class T>
void Nodo<T>::setDato(T dato)
{
	Dato = dato;
}

template<class T>
void Nodo<T>::crearIzquierda(Nodo<T>* newizquierda)
{
	izquierda = newizquierda;
}

template<class T>
void Nodo<T>::crearDerecha(Nodo<T>* newderecha)
{
	derecha = newderecha;
}


