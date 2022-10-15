#include <iostream>
#include "ListaOrdenada.h"

using namespace std;

void presentacion();

int main(int argc, char** argv) {
	presentacion();
	return 0;
}

void presentacion(){
	/*
		Requerimientos: 
		Crear una lista de enteros, reales y carácteres.	*Hecho
		Llenar cada lista con 6 elementos.					*Hecho
		Imprimir la lista ordenada.							*Hecho
		Eliminar 2 o 3 elementos.
		Imprimir la nueva lista ordenada con dichos elementos eliminados	*Hecho
	*/
	Lista<int> enteros ;
	Lista<float> reales;
	Lista<char> caracteres;
	enteros.Insertar(6);
	enteros.Insertar(90);
	enteros.Insertar(3);
	enteros.Insertar(12);
	enteros.Insertar(10);	
	enteros.Insertar(11);	
	cout<<"Lista completa: ";
	enteros.mostrar();
	cout<<"Se elimina un dato: "<<enteros.Eliminar(2)<<endl;
	cout<<"Lista actual: ";
	enteros.mostrar();
	cout<<"Se elimina un dato: "<<enteros.Eliminar(1)<<endl;
	cout<<"Tamaño: "<<enteros.TamLista()<<endl;
	cout<<"Lista actual: ";
	enteros.mostrar();
	
	cout<<endl;
	
	reales.Insertar(6.2);
	reales.Insertar(9.5);
	reales.Insertar(3.8);
	reales.Insertar(12.0);
	reales.Insertar(10.9);
	reales.Insertar(1.1);
	cout<<"Lista completa: ";
	reales.mostrar();
	cout<<"Se elimina un dato: "<<reales.Eliminar(3)<<endl;
	cout<<"Lista actual: ";
	reales.mostrar();
	cout<<"Se elimina un dato: "<<reales.Eliminar(4)<<endl;
	cout<<"Tamaño: "<<reales.TamLista()<<endl;
	cout<<"Lista actual: ";
	reales.mostrar();
	
	cout<<endl;
	
	caracteres.Insertar('a');
	caracteres.Insertar('c');
	caracteres.Insertar('f');
	caracteres.Insertar('m');
	caracteres.Insertar('p');
	caracteres.Insertar('b');
	cout<<"Lista completa: ";
	caracteres.mostrar();
	cout<<"Se elimina un dato: "<<caracteres.Eliminar(4)<<endl;
	cout<<"Lista actual: ";
	caracteres.mostrar();
	cout<<"Se elimina un dato: "<<caracteres.Eliminar(1)<<endl;
	cout<<"Tamaño: "<<caracteres.TamLista()<<endl;
	cout<<"Lista actual: ";
	caracteres.mostrar();
}
