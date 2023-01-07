#pragma once

#include <iostream>
#include <string>
#include <tuple>

#include "Nodo.h"
#include <math.h>

template<class T>
class ABB
{
private:
	Nodo<T>* raiz;
public:
	ABB();
	~ABB();

	void insertar(T elem);
	void insertar(T elem, Nodo<T>*& A);


	int Buscar(T elem);
	void Buscar(T elem, Nodo<T>* A, bool& encontrado, int &cantidad);

	int Menor();
	void Menor(Nodo<T>* A, int& num);

	int Mayor();
	void Mayor(Nodo<T>* A, int& num);

	int Contar();
	void Contar(Nodo<T>* A, int& num);

	int Altura();

	void recorrerInOrder();
	void recorrerPostOrder();
	void recorrerPreOrder();
	void recorrerInOrder(Nodo<T>* A);
	void recorrerPostOrder(Nodo<T>* A);
	void recorrerPreOrder(Nodo<T>* A);

	void mostrarMenoresANumero(int num);
	void mostrarMenoresANumero(Nodo<T>* A, int num);

	void mostrarNivel(int num);
	void mostrarNivel(Nodo<T>* A, int num);

	bool eliminar(T elem);
	bool eliminar(T elem, Nodo<T>* A);

	void eliminarABB();
	void eliminarABB(Nodo<T>* A);

	tuple<T, bool, bool> siguiente(T elem);
	tuple<T, bool, bool>siguiente(T elem, Nodo<T>* A);

};

template<class T>
ABB<T>::ABB()
{
	raiz = NULL;
}

template<class T>
ABB<T>::~ABB()
{
	//eliminarABB();
	raiz = NULL;
}


template<class T>
void ABB<T>::insertar(T elem)
{
	insertar(elem, raiz);
}

template<class T>
void ABB<T>::insertar(T elem, Nodo<T>* &A)
{
	if (A == NULL)
	{
		A = new Nodo<T>(elem);
	}
	else
	{
		if (A->getDato() == elem)
		{
			A->aumentarFrecuencia();
		}
		else
		{
			if (elem < A->getDato())
			{
				insertar(elem, A->getIzquierda());
			}
			else
				//else if (elem > A->getDato());
			{
				insertar(elem, A->getDerecha());
			}
		}	
	}
}


template<class T>
void ABB<T>::recorrerInOrder()
{
	recorrerInOrder(raiz);
}

template<class T>
void ABB<T>::recorrerInOrder(Nodo<T>* A)
{
	if (A != NULL)
	{
		recorrerInOrder(A->getIzquierda());
		cout << " frec: " << A->getFrecuencia()<< "--> " << A->getDato()<<endl;
		recorrerInOrder(A->getDerecha());
	}
}

template<class T>
void ABB<T>::recorrerPostOrder()
{
	recorrerPostOrder(raiz);
}

template<class T>
void ABB<T>::recorrerPostOrder(Nodo<T>* A)
{
	if (A != NULL)
	{
		recorrerPostOrder(A->getIzquierda());
		recorrerPostOrder(A->getDerecha());
		cout << A->getDato();
	}
}

template<class T>
void ABB<T>::recorrerPreOrder()
{
	recorrerPreOrder(raiz);
}

template<class T>
void ABB<T>::recorrerPreOrder(Nodo<T>* A)
{
	if (A != NULL)
	{
		cout << A->getDato();
		recorrerPreOrder(A->getIzquierda());
		recorrerPreOrder(A->getDerecha());
	}
}

template<class T>
int ABB<T>::Buscar(T dato)
{
	bool encontrado = false;
	int cant = 0;
	Buscar(dato, raiz, encontrado,cant);
	return cant;
}

template<class T>
void ABB<T>::Buscar(T dato, Nodo<T>* A, bool& encontrado, int &cant)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (dato == A->getDato())
		{
			encontrado = true;
			cant = A->getFrecuencia();
		}
		Buscar(dato, A->getIzquierda(), encontrado,cant);
		Buscar(dato, A->getDerecha(), encontrado,cant);
	}
}

template<class T>
int ABB<T>::Menor()
{
	int num = 0;
	if (raiz != NULL)
	{
		num = raiz->getDato();
		Menor(raiz, num);
	}
	return num;
}

template<class T>
void ABB<T>::Menor(Nodo<T>* A, int& num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (num > A->getDato())
		{
			num = A->getDato();
		}
		Menor(A->getIzquierda(), num);
		Menor(A->getDerecha(), num);
	}
}

template<class T>
int ABB<T>::Mayor()
{
	int num = 0;
	if (raiz != NULL)
	{
		num = raiz->getDato();
		Mayor(raiz, num);
	}
	return num;
}

template<class T>
void ABB<T>::Mayor(Nodo<T>* A, int& num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (num < A->getDato())
		{
			num = A->getDato();
		}
		Mayor(A->getIzquierda(), num);
		Mayor(A->getDerecha(), num);
	}
}

