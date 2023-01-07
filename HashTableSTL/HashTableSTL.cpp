// compiler settings check "Have g++follow the C++11 iso.."
// unordered_map
/*
#include <unordered_map>
#include <iostream>
using namespace std;

void printFrequencies()
{

    unordered_map<string, int> HashT;
    unordered_map<string, int>::iterator p;

    string word = "hola";
    HashT[word]++;
    HashT[word]++;
    word = "chau";
    HashT[word]++;

    for (p = HashT.begin(); p != HashT.end(); p++)
        cout << "(" << p->first << ", " << p->second << ")\n";
}


int main()
{
    printFrequencies();
    return 0;
}*/


#include <iostream>
#include <list>
#include <fstream>
#include <utility>
#include <iterator>
using namespace std;

//function for printing the elements in a list
void showlist(list <int> g)
{
    list <int> ::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

template<class T>
void listaDoble(list<list<string>> g)
{
    /*list <pair<string, list<string>>> LL;
   list <pair<string, list<string>>>::iterator it;*/
   pair <string, list<string>> TipoLista;
    list <TipoLista> ListaListas;
}

int main()
{
   
    list<string> L{"calculo", "fisica", "estructura"};
    list<string> L1{ "pedro", "juan", "rosa","Maria","julieta","jose","carmen","lucas"};
    list<list<string>> LL;

    LL.push_back(L);
    LL.push_back(L1);

    list<list<string>>::iterator itr;


    for (itr = LL.begin(); itr != LL.end(); ++itr)
    {
        list<string>tl = *itr;
        list<string>::iterator it;
        for (it = tl.begin(); it != tl.end(); ++it)
        {
            cout << '\t' << *it;
        }
        cout << endl;
    }

    pair <string, list<string>> TipoLista;
    TipoLista.first("calculo");

    return 0;
}

/*list<list<string>>
  list< pair<string, list<string> > LL;
 list< pair<string, list<string> >::iterator it;*/
/*
#include <iostream>
#include <utility>
using namespace std;

int main()
{
    pair<int, char> PAIR1;

    PAIR1.first = 100;
    PAIR1.second = 'G';

    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;

    return 0;
}*/

/*
list<list<string>>
list < pair<string, list<string> > LL;
list < pair<string, list<string> >::iterator it;*/