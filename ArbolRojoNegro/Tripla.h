#pragma once

#include <iostream>
using namespace std;

template<class T>
class Tripla
{
private:
	T dato;
	string color;
	Tripla* derecha;
	Tripla* izquierda;
public:
	Tripla(T dato);
	Tripla();
	~Tripla();
	T getDato();
	string getColor();
	void setColor(string palabra);
	void setDato(T dato);

	Tripla<T>*& getDerecha();
	void crearDerecha(Tripla<T>* dato);
	Tripla<T>*& getIzquierda();
	void crearIzquierda(Tripla<T>* dato);
};

template<class T>
Tripla<T>::Tripla(T dato)
{
	this->dato = dato;
	derecha = NULL;
	izquierda = NULL;
	this->color = "";
}

template<class T>
Tripla<T>::Tripla()
{
	dato = NULL;
	derecha = NULL;
	izquierda = NULL;
	this->color = "";
}

template<class T>
Tripla<T>::~Tripla()
{

}

template<class T>
T Tripla<T>::getDato()
{
	return dato;
}

template<class T>
void Tripla<T>::setDato(T dato)
{
	this->dato = dato;
}


template<class T>
Tripla<T>*& Tripla<T>::getDerecha()
{
	return derecha;
}


template<class T>
void Tripla<T>::crearDerecha(Tripla<T>* nuevoSig)
{
	derecha = nuevoSig;
}

template<class T>
Tripla<T>*& Tripla<T>::getIzquierda()
{
	return izquierda;
}


template<class T>
void Tripla<T>::crearIzquierda(Tripla<T>* nuevoAnt)
{
	izquierda = nuevoAnt;
}

template<class T>
string Tripla<T>::getColor()
{
	return color;
}

template<class T>
void Tripla<T>::setColor(string palabra)
{
	color = palabra;
}





