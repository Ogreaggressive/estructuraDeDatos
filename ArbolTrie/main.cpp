
#include "Trie.h"

int main()
{
	Trie arbolTrie;
	vector<char> palabra;
	palabra.push_back('n');
	palabra.push_back('i');
	palabra.push_back('c');
	palabra.push_back('o');
	palabra.push_back('l');
	palabra.push_back('a');
	palabra.push_back('s');

	vector<char> palabra2;
	palabra2.push_back('c');
	palabra2.push_back('h');
	palabra2.push_back('a');
	palabra2.push_back('d');

	arbolTrie.insertarA(palabra);
	cout << arbolTrie.buscarPalabra(palabra) << endl;
	cout << arbolTrie.buscarPalabra(palabra2) << endl;
	arbolTrie.insertarA(palabra2);
	arbolTrie.mostrar(palabra);
	arbolTrie.mostrar(palabra2);
	return 0;
}

