#include "Animal.h"

Animal::Animal(string nombre,int anioNacimiento, string raza)
{
	this->nombre = nombre;
	this->raza = raza;
	this->anioNacimiento = anioNacimiento;
}

Animal::~Animal()
{

}


void Animal::mostrar()
{
	//cout << "Animal:" << endl;
	cout << "nombre:" << nombre;
	cout << "           raza:" << raza;
	cout << "           anioNacimiento:" << anioNacimiento << endl;

}

int Animal::getEdad()
{
	return anioNacimiento;
}