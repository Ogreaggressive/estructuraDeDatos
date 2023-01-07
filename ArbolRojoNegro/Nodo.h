#pragma once
#include <iostream>
using namespace std;

template <class T>
class Nodo
{
private:
	T Dato;
	string Color;
	Nodo<T>* izquierda;
	Nodo<T>* derecha;
public:
	Nodo();
	~Nodo();
	Nodo<T>*& getIzquierda();
	Nodo<T>*& getDerecha();
	T getDato();
	string getColor();
	void setColor(string palabra);
	void setDato(T dato);
	void crearIzquierda(Nodo<T>* newizquierda);
	void crearDerecha(Nodo<T>* newderecha);
};

template<class T>
Nodo<T>::Nodo()
{
	this->izquierda = NULL;
	this->derecha = NULL;
	this->Dato = NULL;
	this->Color = "";
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
string Nodo<T>::getColor()
{
	return Color;
}

template<class T>
void Nodo<T>::setColor(string palabra)
{
	Color = palabra;
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

