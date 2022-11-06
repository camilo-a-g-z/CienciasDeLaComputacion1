#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Arbol.h"

using namespace std;

int main(){
	Arbol a;
	cout<<"Arbol esta vacio? "<<a.arbol_vacio()<<endl;
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
	cout<<endl;
	
	/*
	 *Como el arbol es privado en la clase no se puede realizar:
	 *Nodo *n = a.buscar_nodo_p(3);
	 *cout<<"Buscando un nodo: "<<n->info<<endl;
	 *debido a que tenemos un priblema de acceso a memoria negado
	*/
	Nodo *n = a.buscar_nodo_p(15);
	int i = n->dato;
	cout<<"Buscando un nodo: "<<i<<endl;
	/*
	 * Nota: se pudo crear una copia desde la clase y enviarla, no obstante, resulta mas
	 *mas util enviar la direccion ya que igualmente se puede acceder a otras posiciones
	 *de memoria, por ejemplo:
	*/
	i = n->der->dato;
	cout<<"Buscando un nodo: "<<i<<endl;
	cout<<"Arbol esta vacio? "<<a.arbol_vacio()<<endl;
	return 0;
}

