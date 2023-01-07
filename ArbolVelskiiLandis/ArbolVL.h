#pragma once
#include "Nodo.h"

template <class T>
class ArbolVL
{
private:
	Nodo<T>* raiz;
public:
	ArbolVL();
	~ArbolVL();

	void RotarDerechaSimple(Nodo<T>*& A);
	void RotarIzquierdaSimple(Nodo<T>*& A);

	void RotarDerechaCompuesto(Nodo<T>*& A);
	void RotarIzquierdaCompuesto(Nodo<T>*& A);

	void insertar(T elem, Nodo<T>*& A, bool& continuar);
	void insertar(T elem);

	void mostrarInOrder();
	void mostrarInOrder(Nodo<T>* A);

	void mostrarPostOrder();
	void mostrarPostOrder(Nodo<T>* A);

	void mostrarPreOrder();
	void mostrarPreOrder(Nodo<T>* A);

	int Contar();
	void Contar(Nodo<T>* A, int& num);

	int Altura();
	int Altura2();
	int Altura2(Nodo<T>* A);

	bool Buscar(T elem);
	void Buscar(T elem, Nodo<T>* A, bool& encontrado);

	bool Buscar2(T elem);
	bool Buscar2(Nodo<T>* A, T elem);
};

template<class T>
ArbolVL<T>::ArbolVL()
{
	raiz = NULL;
}

template<class T>
ArbolVL<T>::~ArbolVL()
{
}

template<class T>
void ArbolVL<T>::RotarDerechaSimple(Nodo<T>*& A)
{
	Nodo<T>* aux = A->getIzquierda();
	Nodo<T>* temp;
	if (aux->getDerecha() != NULL)
	{
		temp = aux->getDerecha();
	}
	else
	{
		temp = NULL;
	}	
	aux->setDerecha(A);
	A->setIzquierda(temp);
	A = aux;
	A->setFactor(0);
	A->getDerecha()->setFactor(0);
}

template<class T>
void ArbolVL<T>::RotarIzquierdaSimple(Nodo<T>*& A)
{
	Nodo<T>* aux = A->getDerecha();
	Nodo<T>* temp;
	if (aux->getIzquierda() != NULL)
	{
		temp = aux->getIzquierda();
	}
	else
	{
		temp = NULL;
	}
	aux->setIzquierda(A);
	A->setDerecha(temp);
	A = aux;
	A->setFactor(0);
	A->getIzquierda()->setFactor(0);
}

template<class T>
void ArbolVL<T>::RotarDerechaCompuesto(Nodo<T>*& A)
{
	Nodo<T>* NuevaRaiz = A->getIzquierda()->getDerecha();
	Nodo<T>* tempI = NuevaRaiz->getIzquierda();
	Nodo<T>* tempD = NuevaRaiz->getDerecha();
	NuevaRaiz->setIzquierda(A->getIzquierda());
	NuevaRaiz->setDerecha(A);
	NuevaRaiz->getDerecha()->setIzquierda(tempD);
	NuevaRaiz->getIzquierda()->setDerecha(tempI);
	A = NuevaRaiz;
	if (A->getFactor() == 0)
	{
		A->getIzquierda()->setFactor(0);
		A->getDerecha()->setFactor(0);
	}
	else
	{
		if (A->getFactor() == 1)
		{
			A->getIzquierda()->setFactor(0);
			A->getDerecha()->setFactor(-1);
			A->setFactor(0);
		}
		else
		{
			A->getIzquierda()->setFactor(1);
			A->getDerecha()->setFactor(0);
			A->setFactor(0);
		}
	}
}

template<class T>
void ArbolVL<T>::RotarIzquierdaCompuesto(Nodo<T>*& A)
{
	Nodo<T>* NuevaRaiz = A->getDerecha()->getIzquierda();
	Nodo<T>* tempI = NuevaRaiz->getIzquierda();
	Nodo<T>* tempD = NuevaRaiz->getDerecha();
	NuevaRaiz->setDerecha(A->getDerecha());
	NuevaRaiz->setIzquierda(A);
	NuevaRaiz->getIzquierda()->setDerecha(tempI);
	NuevaRaiz->getDerecha()->setIzquierda(tempD);
	A = NuevaRaiz;
	if (A->getFactor() == 0)
	{
		A->getIzquierda()->setFactor(0);
		A->getDerecha()->setFactor(0);
	}
	else
	{
		if (A->getFactor() == 1)
		{
			A->getIzquierda()->setFactor(0);
			A->getDerecha()->setFactor(-1);
			A->setFactor(0);
		}
		else
		{
			A->getIzquierda()->setFactor(1);
			A->getDerecha()->setFactor(0);
			A->setFactor(0);
		}
	}
}