template<class T>
int ABB<T>::Contar()
{
	int num = 0;
	Contar(raiz, num);
	return num;
}

template<class T>
void ABB<T>::Contar(Nodo<T>* A, int& num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		num = num + 1;
		Contar(A->getIzquierda(), num);
		Contar(A->getDerecha(), num);
	}
}

template<class T>
int ABB<T>::Altura()
{
	int num = 0, tot = 0;
	Contar(raiz, num);
	tot = log(num) + 1;
	return tot + 1;
}

template<class T>
void ABB<T>::mostrarMenoresANumero(int num)
{
	mostrarMenoresANumero(raiz, num);
}

template<class T>
void ABB<T>::mostrarMenoresANumero(Nodo<T>* A, int num)
{
	if (A != NULL)
	{
		mostrarMenoresANumero(A->getIzquierda(), num);
		if (num > A->getDato())
		{
			cout << A->getDato();
		}
		mostrarMenoresANumero(A->getDerecha(), num);
	}
}

template<class T>
void ABB<T>::mostrarNivel(int num)
{
	mostrarNivel(raiz, num);
	cout << endl;
}

template<class T>
void ABB<T>::mostrarNivel(Nodo<T>* A, int num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (num == 1) //mientras no sea ese numero disminuye
		{
			cout << A->getDato() << " ";
		}
		else
		{
			mostrarNivel(A->getIzquierda(), num - 1);
			mostrarNivel(A->getDerecha(), num - 1);
		}
	}
}

template<class T>
bool ABB<T>::eliminar(T elem)
{
	bool sol;
	sol = eliminar(elem, raiz);
	return sol;
}

template<class T>
bool ABB<T>::eliminar(T elem, Nodo<T>* A)
{
	bool res = false;
	if (A == NULL)
	{
		return res;
	}
	else
	{
		if (elem < A->getDato())
		{
			res = eliminar(elem, A->getIzquierda());
		}
		if (elem > A->getDato());
		{
			res = eliminar(elem, A->getDerecha());
		}
		if (elem == A->getDato())
		{
			res = true;
			if (A->getIzquierda() == NULL && A->getDerecha() == NULL)
			{
				delete A;
			}
			else
			{
				int num, may, min;
				if (A->getIzquierda() != NULL && A->getDerecha() != NULL)
				{
					num = rand() % 2;
					if (num == 0)
					{
						may = A->getIzquierda()->getDato();
						Mayor(A->getIzquierda(), may);
						T elemento = may;
						A->setDato(elemento);
						res = eliminar(elemento, A->getIzquierda());
					}
					if (num == 1)
					{
						min = A->getDerecha()->getDato();
						Menor(A->getDerecha(), min);
						T elemento = min;
						A->setDato(elemento);
						res = eliminar(elemento, A->getDerecha());
					}
				}
				else
				{
					if (A->getIzquierda() == NULL && A->getDerecha() != NULL) //1 hijo der
					{
						may = A->getDerecha()->getDato();
						Mayor(A->getDerecha(), may);
						T elemento = may;
						A->setDato(elemento);
						res = eliminar(elemento, A->getDerecha());
					}
					else
					{
						min = A->getIzquierda()->getDato();
						Menor(A->getIzquierda(), min);
						T elemento = min;
						A->setDato(elemento);
						res = eliminar(elemento, A->getIzquierda());
					}
				}
			}
		}
	}
	return res;
}

template<class T>
void ABB<T>::eliminarABB()
{
	eliminarABB(raiz);
}
template<class T>
void ABB<T>::eliminarABB(Nodo<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		eliminarABB(A->getIzquierda());
		eliminarABB(A->getDerecha());
		delete A;
	}
}

template<class T>
tuple<T, bool, bool> ABB<T>::siguiente(T elem)
{
	bool res, Enc_Sig;
	T sig;
	tie(sig, res, Enc_Sig) = siguiente(elem, raiz);
	return make_tuple(sig, res, Enc_Sig);
}
template<class T>
tuple<T, bool, bool> ABB<T>::siguiente(T elem, Nodo<T>* A)
{
	bool res, Enc_Sig;
	T sig;
	int Men;
	if (A == NULL)
	{
		res = false;
	}
	else
	{
		if (elem == A->getDato())
		{
			res = true;
			if (A->getDerecha() == NULL)
			{
				Enc_Sig = false;
			}
			else
			{
				int num;
				num = A->getDerecha()->getDato();
				Menor(A->getDerecha(), num);
				sig = num;
				Enc_Sig = true;
			}
		}
		if (elem > A->getDato())
		{
			tie(sig, res, Enc_Sig) = siguiente(elem, A->getDerecha());
		}
		if (elem < A->getDato())
		{
			tie(sig, res, Enc_Sig) = siguiente(elem, A->getIzquierda());
			if (res == true && Enc_Sig == false)
			{
				Enc_Sig = true;
				sig = A->getDato();
			}
		}
	}
	return make_tuple(sig, res, Enc_Sig);
}

