#include "Tupla.h"

Tupla::Tupla()
{
}

Tupla::~Tupla()
{
}

void Tupla::insertarPalabra(string palabra)
{
	arbolBB.insertar(palabra);
}

void Tupla::tituloLibro(string t)
{
	titulo = t;
}

string Tupla::getTitulo()
{
	return titulo;
}

ABB<string> Tupla::getArbol()
{
	return arbolBB;
}