#pragma once

#include <iostream>
#include <string>

#include "Cabecera.h"
#include "Lista8.h"
#include "ListaVaciaException.h"

template<class T>
class ListaDeListas
{
private:
	Cabecera<T>* primer;
public:
	ListaDeListas();
	~ListaDeListas();
	void addDatoEnLista(T* nombreLista, T* dato);
	void addBack(T* dato);
	void mostrar(void (*mostrarT)(T*));
	void deleteFront();
	void deleteBack();
	T* busquedaSecuencialRecursiva(T* dato);
	T* buscarRecursivamente(T* dato, Cabecera<T>* aux);
};

template<class T>
ListaDeListas<T>::ListaDeListas()
{
	primer = NULL;
}

template<class T>
ListaDeListas<T>::~ListaDeListas()
{

}



//segunda manera
template<class T>
void ListaDeListas<T>::addDatoEnLista(T* nombreLista, T* dato)
{
	if (primer == NULL)
	{
		primer = new Cabecera<T>(nombreLista);
		primer->aumentarEnLista(dato);
	}
	else
	{
		Cabecera<T>* aux = primer;
		while (aux != NULL && (aux->getNombreLista() != nombreLista))
		{
			aux = aux->getSiguiente();
		}
		if (aux == NULL)
		{
			Cabecera<T>* nuevaLista = new Cabecera<T>(nombreLista);
			nuevaLista->aumentarEnLista(dato);
			nuevaLista->crearSiguiente(primer);
			primer = nuevaLista;
		}
		else
		{
			aux->aumentarEnLista(dato);
		}
	}
}

template<class T>
void ListaDeListas<T>::mostrar(void (*mostrarT)(T*))
{
	if (primer == NULL)
	{
		throw ListaVaciaException();
	}
	else
	{
		Cabecera<T>* recorrerLista = primer;
		while (recorrerLista != NULL)
		{
			cout << "materia:" << endl;
			(*mostrarT)(recorrerLista->getNombreLista());
			Lista8<T>* auxLista = recorrerLista->getLista();
			Tripla<T>* aux = auxLista->getPrimer();
			cout << "estudiantes:" << endl;
			while (aux != NULL)
			{
				(*mostrarT)(aux->getDato());
				aux = aux->getSiguiente();
			}
			recorrerLista = recorrerLista->getSiguiente();
		}	
	}
}



template<class T>
T* ListaDeListas<T>::busquedaSecuencialRecursiva(T* dato)
{
	Cabecera<T>* aux = primer;
	return buscarRecursivamente(dato, aux);
}

template<class T>
T* ListaDeListas<T>::buscarRecursivamente(T* dato, Cabecera<T>* aux)
{
	/*if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		if (*aux->getLista()->getPrimer()->getDato() == dato)
		{
			return aux->getDato();
		}
		else
		{
			return buscarRecursivamente(dato, aux->getSiguiente());
		}
	}*/
}



