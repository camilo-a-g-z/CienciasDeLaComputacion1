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
	/*a.insertar_nodo_p(10,1);
	a.insertar_nodo_p(8,1);
	a.insertar_nodo_p(7,1);
	a.insertar_nodo_p(6,1);
	a.insertar_nodo_p(5,1);
	a.insertar_nodo_p(9,1);*/
	
	a.insertar_nodo_p(90,1);
	a.insertar_nodo_p(38,1);
	a.insertar_nodo_p(40,1);
	a.insertar_nodo_p(80,1);
	a.insertar_nodo_p(73,1);
	a.insertar_nodo_p(25,1);
	a.insertar_nodo_p(30,1);
	a.insertar_nodo_p(84,1);
	a.insertar_nodo_p(100,1);
	a.insertar_nodo_p(20,1);
	a.insertar_nodo_p(88,1);
	a.insertar_nodo_p(79,1);
	a.insertar_nodo_p(85,1);
	a.insertar_nodo_p(70,1);
	a.insertar_nodo_p(89,1);
	a.insertar_nodo_p(110,1);
	a.insertar_nodo_p(87,1);
	//a.mostrar_arbol_p();
	/*a.insertar_nodo_p(4,1);
	a.insertar_nodo_p(5,1);
	a.insertar_nodo_p(6,1);
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
	a.eliminar_p(5);
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
	c3.imprimir_queue('I');*/

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

