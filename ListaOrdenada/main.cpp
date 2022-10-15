#include <iostream>
#include "ListaOrdenada.h"

using namespace std;

int main(int argc, char** argv) {
	//template < class T >  
	
	Lista<int> enteros ;
	Lista<float> reales;
	Lista<char> caracteres;
	enteros.Insertar(6);
	enteros.Insertar(9);
	enteros.Insertar(3);
	enteros.Insertar(12);
	enteros.Insertar(10);	
	enteros.mostrar();
	enteros.Eliminar(2);
	cout<<enteros.TamLista()<<" Dato 3: "<<enteros.ObtenerDatos(3) <<endl;
	enteros.mostrar();
	
	reales.Insertar(6.2);
	reales.Insertar(9.5);
	reales.Insertar(3.8);
	reales.Insertar(12.0);
	reales.Insertar(10.9);
	reales.Eliminar(2);
	cout<<reales.TamLista()<<" Dato 3: "<<reales.ObtenerDatos(3) <<endl;
	reales.mostrar();
	
	caracteres.Insertar('a');
	caracteres.Insertar('c');
	caracteres.Insertar('f');
	caracteres.Insertar('m');
	caracteres.Insertar('p');
	caracteres.Eliminar(2);
	cout<<enteros.TamLista()<<" Dato 3: "<<caracteres.ObtenerDatos(3) <<endl;
	caracteres.mostrar();
	return 0;
}

