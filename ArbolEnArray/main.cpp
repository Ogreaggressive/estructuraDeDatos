
#include <iostream>
#include <fstream>
#include "Arbol.h"

void leerDeArchivo(Arbol<int>& arbolBinario)
{
	ifstream archi;
	int numerosArchivo;
	int padreArchivo;

	archi.open("numeros.txt");

	if (!archi)
		cout << "No se puede abrir";
	else
		while (!archi.eof() && archi >> numerosArchivo>>padreArchivo)
		{
			arbolBinario.insertar(numerosArchivo,padreArchivo);
		}
	archi.close();
}
/*
int main()
{
	Arbol<int> arbolBinario;
	int pos = 1;
	arbolBinario.insertar(6, NULL);
	arbolBinario.insertar(3,6);
	arbolBinario.insertar(7, 6);
	
	
	/*arbolBinario.insertar(6, NULL);
	arbolBinario.insertar(3,6);
	arbolBinario.insertar(7, 6);
	arbolBinario.insertar(2, 3);
	arbolBinario.insertar(5, 3);
	arbolBinario.insertar(8, 7);
	
	cout << "cantidad de nodos:" << endl;
	cout<<arbolBinario.contar()<<endl;
	cout << "calcular altura:" << endl;
	cout << arbolBinario.calcularAltura() << endl;
	cout << "recorrer in orden:" << endl;
	arbolBinario.recorrerInOrder();
	cout << "recorrer Post orden:" << endl;
	arbolBinario.recorrerPostOrder();
	cout << "recorrer Pre orden:" << endl;
	arbolBinario.recorrerPreOrder();
	return 0;
}*/
int main()
{
	Arbol<int> arbolBinario;
	leerDeArchivo(arbolBinario);
	cout << endl;
	cout << "imprimir valores" << endl;
	arbolBinario.recorrerInOrder();
}

