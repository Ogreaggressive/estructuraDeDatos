#pragma once

#include <iostream>

#include "Lista8.h"
using namespace std;

template<class T>
class Cabecera
{
private:
	Cabecera* siguiente;
	Lista8<T>* lista;
	T* nombreLista;
public:
	Cabecera(T* nombre);
	Cabecera();
	~Cabecera();
	T* getNombreLista();
	Lista8<T>* getLista();
	void setLista(Cabecera<T>* lista);
	Cabecera<T>* getSiguiente();
	void crearSiguiente(Cabecera<T>* lista);
	void aumentarEnLista(T* dato);
	//bool operator==(Cabecera* t);
};

template<class T>
Cabecera<T>::Cabecera(T* nombre)
{
	this->nombreLista = nombre;
	lista = new Lista8<T>();
	siguiente = NULL;
}

template<class T>
Cabecera<T>::Cabecera()
{
	lista = NULL;
	siguiente = NULL;
}

template<class T>
Cabecera<T>::~Cabecera()
{

}

template<class T>
T* Cabecera<T>::getNombreLista()
{
	return nombreLista;
}

template<class T>
Lista8<T>* Cabecera<T>::getLista()
{
	return lista;
}

template<class T>
void Cabecera<T>::setLista(Cabecera<T>* lista)
{
	this->lista = lista;
}


template<class T>
Cabecera<T>* Cabecera<T>::getSiguiente()
{
	return siguiente;
}


template<class T>
void Cabecera<T>::crearSiguiente(Cabecera<T>* nuevoSig)
{
	siguiente = nuevoSig;
}

template<class T>
void Cabecera<T>::aumentarEnLista(T* dato)
{
	lista->addBack(dato);
}

/*template<class T>
bool Cabecera<T>::operator==(Cabecera* t)
{
	return lista == t->getLista();
}*/





