#include "PalabraLibro.h"

PalabraLibro::PalabraLibro(int ci, string nombre)
{
	this->ci = ci;
	if (nombre.back() == '.' || nombre.back() == ',' || nombre.back() == ';' || nombre.back() == ':')
	{
		this->nombre = nombre.substr(0,nombre.size()-1);
	}
	else
	{
		this->nombre = nombre;
	}
	/*wstring widestr = wstring(nombre.begin(), nombre.end());
	const wchar_t* cambioPalabra = widestr.c_str();
	palabrasUnicode = cambioPalabra;*/
}

PalabraLibro::PalabraLibro(string nombre)
{
	this->nombre = nombre;
}

PalabraLibro::PalabraLibro()
{

}

PalabraLibro::~PalabraLibro()
{

}

int PalabraLibro::getCi()
{
	return ci;
}

string PalabraLibro::getNombre()
{
	return nombre;
}

void PalabraLibro::mostrar()
{
	cout << "PalabraLibro:" << endl;
	cout << "ci: " << ci << endl;
	cout << "nombre: " << nombre << endl;
}

void PalabraLibro::mostrarPalabra()
{
	/*wstring widestr = wstring(nombre.begin(), nombre.end());
	const wchar_t* palabrasUnicode = widestr.c_str();
	wcout << palabrasUnicode << endl;*/
	cout << nombre;
}

bool PalabraLibro::operator==(PalabraLibro* PalabraLibro)
{
	return nombre == PalabraLibro->nombre;
}

void PalabraLibro::mostrar(PalabraLibro* PalabraLibro)
{
	if (PalabraLibro != NULL)
	{
		PalabraLibro->mostrar();
	}
}

void PalabraLibro::mostrarPalabra(PalabraLibro* PalabraLibro)
{
	if (PalabraLibro != NULL)
	{
		PalabraLibro->mostrarPalabra();
	}
}

int PalabraLibro::getCi(PalabraLibro* PalabraLibro)
{
	if (PalabraLibro != NULL)
	{
		return PalabraLibro->getCi();
	}
}


int PalabraLibro::transformarstringAInt()
{
	double tot = 0;
	int cont = 0;
	
	char* palabrasUnicode = new char[nombre.length()];
	strcpy_s(palabrasUnicode, nombre.length() + 1, nombre.c_str());

	/*wstring widestr = wstring(nombre.begin(), nombre.end());
	const wchar_t* palabrasUnicode = widestr.c_str();*/
	//palabrasUnicode = (wchar_t*)malloc(sizeof(wchar_t) * 100);

	while (cont != nombre.length())
	{
		if (palabrasUnicode[cont] != '.' && palabrasUnicode[cont] != ',' && palabrasUnicode[cont] != ';'
			&& palabrasUnicode[cont] != ':')
		{
			tot = tot + (int(palabrasUnicode[cont]) * (2 ^ cont));
		}
		cont++;
	}
	return abs(tot);
}

int PalabraLibro::getTot(PalabraLibro* PalabraLibro)
{
	if (PalabraLibro != NULL)
	{
		return PalabraLibro->transformarstringAInt();
	}
}
