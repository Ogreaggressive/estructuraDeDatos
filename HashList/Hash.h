#pragma once

#include "Lista8.h"
#include <vector>
#include "ListaVaciaException.h"

template<class T>
class Hash
{
private:
	Lista8<T>* hash;
	int tam;
public:
	Hash(int tam);
	~Hash();
	void insertarEnHash(int(*funcGetNumero)(T*), T* dato);
	//void insertarEnHash(T* dato);
	void mostrar(void (*mostrarT)(T*));
	void eliminarEnHash(int(*funcGetNumero)(T*), T* dato);
	//void buscarEnHash(T* dato);
	int funcionHash(int num);
	bool buscar(int(*funcGetNumero)(T*), T* dato);
	void contarCajas(int vect[10000]);
	void contarCajas2(int vect[10000]);
	void contarCajas3(int vect[10000]);
};

template<typename T>
Hash<T>::Hash(int tam) 
{
	this->tam = tam;
	hash = new Lista8<T> [tam];
}

template<typename T>
Hash<T>::~Hash()
{

}

template<typename T>
void Hash<T>::insertarEnHash(int(*funcGetNumero)(T*),T* dato)
{
	int num;
	num=funcionHash((*funcGetNumero)(dato));
	hash[num].insertarContando(dato);
}

/*
template<typename T>
void Hash<T>::insertarEnHash(T*dato)
{
	int pos;
	pos = funcionHash();
	hash[pos].insertarContando(dato);
}*/


template<typename T>
void Hash<T>::eliminarEnHash(int(*funcGetNumero)(T*), T* dato)
{
	int num;
	bool res;
	num = funcionHash((*funcGetNumero)(dato));
	if (hash[num].buscar(dato) != NULL)
	{
		hash[num].deleteValue(hash[num].buscar(dato));
	}
}

template<typename T>
int Hash<T>::funcionHash(int num)
{
	int t;
	t = num%tam;
	return t; 
}

template<typename T>
void Hash<T>::mostrar(void (*mostrarT)(T*))
{
	
	for (int i = 0; i < tam; i++)
	{
		int totEnCaja = 0;
		Tripla<T>* aux = hash[i].getPrimer();
		while (aux != NULL)
		{
			(*mostrarT)(aux->getDato());
			cout << "   " << aux->getContador();
			aux = aux->getSiguiente();
			cout << endl;
		}
	}
}

template<typename T>
bool Hash<T>::buscar(int(*funcGetNumero)(T*), T* dato)
{
	int num;
	bool res;
	num = funcionHash((*funcGetNumero)(dato));
	if (hash[num].buscar(dato) == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
	}
	return res;
}


template<class T>
void Hash<T>::contarCajas(int vect[10000])
{
	for (int i = 0; i < tam; i++)
	{
		Tripla<T>* aux = hash[i].getPrimer();
		if (aux == NULL)
		{
			vect[0]=vect[0]+1;
		}
		else
		{
			int num = 0;
			while (aux != NULL)
			{
				num = num +1;
				aux = aux->getSiguiente();
			}
			vect[num] = 1 + vect[num];
		}
	}
}

template<class T>
void Hash<T>::contarCajas2(int vect[10000])
{
	int cont;
	for (int i = 0; i < tam; i++)
	{
		Tripla<T>* aux = hash[i].getPrimer();
		cont = 0;
		if (aux != NULL)
		{
			while (aux != NULL)
			{
				cont++;
				aux = aux->getSiguiente();
			}
			vect[cont]++;
		}
	}
}

template<class T>
void Hash<T>::contarCajas3(int vect[10000])
{
	int cont;
	for (int i = 0; i < tam; i++)
	{
		Tripla<T>* aux = hash[i].getPrimer();
		cont = 0;
		if (aux != NULL)
		{
			while (aux != NULL)
			{
				cont = cont + 1;
				aux = aux->getSiguiente();
			}
			vect[cont]++;
		}
	}
}