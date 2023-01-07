#include "Cliente.h"

Cliente::Cliente(int ci, string nombre)
{
	this->ci = ci;
	this->nombre = nombre;
}

Cliente::Cliente(int ci)
{
	this->ci = ci;
}


Cliente::Cliente()
{

}

Cliente::~Cliente()
{

}

int Cliente::getCi()
{
	return ci;
}

string Cliente::getNombre()
{
	return nombre;
}

void Cliente::mostrar()
{
	cout << "Cliente:" << endl;
	cout << "Ci: " << ci << endl;
	cout << "nombre: " << nombre << endl;
}

void Cliente::mostrarNum()
{
	cout << nombre << endl;
}

bool Cliente::operator==(Cliente* cliente)
{
	return nombre.compare(cliente->nombre);
}

bool Cliente::operator>(Cliente* cliente)
{
	return ci > cliente->ci;
}

bool Cliente::cmpCiAsc(Cliente* c1, Cliente* c2)
{
	return c1->ci > c2->ci;
}

bool Cliente::cmpCiDes(Cliente* c1, Cliente* c2)
{
	return c1->ci < c2->ci;
}

void Cliente::mostrar(Cliente* cliente)
{
	if (cliente != NULL)
	{
		cliente->mostrar();
	}
}

void Cliente::mostrarNum(Cliente* cliente)
{
	if (cliente != NULL)
	{
		cliente->mostrarNum();
	}
}

