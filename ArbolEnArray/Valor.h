#pragma once

#include <iostream>
using namespace std;

template<class T>
class Valor
{
private:
	T dato;
	bool existente;
public:
	Valor(T dato);
	Valor();
	~Valor();
	T getDato();
	bool existe();
	void setExistente();
	void setDato(T dato);
};

template<class T>
Valor<T>::Valor(T dato)
{
	this->dato = dato;
	existente = false;
}

template<class T>
Valor<T>::Valor()
{
	dato = NULL;
	existente = NULL;
}

template<class T>
Valor<T>::~Valor()
{

}

template<class T>
T Valor<T>::getDato()
{
	return dato;
}

template<class T>
bool Valor<T>::existe()
{
	return existente;
}

template<class T>
void Valor<T>::setDato(T dato)
{
	this->dato = dato;
}

template<class T>
void Valor<T>::setExistente()
{
	existente = true;
}




