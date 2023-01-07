#include "Animales.h"


Animales::Animales(): vectorAnimales()
{
    tam = 0;
}

Animales::~Animales()
{

}

void Animales::leerDeArchivo()
{
    ifstream archi;
    string nombre;
    string raza;
    int fechaNac;
    int i = 0;

    //usar animales para 3000+ 
    //usar animalesCorto para 100
    archi.open("animales.txt");

    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof()&& archi>>nombre>>fechaNac>>raza)
        {
            Animal* animal = new Animal(nombre, fechaNac, raza);
            vectorAnimales[i]=animal;
            i++;
        }

    archi.close();
    tam = i;
}

void Animales::mostrar()
{
    for (int i = 0; i < tam; i++)
    {
        vectorAnimales[i]->mostrar();
    }
}

void Animales::mostrarLista(Animal* listaCopia[TAM])
{
    for (int i = 0; i < tam; i++)
    {
        listaCopia[i]->mostrar();
    }
}

void Animales::copiarLista(Animal* listaCopia[TAM])
{
    for (int i = 0; i < tam; i++)
    {
        listaCopia[i]=vectorAnimales[i];
    }
}


void swap(Animal* xp, Animal* yp)
{
    Animal temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Animales::ordenarBurbujaEdad()
{
    int i, j;
    for (i = 0; i < tam - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < tam - i - 1; j++)
            if (vectorAnimales[j]->getEdad() > vectorAnimales[j + 1]->getEdad())
                swap(vectorAnimales[j], vectorAnimales[j + 1]);
}

void Animales::ordenarBurbujaEdad2(Animal* listaCopia[TAM])
{
    int i, j;
    for (i = 0; i < tam - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < tam - i - 1; j++)
            if (listaCopia[j]->getEdad() > listaCopia[j + 1]->getEdad())
                swap(listaCopia[j], listaCopia[j + 1]);
}


void merge(Animal* array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new Animal* [subArrayOne],
        * rightArray = new Animal* [subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]->getEdad() <= rightArray[indexOfSubArrayTwo]->getEdad()) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */

void Animales::ordenarMergeEdad(Animal* array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursivly

    auto mid = begin + (end - begin) / 2;
    ordenarMergeEdad(array, begin, mid);
    ordenarMergeEdad(array, mid + 1, end);
    merge(array, begin, mid, end);
}


int Animales::getTam()
{
    return tam;
}