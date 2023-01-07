#pragma once

#include "Nodo.h"

template<class T>
class ListaGenerica
{
private:
	Nodo<T>* primer;
	int tam;
public:
	ListaGenerica();
	~ListaGenerica();
	int getTam();
	Nodo<T>* getPrimer();
	void registrar(T* dato);
	void mostrar(void(*mostrarT)(T*));
	T* buscar(T* dato);
	void ordenar(bool (*funcComp)(T*, T*));
	T* operator[](int i);
	void ordenar2(bool (*funcComp)(T*, T*));
	void eliminar(T* dato);
};


template<class T>
ListaGenerica<T>::ListaGenerica()
{
	primer = NULL;
	tam = 0;
}

template<class T>
ListaGenerica<T>::~ListaGenerica()
{
}

template<class T>
int ListaGenerica<T>::getTam()
{
	return tam;
}

template<class T>
Nodo<T>* ListaGenerica<T>::getPrimer()
{
	return primer;
}

template<class T>
void ListaGenerica<T>::registrar(T* dato)
{
	if (primer == NULL)
	{
		primer = new Nodo<T>(dato);
	}
	else
	{
		Nodo<T>* aux = primer;
		while (aux->getSiguiente() != NULL)
		{
			aux = aux->getSiguiente();
		}
		aux->crearSiguiente(dato);
	}
	tam++;
}


template<class T>
void ListaGenerica<T>::mostrar(void (*mostrarT)(T*))
{
	Nodo<T>* aux = primer;
	while (aux != NULL)
	{
		(*mostrarT)(aux->getDato());
		aux = aux->getSiguiente();
	}
}

template<class T>
T* ListaGenerica<T>::operator[](int i)
{
	Nodo<T>* aux = primer;
	for (int num = 0; num < i; num++)
	{
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}

template<class T>
T* ListaGenerica<T>::buscar(T* dato)
{
	Nodo<T>* aux = primer;
	while (aux != NULL)
	{
		if (*(aux->getDato()) == dato)
		{
			return aux->getDato();
		}
		aux = aux->getSiguiente();
	}
	return NULL;
}

template<class T>
void ListaGenerica<T>::ordenar(bool (*funcComp)(T*, T*))
{
	Nodo<T>* aux = primer;
	Nodo<T>* auxSiguiente;
	T* dato;
	while (aux->getSiguiente() != NULL)
	{
		auxSiguiente = aux->getSiguiente();
		while (auxSiguiente != NULL)
		{
			if ((*funcComp)(aux->getDato(), auxSiguiente->getDato()))
			{
				dato = aux->getDato();
				aux->setDato(auxSiguiente->getDato());
				auxSiguiente->setDato(dato);
			}
			auxSiguiente = auxSiguiente->getSiguiente();
		}
		aux = aux->getSiguiente();
	}
}

template<class T>
void ListaGenerica<T>::eliminar(T* dato)
{
	if (primer != NULL)
	{
		Nodo<T>* aux_borrar;
		Nodo<T>* anterior = NULL;

		aux_borrar = primer;

		while ((aux_borrar != NULL) && !(*(aux_borrar->getDato()) == dato))
		{
			anterior = aux_borrar;
			aux_borrar = aux_borrar->getSiguiente();
		}
		if (aux_borrar == NULL)
		{
			cout << "elemento no encontrado" << endl;
		}
		else if (anterior == NULL)
		{
			primer = primer->getSiguiente();
			delete aux_borrar;
		}
		else
		{
			//anterior->getSiguiente() = aux_borrar->getSiguiente();
			anterior->crearSiguiente(aux_borrar->getSiguiente()->getDato());
			delete aux_borrar;
		}
	}
}









