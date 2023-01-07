
#include <iostream>
#include <fstream>
#include "Heap.h"

#include <list>
#include <iterator>

void leerDeArchivo(Heap<int>& arbol)
{
	ifstream archi;
	int numerosArchivo;
	archi.open("10000_Numeros.txt");

	if (!archi)
		cout << "No se puede abrir";
	else
		while (!archi.eof() && archi >> numerosArchivo)
		{
			if (numerosArchivo == 1)
			{
				//cout << "aaaaaaaaaaaaaaaaaaaaaaaa" << endl;
			}
			arbol.insertar(numerosArchivo);
		}
	archi.close();
}

void showlist(list <int> lista)
{
	list <int> ::iterator i;
	for (i = lista.begin(); i != lista.end(); ++i)
	{
		//cout << '\t' << *i;
		cout << *i << endl;
	}
	cout << endl;
}

void heapSort(Heap<int>& arbol, list <int> lista)
{
	for (int i = 0; i < 10000; i++)
	{
		lista.push_back(arbol.eliminarMayor());
	}
	showlist(lista);
}


int main()
{
	/*Heap<int> arbolHeap;
	arbolHeap.insertar(5);
	arbolHeap.insertar(7);
	arbolHeap.insertar(8);
	arbolHeap.insertar(6);

	cout<<"valor :"<<arbolHeap.eliminarMayor()<<" eliminado"<<endl;
	cout << "valor :" << arbolHeap.eliminarMayor() << " eliminado" << endl;
	cout << "valor :" << arbolHeap.eliminarMayor() << " eliminado" << endl;
	cout << "valor :" << arbolHeap.eliminarMayor() << " eliminado" << endl;

	arbolHeap.insertar(8);
	arbolHeap.insertar(3);
	arbolHeap.insertar(4);
	arbolHeap.insertar(5);

	arbolHeap.recorrerHeap();
	cout << "valor maximo :" << arbolHeap.getMayor() << endl;
	cout << "valor minimo :" << arbolHeap.getMenor() <<  endl;*/
	Heap<int> arbolHeap2;
	leerDeArchivo(arbolHeap2);
	//cout << "valor maximo :" << arbolHeap2.getMayor() << endl;
	//cout << "valor minimo :" << arbolHeap2.getMenor() << endl;
	//arbolHeap2.recorrerHeap();
	list <int> lista;
	heapSort(arbolHeap2,lista);
}


