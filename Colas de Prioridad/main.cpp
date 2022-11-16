#include <iostream>
#include "Monticulo.h"
using namespace std;

int main(){
	Monticulo m(10);
	m.insertar(60);
	m.insertar(80);
	m.insertar(20);
	m.insertar(90);
	m.insertar(50);
	m.insertar(40);
	m.insertar(30);
	m.insertar(70);
	m.insertar(55);
	m.insertar(45);
	m.imprimirArreglo();
	m.atender();
	m.atender();
	m.imprimirArreglo();
	return 0;
}
