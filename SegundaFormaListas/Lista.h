#pragma once

#include <iostream>
#include <string>

#include "ListaVaciaException.h"
#include "Cliente.h"

template<class T>
class Lista
{
private:
	T** PrincipalArray;
	int primer, ultimo;
	int tam;
public:
	Lista(int tam);
	~Lista();
	void addFront(T* dato);
	void addBack(T* dato);
	T* operator[](int i);
	void mostrar(void (*mostrarT)(T*));
	void deleteFront();
	void deleteBack();
	T* busquedaSecuencialNoRecursiva(T* dato);
	T* busquedaSecuencialRecursiva(T* dato);
	T* buscarRecursivamente(T* dato, int i);
	T* menorLista(bool(*funcComp)(T*, T*));;
	int getPrimer();
	int getUltimo();
	T* BusquedaBinaria(T* aux);
	T* BinarySearch(T* aux, int first, int last);
	//T* BinarySearch(bool(*mostrarT)(T*), T* dato, int first, int last);
	//Cliente* BusquedaBinaria(Cliente* aux);
	//Cliente* BinarySearch(Cliente* aux, int first, int last);
	void ordenar(bool (*funcComp)(T*, T*));
};

template<class T>
Lista<T>::Lista(int tam)
{
	primer = -1;
	ultimo = -1;
	PrincipalArray = new T*[tam];
	for (int i = 0; i < tam; i++)
	{
		PrincipalArray[i] = new T;
	}

	this->tam = tam;
	
}

template<class T>
Lista<T>::~Lista()
{
	for (int i = 0; i < tam; i++)
	{
		delete PrincipalArray[i];
	}
	delete[] PrincipalArray;
}

template<class T>
void Lista<T>::addBack(T* dato)
{
	if (primer == -1 && ultimo == -1)
	{
		primer = tam / 2;
		ultimo = primer;
		PrincipalArray[primer] = dato;
	}
	else
	{
		if (primer - 1 == ultimo || (primer == 0 && ultimo == tam - 1))
		{
			throw ListaVaciaException(); //con lista llena
		}
		else
		{
			if (primer > 0)
			{
				primer--;
			}
			else
			{
				primer = tam - 1;
			}
			PrincipalArray[primer] = dato;
		}
	}
}

template<class T>
void Lista<T>::addFront(T* dato)
{
	if (primer == -1 && ultimo == -1)
	{
		primer = tam / 2;
		ultimo = primer;
		PrincipalArray[primer] = dato;
	}
	else
	{
		if (primer - 1 == ultimo || (primer == 0 && ultimo == tam - 1))
		{
			throw ListaVaciaException(); //con lista llena
		}
		else
		{
			if (ultimo < tam-1)
			{
				ultimo++;
			}
			else
			{
				ultimo = 0;
			}
			PrincipalArray[ultimo] = dato;
		}
	}

}

template<class T>
T* Lista<T>::operator[](int i)
{
	return PrincipalArray[i];
}

template<class T>
void Lista<T>::mostrar(void (*mostrarT)(T*))
{
	int i = primer;
	while (i != ultimo)
	{
		(*mostrarT)(PrincipalArray[i]);
		if (i == tam - 1)
		{
			i = 0;
		}
		else
		{
			i++;
		}
	}
	if (i == ultimo && primer != 1)
	{
		(*mostrarT)(PrincipalArray[ultimo]);
	}
}

template<class T>
void Lista<T>::deleteFront()
{
	if (primer == -1 && ultimo == -1)
	{
		throw ListaVaciaException(); //lista vacia
	}
	else
	{
		if (primer == ultimo)
		{
			primer = -1;
			ultimo = -1;
		}
		else
		{
			if (primer < tam - 1)
			{
				primer++;
			}
			else
			{
				primer = 0;
			}
		}
	}
}


template<class T>
void Lista<T>::deleteBack()
{
	if (primer == -1 && ultimo == -1) 
	{
		throw ListaVaciaException(); //lista vacia
	}
	else
	{
		if (primer == ultimo)
		{
			primer = -1;
			ultimo = -1;
		}
		else
		{
			if (ultimo > 0)
			{
				ultimo--;
			}
			else
			{
				ultimo = tam - 1;
			}
		}
	}
}


template<class T>
T* Lista<T>::busquedaSecuencialNoRecursiva(T* dato)
{
	int i = primer;
	while (i != ultimo + 1)
	{
		if ((*PrincipalArray[i]) == dato)
		{
			return PrincipalArray[i];
		}
		if (i == tam - 1)
		{
			i = 0;
		}
		else
		{
			i++;
		}
	}
	return NULL;
}

template<class T>
T* Lista<T>::busquedaSecuencialRecursiva(T* dato)
{
	return buscarRecursivamente(dato, primer);
}

template<class T>
T* Lista<T>::buscarRecursivamente(T* dato, int i)
{
	if (i == ultimo + 1)
	{
		return NULL;
	}
	else
	{
		if ((*PrincipalArray[i]) == dato)
		{
			return PrincipalArray[i];
		}
		else
		{
			if (i < tam - 1)
			{
				return buscarRecursivamente(dato, i + 1);
			}
			else
			{
				return buscarRecursivamente(dato, 0);
			}
		}
	}
}

template<class T>
T* Lista<T>::menorLista(bool (*funcComp)(T*, T*))
{
	T* menor = PrincipalArray[primer];
	int i = primer + 1;
	while (i != ultimo + 1)
	{
		if ((*funcComp)(PrincipalArray[i], menor)==false)
		{
			menor = PrincipalArray[i];
		}

		if (i == tam - 1)
		{
			i = 0;
		}
		else
		{
			i++;
		}
	}
	return menor;
}

template<class T>
int Lista<T>::getPrimer()
{
	return primer;
}

template<class T>
int Lista<T>::getUltimo()
{
	return ultimo;
}



template <class T>
T * Lista<T>::BusquedaBinaria(T * dato)
{
	return BinarySearch(dato, primer, ultimo);
}


template <class T>
T* Lista<T>::BinarySearch(T* dato, int first, int last)
{
	if (first == last + 1)
	{
		return NULL;
	}
	else
	{
		int mid = 0;

		if (first<last)
		{
			mid = (first+last-1)/2;
		}
		else
		{
			int espacioOcupado = tam - ((first - last)-1);
			mid = (first + (espacioOcupado / 2)) - (tam - 1);
		}
		if ((*PrincipalArray[mid]) == dato)
		{
			return PrincipalArray[mid];
		}
		else
		{
			
			if (*PrincipalArray[mid] > dato)
			{
				return BinarySearch(dato,first,mid-1);
			}
			else
			{
				return BinarySearch(dato,mid+1,last);
			}
		}
	}
}

template<class T>
void intercambiar(T* a, T* b)
{
	T aux = *a;
	*a = *b;
	*b = aux;
}

template <class T>
void Lista<T>::ordenar(bool (*funcComp)(T*, T*))
{
	int i = primer;
	while(i!=ultimo+1)
	{
		if (i == tam)
		{
			i = 0;
		}
		int j = i + 1;
		while (j!=ultimo+1)
		{
			if (j == tam)
			{
				j = 0;
			}

			if ((*funcComp)(PrincipalArray[i], PrincipalArray[j]))
			{
				intercambiar(&(PrincipalArray[i]), &(PrincipalArray[j]));
			}
			j++;
		}
		i++;
	}
}