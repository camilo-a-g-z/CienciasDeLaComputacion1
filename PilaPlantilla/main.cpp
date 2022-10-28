/*
Integrantes: 
	Camilo Andres Garcia Zambrano(20201020047)
	Miguel Angel Veloza Ortiz(20192020012)
*/

#include <iostream>
#include "PILA.h"
using namespace std;

template < class T >  
void reemplazar(Pila<T> x, T valA, T valN){
	Pila<int> aux(100);
	T datoAux;
	if(!x.vacia()){
		do{
			datoAux = x.sacar();
			aux.meter(datoAux);
		}while(datoAux != valA && !x.vacia());
		if(datoAux == valA){
			aux.sacar();
			x.meter(valN);
			while(!aux.vacia()){
				x.meter(aux.sacar());
			}
		}
	}
}

int main(int argc, char** argv) {
	//template < class T >  ;
	Pila<int> acc(5);
	acc.meter(4);
	acc.meter(423);	
	acc.meter(5);
	acc.meter(14);
	acc.meter(22);
	reemplazar(acc, 5, 10);
	while(!acc.vacia()){
		cout<<acc.sacar()<<endl;
	}
	return 0;
}
