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
	cout << ci << endl;
}

bool Cliente::operator==(Cliente* cliente)
{
	return ci == cliente->ci;
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

int Cliente::getCi(Cliente* cliente)
{
	if (cliente != NULL)
	{
		return cliente->getCi();
	}
}


int Cliente::transformarStringAInt()
{
	int tot=0;
	int cont = 0;
	while ( cont!=nombre.length())
	{
		tot = tot + (int(nombre.at(cont))*2^tot);
		cont++;
	}
	return tot;
}

int Cliente::getTot(Cliente* cliente)
{
	if (cliente != NULL)
	{
		return cliente->transformarStringAInt();
	}
}
