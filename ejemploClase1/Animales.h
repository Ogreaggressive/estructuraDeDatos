#include "Animal.h"
#include <fstream>

#define TAM 5000

class Animales
{
private:
	Animal* vectorAnimales[TAM];
	int tam;
public:
	Animales();
	~Animales();
	void leerDeArchivo();
	void mostrar(); //para mostrar la lista dentro de animales
	void mostrarLista(Animal* listaCopia[TAM]); //para mostrar cualquier lista creada
	void copiarLista(Animal* listaCopia[TAM]);
	void ordenarBurbujaEdad(); //mostrar vector original
	void ordenarBurbujaEdad2(Animal* listaCopia[TAM]); //mostrar cualquier vector copiado
	void ordenarMergeEdad(Animal* listaCopia[TAM],int const begin, int const end);
	int getTam();
};





