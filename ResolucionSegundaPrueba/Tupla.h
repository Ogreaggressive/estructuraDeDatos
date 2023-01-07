#pragma once

#include "ABB.h"

class Tupla
{
private:
	string titulo;
	ABB<string> arbolBB;
public:
	Tupla();
	~Tupla();
	void insertarPalabra(string palabra);
	void tituloLibro(string titulo);
	string getTitulo();
	ABB<string> getArbol();
};




