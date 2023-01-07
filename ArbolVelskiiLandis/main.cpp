#include "ArbolVL.h"
#include "timer.h"

#include <set>
#include <fstream>
#include <iterator>

void leerDeArchivo(ArbolVL<int>& arbolBinario)
{
    ifstream archi;
    int numerosArchivo;
    archi.open("10000_Numeros.txt");

    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof() && archi >> numerosArchivo)
        {
            arbolBinario.insertar(numerosArchivo);
        }
    archi.close();
}

void leerDeArchivoSET(set<int>& s1)
{
    ifstream archi;
    int numerosArchivo;
    archi.open("10000_Numeros.txt");

    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof() && archi >> numerosArchivo)
        {
            s1.insert(numerosArchivo);
        }
    archi.close();
}

int main()
{
    timer reloj1, reloj2,reloj3,reloj4;
    set<int> s1;
    ArbolVL<int> arbol1;
    reloj1.start();
    leerDeArchivo(arbol1);
    reloj1.stop();
    reloj2.start();
    leerDeArchivoSET(s1);
    reloj2.stop();
    cout << " Tiempo en leer de archivo usando ArbolVL: " << reloj1 << " segundos" << endl;
    cout << " Tiempo en leer de archivo usando set: " << reloj2 << " segundos" << endl;
    reloj3.start();
    bool encontrado;
    for (int i = 0; i < 10000000; i++)
    {
        encontrado = arbol1.Buscar2(rand()%10000);
    }
    reloj3.stop();
    reloj4.start();
    for (int j = 0; j < 10000000; j++)
    {
        s1.find(rand()%10000);
    }
    reloj4.stop();
    cout << " Tiempo en leer 10 millones usando ArbolVL: " << reloj3 << " segundos" << endl;
    cout << " Tiempo en leer 10 millones usando set: " << reloj4 << " segundos" << endl;
    return 0;
}