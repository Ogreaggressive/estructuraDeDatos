
#include <iostream>
#include <fstream>

#include "ListaDeListas.h"
#include "Cabecera.h"
#include "Lista8.h"
#include "Cliente.h"

void leerDeArchivo(ListaDeListas<Cliente>& materias)
{
	ifstream archi;

	char nombres[20];

	string titulo;
	bool start = true;
	string estudiantes;
	Cliente* materia = new Cliente();
	//usar animales para 3000+ 
	//usar animalesCorto para 100
	archi.open("archivoClases.txt");

	if (!archi)
		cout << "No se puede abrir";
	else
		while (!archi.eof() && archi >> nombres)
		{
			if (strlen(nombres)<2 || strcmp(nombres,"start"))
			{
				titulo = nombres;
				Cliente* materia = new Cliente(1, titulo);
				start = false;
			}
			else
			{
				start = false;
				int i = 0;
				while (i < strlen(nombres))
				{
					if (isdigit(i) == true)
					{
						start = true;
					}
					i++;
				}
				if (start == false)
				{
					Cliente* estudiante = new Cliente(1, nombres);
					materias.addDatoEnLista(materia, estudiante);
				}
			}
		}
	archi.close();
}

/*
void leerDeArchivo2(ListaDeListas<Cliente>& materias)
{
	ifstream archi;

	string nombres;

	string titulo;
	bool start = true;
	bool EsNumero = true;
	Cliente* materia = new Cliente();
	Lista8<Cliente> materias;
	int num=10;

	archi.open("archivoClases.txt");

	if (!archi)
		cout << "No se puede abrir";
	else
		while (!archi.eof() && archi >> nombres)
		{

			if ((start == true))
			{
				titulo = nombres;
				materias.addBack(new Cliente(1, nombres));
				start = false;
				
			}
			else if (num > 0 && start == false && EsNumero == false)
			{
				Cliente* estudiante = new Cliente(1, nombres);
				materias.buscarRecursivamente();
				Cliente* materia = new Cliente(1, titulo);
				materias.addDatoEnLista(materia, estudiante);
				if (num == 1)
				{
					start = true;
					EsNumero = true;
				}
			}
			num = num - 1;
			if (nombres.length()==1)
			{
				num = stoi(nombres);
				EsNumero = false;
				
			}
		}
	archi.close();
}
*/

void leerDeArchivo3(ListaDeListas<string>& materias)
{
	ifstream archi;

	string nombres;
	string titulo;
	int cant;

	archi.open("archivoClases.txt");

	if (!archi)
		cout << "No se puede abrir";
	else
		while (!archi.eof())
		{
			archi >> titulo;
			archi >> cant;
			
			for (int i = 0; i < cant; i++)
			{
				archi >> nombres;
				materias.addDatoEnLista(titulo,nombres);
			}
		}
	archi.close();
}

int main()
{
    ListaDeListas<string> materias;

	/*Cliente* materia1 = new Cliente(1, "CALCULO");
	Cliente* materia2 = new Cliente(2, "FISICA");
	Cliente* materia3 = new Cliente(3, "ESTRUCTURA");
	Cliente* materia4 = new Cliente(2, "FISICA");

	Cliente* persona1 = new Cliente(155, "pedro");
	Cliente* persona2 = new Cliente(242, "juan");
	Cliente* persona3 = new Cliente(341, "rosa");
	Cliente* persona4 = new Cliente(412, "maria");
	Cliente* persona5 = new Cliente(823, "julieta");
	Cliente* persona6 = new Cliente(412, "jose");
	Cliente* persona7 = new Cliente(823, "carmen");
	Cliente* persona8 = new Cliente(823, "lucas");

	materias.addDatoEnLista(materia1, persona1);
	materias.addDatoEnLista(materia1,persona2);
	materias.addDatoEnLista(materia1, persona3);
	materias.addDatoEnLista(materia2, persona4);
	materias.addDatoEnLista(materia2, persona5);
	materias.addDatoEnLista(materia3, persona6);
	materias.addDatoEnLista(materia3, persona7);
	materias.addDatoEnLista(materia2, persona8);*/

	

	leerDeArchivo3(materias);

	//materias.mostrar(string::);
	return 0;
}
