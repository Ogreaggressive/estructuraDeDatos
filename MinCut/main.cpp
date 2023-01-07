#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <fstream>

#include <sstream>
#include <string>

using namespace std;

void leerDeArchivoAvanzado(map<int, list<int>> &grafo)
{
    ifstream archi;
    int numerosArchivo;

    //pruebaChiquita
    //test
    archi.open("Test.txt");
    string line;

    if (!archi)
        cout << "No se puede abrir";
    else
        while (getline(archi, line))
        {
            istringstream iss(line);
            int n;
            int inicio;
            iss >> inicio;

            while (iss >> n)
            {
                if (n != -1)
                {
                    grafo[inicio].push_back(n);
                }
            }
        }
    archi.close();
}

void mostrar(map<int, list<int>> grafo)
{
    for (auto it = grafo.cbegin(); it != grafo.cend(); ++it)
    {
        cout << it->first << ": ";

        for (auto it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2)
        {
            cout << (*it2)<<" ";
        }
        cout << endl;
    }
}
/*
void deleteGrafo2(map<int, list<int>>& grafo,int lugar ,int valor)
{

    for (list<int>::iterator it = grafo[lugar].begin(); it != grafo[lugar].end(); ++it)
    {
        if (*it == valor)
        {
            grafo[lugar].erase(it);
        }
    }
    list<int>::iterator i = grafo[lugar].begin();
while (i != grafo[lugar].end())
{
    if (*i == valor)
    {
        grafo[lugar].erase(i++);
    }
    else
    {
        i++;
    }
}

}*/

void deleteGrafo(map<int, list<int>>& grafo, int lugar, int valor)
{
    grafo[lugar].erase((find(grafo[lugar].begin(), grafo[lugar].end(), valor)));
}

void mostrarValor(map<int, list<int>>& grafo, int lugar, int valor)
{
    for (list<int>::iterator it = grafo[lugar].begin(); it != grafo[lugar].end(); ++it)
    {
        if (*it == valor)
        {
            cout<<valor<<endl;
        }
    }
}


void contraer(map<int, list<int>>& grafo, int v1, int v2)
{
    int ady;
    grafo[v1].remove(v2);
    grafo[v2].remove(v1);
    for (list<int>::iterator it = grafo[v2].begin(); it != grafo[v2].end(); it++)
    {
        grafo[*it].remove(v2);
        if (*it != v1)
        {
            grafo[v1].push_back(*it);
            grafo[*it].push_back(v1);
        }
    }
    grafo.erase(v2);
}

void azar(map<int, list<int>> grafo,int &v1, int &v2)
{
    map<int, list<int>>::iterator it;
    it = grafo.begin();
    int ind = rand() % grafo.size();
    advance(it, ind);
    v1 = it->first;
    list<int>::iterator itList;
    itList = grafo[v1].begin();
    int indice = rand() % grafo[v1].size();
    advance(itList, indice);
    v2 = *itList;
}

void eliminarAutoCiclos(map<int, list<int>>& grafo)
{
    int tam = grafo.size();
    for (int i = 0; i < tam; i++)
    {
        for (list<int>::iterator it = grafo[i].begin(); it != grafo[i].end(); ++it)
        {
            if (*it == i)
            {
                grafo[i].erase(it);
            }
        }  
    }
}

int minCut(map<int, list<int>> &grafo)
{
    while (grafo.size() > 2)
    {
        int rand1, rand2;
        azar(grafo, rand1, rand2);
        contraer(grafo, rand1, rand2);
    }
    map<int, list<int>>::iterator it = grafo.begin();
    return it->second.size();
}

int main()
{
    srand((unsigned)time(0));
    map<int, list<int>> grafoOri;
    map<int, list<int>> grafo;

    /*map<int, list<int>> prueba;
    prueba[0].push_back(1);
    prueba[0].push_back(2);
    prueba[1].push_back(0);
    prueba[1].push_back(2);
    prueba[1].push_back(3);
    prueba[2].push_back(0);
    prueba[2].push_back(1);
    prueba[2].push_back(3);
    prueba[3].push_back(1);
    prueba[3].push_back(2);*/

    leerDeArchivoAvanzado(grafoOri);
    //mostrar(grafoOri);

    int min = 10000;
    double tam = grafoOri.size();
    int  res =0;
    double n = 0;

    while (n < (tam * tam) * log10(tam))
        {
            grafo = grafoOri;
            res = minCut(grafo);
            cout << res << endl;
            if (res < min)
            {
                min = res;
            }
            n++;
        }
    cout << "el minimo es: " << min << endl;
    return 0;
}