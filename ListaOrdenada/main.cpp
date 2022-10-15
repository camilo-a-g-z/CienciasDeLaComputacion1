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
	cout<<"Lista completa: ";
	enteros.mostrar();
	cout<<"Se elimina un dato: "<<enteros.Eliminar(2)<<endl;
	cout<<"Tamaño: "<<enteros.TamLista()<<endl;
	cout<<"Lista actual: ";
	enteros.mostrar();
	
	cout<<endl;
	
	reales.Insertar(6.2);
	reales.Insertar(9.5);
	reales.Insertar(3.8);
	reales.Insertar(12.0);
	reales.Insertar(10.9);
	cout<<"Lista completa: ";
	reales.mostrar();
	cout<<"Se elimina un dato: "<<reales.Eliminar(3)<<endl;
	cout<<"Tamaño: "<<reales.TamLista()<<endl;
	cout<<"Lista actual: ";
	reales.mostrar();
	
	cout<<endl;
	
	caracteres.Insertar('a');
	caracteres.Insertar('c');
	caracteres.Insertar('f');
	caracteres.Insertar('m');
	caracteres.Insertar('p');
	cout<<"Lista completa: ";
	caracteres.mostrar();
	cout<<"Se elimina un dato: "<<caracteres.Eliminar(4)<<endl;
	cout<<"Tamaño: "<<caracteres.TamLista()<<endl;
	cout<<"Lista actual: ";
	caracteres.mostrar();
	return 0;
}

