#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector < int > datos(10);
	datos.push_back(20); // se insertan elementos en el final
	datos.push_back(48);
	datos.push_back(17);
	datos.push_back(5);
	datos.push_back(36);
	datos.push_back(12);
	for (unsigned i = 0; i < datos.size(); ++i)
		cout << datos[i] << endl; // mostrar por pantalla


	//vector <char> valores(1000000000000);
	//char array[1000000];
	return 0;
}