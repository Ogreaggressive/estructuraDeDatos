#pragma once


#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
	string nombre;
	string raza;
	int anioNacimiento;
public:
	Animal(string nombre, int anioNacimiento, string raza);
	~Animal();

	int getEdad();

	void mostrar();
};











