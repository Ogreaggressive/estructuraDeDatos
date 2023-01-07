#pragma once

#include <sstream>
#include <iostream>
using namespace std;

class ListaVaciaException : public exception
{
private:
	string mensaje;
public:
	ListaVaciaException() {
		stringstream ss;
		ss << "por favor revisar si hay datos o queda espacio en la lista";
		mensaje = ss.str();
	}
	const char* what() const throw ()
	{
		return mensaje.c_str();
	}
};

