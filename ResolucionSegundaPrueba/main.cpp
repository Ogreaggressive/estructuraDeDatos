#include <iostream>
#include<vector>
#include <fstream>
#include "Tupla.h"

/*
#define titulo1 "poemaAlfonsina.txt"
#define titulo2 "poemaNeruda.txt"
#define titulo3 "poemaBecquer.txt"
#define titulo4 "poemaAlfonsina.txt"
*/
using namespace std;

void mostrarListaLibros(vector<Tupla> ListaLibros)
{
    
    for (int i = 0; i < ListaLibros.size(); i++)
    {
        cout<<"nombre Libro: "<<ListaLibros[i].getTitulo()<<endl;
        ListaLibros[i].getArbol().recorrerInOrder();
        cout << endl;
    }
}

void insertarEnLibro(vector<Tupla>& ListaLibros, string titulo, string palabra)
{
    for (int i = 0; i < ListaLibros.size(); i++)
    {
        if (ListaLibros[i].getTitulo() == titulo)
        {
            ListaLibros[i].insertarPalabra(palabra);
        }
    }
}

void BuscarEnLibro(vector<Tupla>& ListaLibros, string palabra)
{
    for (int i = 0; i < ListaLibros.size(); i++)
    {
          cout << "en libro " << i+1 << endl;
          cout<<"palabra:"<<palabra<<" veces:"<< ListaLibros[i].getArbol().Buscar(palabra)<<endl;
    }
}

void leerDeArchivo(vector<Tupla>& ListaLibros,string titulo,int numLibro)
{
    ifstream archi;
    string palabras;

    if (numLibro == 1)
    {
        archi.open("poemaZamudio.txt");
    }
    if (numLibro == 2)
    {
        archi.open("poemaNeruda.txt");
    }
    if (numLibro == 3)
    {
        archi.open("poemaBecquer.txt");
    }
    if (numLibro == 4)
    {
        archi.open("poemaAlfonsina.txt");
    }
    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof() && archi >> palabras)
        {
            insertarEnLibro(ListaLibros,titulo,palabras);
        }
    archi.close();
}

int main()
{
    vector<Tupla> ListaLibros;
    Tupla poema1,poema2,poema3,poema4;

    poema1.tituloLibro("poema1");
    ListaLibros.push_back(poema1);
    poema2.tituloLibro("poema2");
    ListaLibros.push_back(poema2);
    poema3.tituloLibro("poema3");
    ListaLibros.push_back(poema3);
    poema4.tituloLibro("poema4");
    ListaLibros.push_back(poema4);

    leerDeArchivo(ListaLibros,"poema1",1);
    leerDeArchivo(ListaLibros, "poema2", 2);
    leerDeArchivo(ListaLibros, "poema3", 3);
    leerDeArchivo(ListaLibros, "poema4", 4);
    //insertarEnLibro(ListaLibros, "comida", "Hamburguesa"); 
    mostrarListaLibros(ListaLibros);
    BuscarEnLibro(ListaLibros, "golondrinas");
    BuscarEnLibro(ListaLibros, "soledad");
    BuscarEnLibro(ListaLibros, "de");
    //golondrina 1, soledad 2
    return 0;
}

/*
int main()
{
    vector<Tupla> ListaLibros;
    Tupla libro1, libro2;

    libro1.tituloLibro("comida");
    ListaLibros.push_back(libro1);
    libro2.tituloLibro("juegos");
    ListaLibros.push_back(libro2);

    insertarEnLibro(ListaLibros, "comida", "Hamburguesa");
    insertarEnLibro(ListaLibros, "comida", "Pizza");
    insertarEnLibro(ListaLibros, "juegos", "Lol");
    insertarEnLibro(ListaLibros, "juegos", "Dota");
    insertarEnLibro(ListaLibros, "juegos", "Osu");
    insertarEnLibro(ListaLibros, "juegos", "Depresion");
    insertarEnLibro(ListaLibros, "juegos", "Depresion");
    insertarEnLibro(ListaLibros, "juegos", "Depresion");

    mostrarListaLibros(ListaLibros);
    BuscarEnLibro(ListaLibros,"Depresion");
    return 0;
}*/