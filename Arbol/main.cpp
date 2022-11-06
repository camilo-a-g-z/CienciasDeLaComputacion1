#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Arbol.h"

using namespace std;

int main(){
	Arbol a;
	a.insertar_nodo_p(15,1);
	a.insertar_nodo_p(51,1);
	a.insertar_nodo_p(5,1);
	a.insertar_nodo_p(6,1);
	a.insertar_nodo_p(3,1);
	a.insertar_nodo_p(55,1);
	a.insertar_nodo_p(49,1);
	a.insertar_nodo_p(50,1);
	a.insertar_nodo_p(50,1);
	a.mostrar_arbol_p();
	a.eliminar_p(57);
	cout<<endl;
	a.mostrar_arbol_p();
	a.eliminar_p(51);
	a.mostrar_arbol_p();
	return 0;
}

