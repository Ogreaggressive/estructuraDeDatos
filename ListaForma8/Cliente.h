#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cliente
{
private:
	int ci;
	string nombre;
public:
	Cliente(int ci, string nombre);
	Cliente(int ci);
	Cliente();
	~Cliente();
	int getCi();
	string getNombre();
	void mostrar();
	void mostrarNum();
	bool operator==(Cliente* cliente);
	bool operator>(Cliente* cliente);
	static bool cmpCiAsc(Cliente* c1, Cliente* c2);
	static bool cmpCiDes(Cliente* c1, Cliente* c2);
	static void mostrar(Cliente* cliente);
	static void mostrarNum(Cliente* cliente);
};

