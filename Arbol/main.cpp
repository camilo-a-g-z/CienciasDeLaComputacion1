#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Arbol.h"

using namespace std;

int main(){
	Arbol a;
	a.insertar_nodo_p(15);
	a.insertar_nodo_p(51);
	a.insertar_nodo_p(5);
	a.insertar_nodo_p(6);
	a.insertar_nodo_p(3);
	a.insertar_nodo_p(55);
	a.insertar_nodo_p(49);
	a.insertar_nodo_p(50);
	a.insertar_nodo_p(50);
	a.mostrar_arbol_p();
	a.eliminar_p(57);
	cout<<endl;
	a.mostrar_arbol_p();
	a.eliminar_p(51);
	a.mostrar_arbol_p();
	return 0;
}

