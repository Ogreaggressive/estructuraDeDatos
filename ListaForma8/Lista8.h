#pragma once

#include <iostream>
#include <string>

#include "Tripla.h"
#include "ListaVaciaException.h"

template<class T>
class Lista8
{
private:
	Tripla<T>* primer;
	Tripla<T>* ultimo;
public:
	Lista8();
	~Lista8();
	void addFront(T* dato);
	void addBack(T* dato);
	void mostrar(void (*mostrarT)(T*));
	void deleteFront();
	void deleteBack();
	T* busquedaSecuencialNoRecursiva(T* dato);
	T* busquedaSecuencialRecursiva(T* dato);
	T* buscarRecursivamente(T* dato, Tripla<T>* aux);
	T* menorLista(bool(*funcComp)(T*, T*));;
	T* buscarIesimaPosicion(int pos);
	void invertirSobreSiMisma();
	void invertirOtraLista();
};

template<class T>
Lista8<T>::Lista8()
{
	primer = NULL;
	ultimo = NULL;
}

template<class T>
Lista8<T>::~Lista8()
{
	Tripla<T>* segundo;
	while (primer != NULL)
	{
		if (primer == ultimo)
		{
			delete primer;
			ultimo = NULL;
			primer = NULL;
		}
		else
		{
			segundo = primer->getSiguiente();
			delete primer;
			primer = segundo;
			//primer->anterior=NULL;
			primer->crearAnterior(NULL);
		}
	}
}

//primera manera
template<class T>
void Lista8<T>::addBack(T* dato)
{
	
	if (primer == NULL && ultimo == NULL)
	{
		primer = new Tripla<T>(dato);
		ultimo = primer;
	}
	else
	{
		Tripla<T>* aux = primer;
		primer = new Tripla<T>(dato);
		primer->crearSiguiente(aux);
		aux->crearAnterior(primer);
	}
}


//segunda manera
template<class T>
void Lista8<T>::addFront(T* dato)
{
	if (primer == NULL)
	{
		primer = new Tripla<T>(dato);
		ultimo = primer;
	}
	else
	{
		Tripla<T>* aux = ultimo;
		ultimo = new Tripla<T>(dato);
		ultimo->crearAnterior(aux);
		aux->crearSiguiente(ultimo);
	}
}

template<class T>
void Lista8<T>::mostrar(void (*mostrarT)(T*))
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	else
	{
		Tripla<T>* aux = primer;
		while (aux != NULL)
		{
			(*mostrarT)(aux->getDato());
			aux = aux->getSiguiente();
		}
	}
}

template<class T>
void Lista8<T>::deleteBack()
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	if (primer == ultimo)
	{
		delete primer;
		ultimo = NULL;
		primer = NULL;
	}
	else
	{
		Tripla<T>* aux = primer->getSiguiente();
		delete primer;
		primer = aux;
		primer->crearAnterior(NULL);
	}
}

template<class T>
void Lista8<T>::deleteFront()
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	if (primer == ultimo)
	{
		delete primer;
		ultimo = NULL;
		primer = NULL;
	}
	else
	{
		Tripla<T>* aux = ultimo->getAnterior();
		delete ultimo;
		ultimo = aux;
		ultimo->crearSiguiente(NULL);
	}
}

template<class T>
T* Lista8<T>::busquedaSecuencialNoRecursiva(T* dato)
{
	Tripla<T>* aux = primer;
	T* datoEncontrado = NULL;
	while (aux != NULL)
	{
		if (*aux->getDato() == dato)
		{
			datoEncontrado=aux->getDato();
		}
		aux = aux->getSiguiente();
	}
	return datoEncontrado;
}


template<class T>
T* Lista8<T>::busquedaSecuencialRecursiva(T* dato)
{
	Tripla<T>* aux = primer;
	return buscarRecursivamente(dato, aux);
}

template<class T>
T* Lista8<T>::buscarRecursivamente(T* dato, Tripla<T>* aux)
{
	if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		if (*aux->getDato() == dato)
		{
			return aux->getDato();
		}
		else
		{
			return buscarRecursivamente(dato, aux->getSiguiente());
		}
	}
}

template<class T>
T* Lista8<T>::menorLista(bool (*funcComp)(T*, T*))
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	T* menor = primer->getDato();
	Tripla<T>* aux = primer->getSiguiente();

	while (aux == NULL)
	{
		if ((*funcComp)(aux->getDato(), menor) == false)
		{
			menor = aux->getDato();
		}
		aux = aux->getSiguiente();
	}
	return menor;
}


template<class T>
T* Lista8<T>::buscarIesimaPosicion(int pos)
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	Tripla<T>* aux = primer;
	T* datoEncontrado = NULL;
	int cont = 0;
	while (aux != NULL)
	{
		if (pos == cont)
		{
			datoEncontrado = aux->getDato();
		}
		cont++;
		aux = aux->getSiguiente();
	}
	return datoEncontrado;
}

template<class T>
void intercambiar(Tripla<T>* a, Tripla<T>* b)
{
	T* aux = a->getDato();
	a->setDato(b->getDato());
	b->setDato(aux);
}

template <class T>
void Lista8<T>::invertirSobreSiMisma()
{
	Tripla<T>* i = primer;
	Tripla<T>* j = ultimo;

	int tam=0;
	Tripla<T>* aux = primer;
	while (aux != NULL)
	{
		aux = aux->getSiguiente();
		tam += 1;
	}

	int cont = 0;
	while (i != j)
	{
		intercambiar((i), (j));
		i=	i->getSiguiente();
		j = j->getAnterior();
		cont += 1;
	}
}
