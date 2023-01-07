

#include <iostream>
#include <fstream>

#include "Arbol.h"

void leerDeArchivo(Arbol<int>& arbolBinario)
{
	ifstream archi;
	int numerosArchivo;

	//usar animales para 3000+ 
	//usar animalesCorto para 100
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




int main()
{
	Arbol<int> arbolBinario;
	leerDeArchivo(arbolBinario);
	cout << "mostrando nivel 1" << endl;
	arbolBinario.mostrarNivel(1);
	cout << endl;
	cout << "mostrando nivel 2" << endl;
	arbolBinario.mostrarNivel(2);
	cout << endl;
	cout << "mostrando nivel 3" << endl;
	arbolBinario.mostrarNivel(3);
	cout << endl;
	cout<<arbolBinario.Contar() << endl;
	//arbolBinario.eliminar(2148);
	//arbolBinario.mostrarNivel(1);
	//arbolBinario.mostrarNivel(2);
}

/*
int main()
{
	Arbol<int> arbolBinario;
	for (int i = 1; i < 100000; i++)
	{
		arbolBinario.insertar(i);
	}
}*/
/*
int main()
{
	Arbol<int> arbolBinario;
	arbolBinario.insertar(4);
	arbolBinario.insertar(2);
	arbolBinario.insertar(1);
	arbolBinario.insertar(3);
	arbolBinario.insertar(6);
	arbolBinario.insertar(5);
	arbolBinario.insertar(7);
	/*arbolBinario.recorrerInOrder();
	cout << endl;
	arbolBinario.recorrerPostOrder();
	cout << endl;
	arbolBinario.recorrerPreOrder();
	cout << endl;
	cout << "buscar 7, imprimir 1 si esta 0 sino" << endl;
	cout << arbolBinario.Buscar(7) << endl;
	cout << "buscar 10, imprimir 1 si esta 0 sino" << endl;
	cout << arbolBinario.Buscar(10) << endl;
	cout << "buscar menor" << endl;
	cout << arbolBinario.Menor() << endl;
	cout << "buscar mayor" << endl;
	cout << arbolBinario.Mayor() << endl;
	cout << "contar nodos" << endl;
	cout << arbolBinario.Contar() << endl;
	cout << "calcular altura" << endl;
	cout << arbolBinario.Altura() << endl;
	cout << "mostrar menores a 5" << endl;
	arbolBinario.mostrarMenoresANumero(5);
	cout << endl;
	cout << "mostrando arbol viejo" << endl;
	arbolBinario.mostrarNivel(1);
	arbolBinario.mostrarNivel(2);
	arbolBinario.mostrarNivel(3);
	cout << endl;
	bool res, Enc_Sig;
	int sig;
	cout << "numero existente" << endl;
	tie(sig, res, Enc_Sig) = arbolBinario.siguiente(5);
	cout << sig <<"  " << res<<"    " << Enc_Sig << endl;
	cout << "numero final" << endl;
	tie(sig, res, Enc_Sig) = arbolBinario.siguiente(7);
	cout << sig << "  " << res << "    " << Enc_Sig << endl;
	cout << "numero -1" << endl;
	tie(sig, res, Enc_Sig) = arbolBinario.siguiente(-1);
	cout << sig << "  " << res << "    " << Enc_Sig << endl;
	
	cout << "eliminando 4" << endl;
	cout<<arbolBinario.eliminar(4)<<endl;
	cout << "mostrando arbol nuevo" << endl;
	arbolBinario.mostrarNivel(1);
	arbolBinario.mostrarNivel(2);
	arbolBinario.mostrarNivel(3);
	//cout << arbolBinario.Contar() << endl;
}*/
