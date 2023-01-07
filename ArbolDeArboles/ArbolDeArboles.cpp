#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void printTree(map<string, string> Arbol)
{
	map<string, string>::iterator it;
	for (it = Arbol.begin(); it != Arbol.end(); ++it)
	{
		cout << it->first << " => " << it->second << '\n';
	}
}

void printWord(map<string, string> Arbol, string palabra)
{
	map<string, string>::iterator it;
	for (it = Arbol.begin(); it != Arbol.end(); ++it)
	{
		if (it->second == palabra)
		{
			cout << it->second << " => " << it->first << '\n';
		}
	}	
}

void insertarIngles(map<string, string> &Arbol, string palabra, string traductor)
{
	Arbol[traductor] = palabra;
}


int main()
{
	map<string, string> ingles;
	map<string, string> aleman;
	map<string, string> frances;
	map<string, string>::iterator it;
	map<string, map<string, string> > traductor;
	pair<string, string> i;

	ingles["hi"] = "hola";
	ingles["eat"] = "comer";
	ingles["play"] = "jugar";
	ingles["sleep"] = "dormir";

	aleman["hallo"] = "hola";
	aleman["essen"] = "comer";
	aleman["spiel"] = "jugar";
	aleman["shlafen"] = "dormir";

	frances["bonjour"] = "hola";
	frances["manger"] = "comer";
	frances["jouer"] = "jugar";
	frances["dormir"] = "dormir";

	traductor.insert({ "ingles",ingles });
	traductor.insert({ "aleman",aleman });
	traductor.insert({ "frances",frances });

	for (auto it = traductor.cbegin(); it != traductor.cend(); ++it)
	{
		cout << it->first <<endl;
		printTree(it->second);
	}

	/*cout << "-----------------------" << endl;
	cout << "elija la palabra a insertar, el idioma a cual traduce y su traduccion" << endl;
	string palabra1,idioma1,traduccion1;
	cin >> palabra1;
	cin >> idioma1;
	cin >> traduccion1;
	if (idioma1 == "ingles")
	{
		ingles.insert({ traduccion1,idioma1 });
		//ingles[traduccion1] = idioma1;
		traductor.insert({ "ingles",ingles });
	}


	for (auto it = traductor.cbegin(); it != traductor.cend(); ++it)
	{
		cout << it->first << endl;
		printTree(it->second);
	}*/

	cout << "-----------------------" << endl;
	cout << "elija la palabra a traducir y el idioma a cual ser traducido" << endl;
	string idioma, palabra;
	cin >> palabra;
	cin >> idioma;
	for (auto it = traductor.cbegin(); it != traductor.cend(); ++it)
	{
		if (it->first == idioma)
		{
			printWord(it->second,palabra);
		}	
	}
}
