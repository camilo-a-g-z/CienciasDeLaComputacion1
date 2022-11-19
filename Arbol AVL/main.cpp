/*
	Integrantes:
	Camilo Andres Garcia Zambrano(20201020047)
	Miguel Angel Veloza Ortiz(20192020012)
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "ArbolAVL.h"
#include "PILA.h"
using namespace std;

int main(){
	ArbolAVL a;
	Queue<int> c;
	Queue<int> c2;
	Queue<int> c3;
	cout<<"Arbol esta vacio? "<<a.arbol_vacio()<<endl;
	a.insertar_nodo_p(15,1);
	a.insertar_nodo_p(51,1);
	a.insertar_nodo_p(5,1);
	a.insertar_nodo_p(6,1);
	a.insertar_nodo_p(3,1);
	a.insertar_nodo_p(55,1);
	a.insertar_nodo_p(49,1);
	a.insertar_nodo_p(50,1);
	a.insertar_nodo_p(58,1);
	a.insertar_nodo_p(39,1);
	a.insertar_nodo_p(10,1);
	a.insertar_nodo_p(60,1);
	

	
	a.mostrar_arbol_p();
	cout<<endl;
	c = a.in_orden();
	c2 = a.pre_orden();
	c3 = a.post_orden();
	cout<<endl;
	c.imprimir_queue('I');
	cout<<endl;
	c2.imprimir_queue('I');
	cout<<endl;
	c3.imprimir_queue('I');
	cout<<endl;
	a.eliminar_p(15);
	a.mostrar_arbol_p();
	cout<<endl;
	c = a.in_orden();
	c2 = a.pre_orden();
	c3 = a.post_orden();
	cout<<endl;
	c.imprimir_queue('I');
	cout<<endl;
	c2.imprimir_queue('I');
	cout<<endl;
	c3.imprimir_queue('I');

	/*
	 *Como el arbol es privado en la clase no se puede realizar:
	 *Nodo *n = a.buscar_nodo_p(3);
	 *cout<<"Buscando un nodo: "<<n->info<<endl;
	 *debido a que tenemos un priblema de acceso a memoria negado
	*//*
	Nodo *n = a.buscar_nodo_p(15);
	int i = n->dato;
	cout<<"Buscando un nodo: "<<i<<endl;
	/*
	 * Nota: se pudo crear una copia desde la clase y enviarla, no obstante, resulta mas
	 *mas util enviar la direccion ya que igualmente se puede acceder a otras posiciones
	 *de memoria, por ejemplo:
	*//*
	i = n->der->dato;
	cout<<"Buscando un nodo: "<<i<<endl;
	cout<<"Arbol esta vacio? "<<a.arbol_vacio()<<endl;*/
	return 0;
}

