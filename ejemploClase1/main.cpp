#include <iostream>
#include <fstream>
#include <iterator>
#include "timer.h"
#include <set> // para set y multiset


#include "Animal.h"
#include "Animales.h"
using namespace std;


int main()
{
    timer reloj1, reloj2,reloj3,reloj4;

    Animales lista;
    Animal* listaCopia1[5000];
    Animal* listaCopia2[5000];

    reloj1.start();
    lista.leerDeArchivo();
    reloj1.stop();

    reloj2.start();
    lista.copiarLista(listaCopia1);
    reloj2.stop();
    lista.copiarLista(listaCopia2);

    reloj3.start();
    lista.ordenarBurbujaEdad2(listaCopia1);
    reloj3.stop();
    //lista.mostrarLista(listaCopia1);
    cout << "--------------------------------------------------------------------------" << endl;

    reloj4.start();
    lista.ordenarMergeEdad(listaCopia2,0,lista.getTam()-1);
    reloj4.stop();
    //lista.mostrarLista(listaCopia2);
    cout << " Tiempo en leer de archivo: " << reloj1 << " segundos" << endl;
    cout << " Tiempo en copiar lista: " << reloj2 << " segundos" << endl;
    cout << " Tiempo en metodo burbuja con SET: " << reloj3 << " segundos" << endl;
    cout << " Tiempo en metodo merge con SET: " << reloj4 << " segundos" << endl;
}