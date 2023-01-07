
#include <iostream>
#include <fstream>

#include "Lista8.h"
#include "Cliente.h"

void leerDeArchivo(Lista8<Cliente> &clientes)
{
	ifstream archi;
	int numerosArchivo;

	//usar animales para 3000+ 
	//usar animalesCorto para 100
	archi.open("10000_Numeros.txt");

	if (!archi)
		cout << "No se puede abrir";
	else
		while (!archi.eof() && archi >> numerosArchivo)
		{
			clientes.addFront(new Cliente(numerosArchivo, "num"));
		}
	archi.close();
}


int main()
{
	Lista8<Cliente> clientes;
	leerDeArchivo(clientes);
	clientes.mostrar(Cliente::mostrarNum);
	cout << "ahora invertido---------------------------------------------------------------------------" << endl;
	clientes.invertirSobreSiMisma();
	clientes.mostrar(Cliente::mostrarNum);
	return 0;
}




//cosas antes de la defensa
/*
	Lista8<Cliente> clientes;
	Cliente* c1 = new Cliente(1, "Azul");
	Cliente* c2 = new Cliente(2, "Verde");
	Cliente* c3 = new Cliente(3, "Rojo");
	Cliente* c4 = new Cliente(4, "Amarillo");
	Cliente* c5 = new Cliente(5, "Negro");
	Cliente* c6 = new Cliente(6, "Blanco");
	Cliente* c7 = new Cliente(7, "celeste");
	Cliente* c8 = new Cliente(8, "morado");

	Cliente* clienteABuscar = new Cliente(3);

	clientes.addFront(c3); //pos 1
	clientes.addFront(c4); //pos 2
	clientes.addBack(c2); //pos 0
	clientes.addBack(c1); //borra c1->azul
	clientes.addFront(c5); //pos 3
	clientes.addFront(c6); //borra c6 ->blanco
	clientes.deleteFront();
	clientes.deleteBack();

	clientes.mostrar(Cliente::mostrar);

	cout << "buscar clientes forma 1-----" << endl;
	//Buscar Clientes forma 1
	clientes.busquedaSecuencialNoRecursiva(clienteABuscar)->mostrar();
	//Buscar Clientes forma 2
	cout << "buscar clientes forma 2-----" << endl;
	Cliente* clienteEncontrado2 = clientes.busquedaSecuencialRecursiva(clienteABuscar);
	clienteEncontrado2->mostrar();
	//menor de los clientes
	cout << "encontrar menor CI-----" << endl;
	clientes.menorLista(Cliente::cmpCiAsc)->mostrar();
	cout << "encontrar Iesima posicion-----" << endl;
	cout << "buscando posicion 2-----" << endl;
	clientes.buscarIesimaPosicion(2)->mostrar();
	*/