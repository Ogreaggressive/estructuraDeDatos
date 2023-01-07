#pragma once
#include "nodo.h"

class Trie
{
private:
	nodo* raiz;
public:
	Trie();
	~Trie();
	void insertarA(vector<char> palabra);
	bool buscarPalabra(vector<char> palabra);
	void mostrar(vector<char> palabra);
};

Trie::Trie()
{
	raiz = new nodo();
}

Trie::~Trie()
{
}

void Trie::insertarA(vector<char> palabra)
{
	raiz->insertar(palabra, raiz);
}

bool Trie::buscarPalabra(vector<char> palabra)
{
	return raiz->buscar(palabra, raiz);
}

void Trie::mostrar(vector<char> palabra)
{
	raiz->mostrar(palabra, raiz);
}

