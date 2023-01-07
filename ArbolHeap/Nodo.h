#pragma once
#include <iostream>
using namespace std;

template <class T>
class Nodo
{
private:
	T Dato;
	bool existe;
	Nodo<T>* izquierda;
	Nodo<T>* derecha;
public:
	Nodo();
	~Nodo();
	Nodo<T>*& getIzquierda();
	Nodo<T>*& getDerecha();
	T getDato();
	bool getExiste();
	void Presente(bool palabra);
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
	this->existe = false;
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
bool Nodo<T>::getExiste()
{
	return existe;
}

template<class T>
void Nodo<T>::Presente(bool palabra)
{
	existe = palabra;
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

