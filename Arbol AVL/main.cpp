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
	/*a.insertar_nodo_p(10,1);
	a.insertar_nodo_p(8,1);
	a.insertar_nodo_p(7,1);
	a.insertar_nodo_p(6,1);
	a.insertar_nodo_p(5,1);
	a.insertar_nodo_p(9,1);*/
	
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
	
	
	a.insertar_nodo_p(100,1);
	a.insertar_nodo_p(90,1);
	a.insertar_nodo_p(80,1);
	a.insertar_nodo_p(110,1);
	a.insertar_nodo_p(95,1);
	a.insertar_nodo_p(120,1);
	a.insertar_nodo_p(130,1);
	a.insertar_nodo_p(140,1);
	a.insertar_nodo_p(111,1);
	a.eliminar_p(100);
	a.insertar_nodo_p(128,1);
	a.insertar_nodo_p(97,1);
	a.insertar_nodo_p(85,1);
	a.insertar_nodo_p(94,1);
	a.insertar_nodo_p(72,1);
	a.insertar_nodo_p(92,1);
	a.insertar_nodo_p(76,1);
	a.insertar_nodo_p(70,1);
	a.insertar_nodo_p(81,1);
	a.insertar_nodo_p(74,1);
	a.eliminar_p(90);
	
	
	/*a.insertar_nodo_p(5,1);
	a.insertar_nodo_p(4,1);
	a.insertar_nodo_p(7,1);
	a.insertar_nodo_p(6,1);
	a.insertar_nodo_p(8,1);
	//a.insertar_nodo_p(3,1);
	a.mostrar_arbol_p();
	
	a.eliminar_p(6);*/
	
	return 0;
}

