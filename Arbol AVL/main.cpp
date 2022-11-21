/*
	Integrantes:
	Camilo Andres Garcia Zambrano(20201020047)
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "ArbolAVL.h"
#include "PILA.h"
using namespace std;

int main(){
	ArbolAVL a;
	/*
		La funcion mostrar arbol muestra primero el dato y luego el factor de balance
		dato|FB
		10|1
	*/
	
	//Ejemplo de solo inserccion a la izq
	/*a.insertar_nodo_p(10,1);
	a.insertar_nodo_p(8,1);
	a.insertar_nodo_p(7,1);
	a.insertar_nodo_p(6,1);
	a.insertar_nodo_p(5,1);
	a.insertar_nodo_p(9,1);
	a.mostrar_arbol_p();*/
	
	//Ejemplo de solo inserccion a la der
	/*a.insertar_nodo_p(10,1);
	a.insertar_nodo_p(11,1);
	a.insertar_nodo_p(12,1);
	a.insertar_nodo_p(13,1);
	a.insertar_nodo_p(14,1);
	a.insertar_nodo_p(15,1);
	a.mostrar_arbol_p();*/
	
	//Ejemplo de inserccion dado en las diapos de la profesora
	/*a.insertar_nodo_p(90,1);
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
	a.mostrar_arbol_p();*/
		
	//ultimo ejemplo de inserccion y eliminacion en las diapos de la profesora
	/*a.insertar_nodo_p(100,1);
	a.insertar_nodo_p(90,1);
	a.insertar_nodo_p(80,1);
	a.insertar_nodo_p(110,1);
	a.insertar_nodo_p(95,1);
	a.insertar_nodo_p(120,1);
	a.insertar_nodo_p(130,1);
	a.insertar_nodo_p(140,1);
	a.insertar_nodo_p(111,1);
	a.mostrar_arbol_p();
	cout<<endl<<endl;
	a.eliminar_p(100);
	a.mostrar_arbol_p();
	cout<<endl<<endl;
	a.insertar_nodo_p(128,1);
	a.insertar_nodo_p(97,1);
	a.insertar_nodo_p(85,1);
	a.insertar_nodo_p(94,1);
	a.insertar_nodo_p(72,1);
	a.insertar_nodo_p(92,1);
	a.mostrar_arbol_p();
	cout<<endl<<endl;
	a.insertar_nodo_p(76,1);
	a.insertar_nodo_p(70,1);
	a.insertar_nodo_p(81,1);
	a.insertar_nodo_p(74,1);
	a.mostrar_arbol_p();
	cout<<endl<<endl;
	a.eliminar_p(90);
	a.mostrar_arbol_p();
	cout<<endl<<endl;*/
	
	//caso especial
	/*a.insertar_nodo_p(50,1);
	a.insertar_nodo_p(70,1);
	a.insertar_nodo_p(40,1);
	a.insertar_nodo_p(45,1);
	a.insertar_nodo_p(30,1);
	a.insertar_nodo_p(65,1);
	a.insertar_nodo_p(20,1);
	a.insertar_nodo_p(35,1);
	a.mostrar_arbol_p();
	cout<<endl<<endl;
	a.eliminar_p(45);
	a.mostrar_arbol_p();
	cout<<endl<<endl;*/
	
	return 0;
}