template<class T>
void ArbolVL<T>::insertar(T elem, Nodo<T>*& A, bool& continuar)
{
	if (A == NULL)
	{
		A = new Nodo<T>(elem);
		continuar = true;
	}
	else
	{
		if (elem < A->getDato())
		{
			insertar(elem, A->getIzquierda(), continuar);
			if (continuar == true)
			{
				A->setFactor(A->getFactor() + 1);
				if (A->getFactor() == 0)
				{
					continuar = false;
				}
				else
				{
					if (A->getFactor() == 2)
					{
						continuar = false;
						if (A->getIzquierda()->getFactor() == 1)
						{
							RotarDerechaSimple(A);
						}
						else
						{
							RotarDerechaCompuesto(A);
						}
					}
				}
			}
		}
		if (elem > A->getDato())
		{
			insertar(elem, A->getDerecha(), continuar);
			if (continuar == true)
			{
				A->setFactor(A->getFactor() - 1);
				if (A->getFactor() == 0)
				{
					continuar = false;
				}
				else
				{
					if (A->getFactor() == -2)
					{
						continuar = false;
						if (A->getDerecha()->getFactor() == -1)
						{
							RotarIzquierdaSimple(A);
						}
						else
						{
							RotarIzquierdaCompuesto(A);
						}
					}
				}
			}
		}
	}
}

template<class T>
void ArbolVL<T>::insertar(T elem)
{
	bool continuar = true;
	insertar(elem, raiz, continuar);
}


template<class T>
void ArbolVL<T>::mostrarInOrder()
{
	mostrarInOrder(raiz);
	cout << endl;
}

template<class T>
void ArbolVL<T>::mostrarPostOrder()
{
	mostrarPostOrder(raiz);
	cout << endl;
}

template<class T>
void ArbolVL<T>::mostrarPreOrder()
{
	mostrarPreOrder(raiz);
	cout << endl;
}

template<class T>
void ArbolVL<T>::mostrarInOrder(Nodo<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		mostrarInOrder(A->getIzquierda());
		cout << A->getDato() << ", " << A->getFactor() << endl;
		mostrarInOrder(A->getDerecha());
	}
}

template<class T>
void ArbolVL<T>::mostrarPostOrder(Nodo<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		mostrarPostOrder(A->getIzquierda());
		mostrarPostOrder(A->getDerecha());
		cout << A->getDato() << ", " << A->getFactor() << endl;
	}
}

template<class T>
void ArbolVL<T>::mostrarPreOrder(Nodo<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		cout << A->getDato() << ", " << A->getFactor() << endl;
		mostrarPreOrder(A->getIzquierda());
		mostrarPreOrder(A->getDerecha());
	}
}

template<class T>
int ArbolVL<T>::Contar()
{
	int num = 0;
	Contar(raiz, num);
	return num;
}

template<class T>
void ArbolVL<T>::Contar(Nodo<T>* A, int& num)
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
int ArbolVL<T>::Altura()
{
	int num = 0, tot = 0;
	Contar(raiz, num);
	tot = log(num) + 1;
	return tot + 1;
}

template<class T>
int ArbolVL<T>::Altura2(Nodo<T>* A)
{
	if (A == NULL)
	{
		return 0;
	}
	else
	{
		if (Altura2(A->getIzquierda()) > Altura2(A->getDerecha()))
		{
			return Altura2(A->getIzquierda()) + 1;
		}
		else
		{
			return Altura2(A->getDerecha()) + 1;
		}
	}
}

template<class T>
int ArbolVL<T>::Altura2()
{
	int num = 0;
	num = Altura2(raiz);
	return num;
}

template<class T>
bool ArbolVL<T>::Buscar(T dato)
{
	bool encontrado = false;
	Buscar(dato, raiz, encontrado);
	return encontrado;
}

template<class T>
void ArbolVL<T>::Buscar(T dato, Nodo<T>* A, bool& encontrado)
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
		}
		Buscar(dato, A->getIzquierda(), encontrado);
		Buscar(dato, A->getDerecha(), encontrado);
	}
}

template<class T>
bool ArbolVL<T>::Buscar2(T dato)
{
	bool encontrado = false;
	encontrado = Buscar2(raiz,dato);
	return encontrado;
}

template<class T>
bool ArbolVL<T>::Buscar2(Nodo<T>* A, T elementoBuscar)
{
	if (A == NULL)
	{
		return false;
	}
	else if (A->getDato() == elementoBuscar)
	{
		return true;
	}
	else if (elementoBuscar < A->getDato())
	{
		return Buscar2(A->getIzquierda(), elementoBuscar);
	}
	else
	{
		return Buscar2(A->getDerecha(), elementoBuscar);
	}
}