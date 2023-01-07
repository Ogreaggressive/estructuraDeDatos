#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class PalabraLibro
{
private:
	int ci;
	string nombre;
	//const wchar_t* palabrasUnicode;
public:
	PalabraLibro(int ci, string nombre);
	PalabraLibro(string nombre);
	PalabraLibro();
	~PalabraLibro();
	int getCi();
	string getNombre();
	void mostrar();
	void mostrarPalabra();
	bool operator==(PalabraLibro* PalabraLibro);
	static void mostrar(PalabraLibro* PalabraLibro);
	static void mostrarPalabra(PalabraLibro* PalabraLibro);
	static int getCi(PalabraLibro* PalabraLibro);

	int transformarstringAInt();
	static int getTot(PalabraLibro* PalabraLibro);
};

