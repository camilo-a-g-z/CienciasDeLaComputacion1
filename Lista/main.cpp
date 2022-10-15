#include <iostream>
#include "Lista.h"

using namespace std;

int main(int argc, char** argv) {
	//template < class T >  
	
	Lista<int> enteros ;
	Lista<float> reales;
	Lista<char> caracteres;
	enteros.Insertar(6,1);
	enteros.Insertar(9,1);
	enteros.Insertar(3,2);
	enteros.Insertar(12,4);
	enteros.Insertar(10,4);	
	enteros.mostrar();
	enteros.Eliminar(2);
	cout<<enteros.TamLista()<<" Dato 3: "<<enteros.ObtenerDatos(3) <<endl;
	enteros.mostrar();
	
	reales.Insertar(6.2,1);
	reales.Insertar(9.5,1);
	reales.Insertar(3.8,2);
	reales.Insertar(12.0,4);
	reales.Insertar(10.9,4);
	reales.Eliminar(2);
	cout<<reales.TamLista()<<" Dato 3: "<<reales.ObtenerDatos(3) <<endl;
	reales.mostrar();
	
	caracteres.Insertar('a',1);
	caracteres.Insertar('c',2);
	caracteres.Insertar('f',2);
	caracteres.Insertar('m',4);
	caracteres.Insertar('p',3);
	caracteres.Eliminar(2);
	cout<<enteros.TamLista()<<" Dato 3: "<<caracteres.ObtenerDatos(3) <<endl;
	caracteres.mostrar();
	return 0;
}

