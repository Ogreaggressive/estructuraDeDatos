
#include <iostream>

#include "Lista.h"
#include "Cliente.h"

int main()
{
	
	Lista<Cliente> clientes(10);
	Cliente* c1 = new Cliente(1, "Azul");
	Cliente* c2 = new Cliente(2, "Verde");
	Cliente* c3 = new Cliente(3, "Rojo");
	Cliente* c4 = new Cliente(4, "Amarillo");
	Cliente* c5 = new Cliente(5, "Negro");
	Cliente* c6 = new Cliente(6, "Blanco");
	Cliente* c7 = new Cliente(7, "celeste");
	Cliente* c8 = new Cliente(8, "morado");

	Cliente* clienteABuscar = new Cliente(3);
	
	
	/*clientes.addFront(c3);
	clientes.addFront(c4);
	clientes.addBack(c2);
	clientes.addBack(c1);
	clientes.addFront(c5);
	clientes.addBack(c6);
	clientes.deleteFront();
	clientes.deleteBack();*/

	clientes.addFront(c1);
	clientes.addFront(c2);
	clientes.addBack(c3);
	clientes.addBack(c4);
	clientes.addFront(c5);
	clientes.addBack(c6);

	
	//mostrarClientes
	clientes.mostrar(Cliente::mostrar);
	/*
	cout << "buscar clientes forma 1-----" << endl;
	//Buscar Clientes forma 1
	clientes.busquedaSecuencialNoRecursiva(clienteABuscar)->mostrar();
	//Buscar Clientes forma 2
	cout << "buscar clientes forma 2-----" << endl;
	Cliente* clienteEncontrado2 = clientes.busquedaSecuencialRecursiva(clienteABuscar);
	clienteEncontrado2->mostrar();

	cout << "encontrar menor CI-----" << endl;
	clientes.menorLista(Cliente::cmpCiAsc)->mostrar();
	*/
	//Buscar Clientes forma 3

	cout << "ahora ordenado-----" << endl;
	clientes.ordenar(Cliente::cmpCiAsc);
	clientes.mostrar(Cliente::mostrar);

	cout << "busqueda binaria forma facil-----" << endl;
	clientes.BusquedaBinaria(clienteABuscar)->mostrar();
	

	//clientes.mostrar(Cliente::mostrar);
	
	
	
	//probar el caso busqueda binaria
	/*
	clientes.addFront(c8);
	clientes.addBack(c7);
	clientes.addBack(c6);
	clientes.addBack(c5);
	clientes.addBack(c4);
	clientes.addBack(c3);
	clientes.addBack(c2);
	clientes.addBack(c1);
	clientes.BusquedaBinaria(clienteABuscar)->mostrar();
	*/
	return 0;
}

