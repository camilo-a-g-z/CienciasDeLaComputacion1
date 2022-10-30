/*
Integrantes: 
	Camilo Andres Garcia Zambrano(20201020047)
	Miguel Angel Veloza Ortiz(20192020012)
*/

#include <iostream>
#include "PILA.h"
using namespace std;
/*
* Nota importante: Por configuracion de c++, templates + punteros + recursion no se
* llevan muy bien por lo que se decidio usar variables globales, de ahi que las
* las funciones principales reciban datos que no se utilizan. adjunto un enlace 
* de stackoverflow que lo explica mejor:
https://stackoverflow.com/questions/73008749/why-does-the-compiler-issue-a-template-recursion-error
*/
//variable para generar volcamiento en una pila
int i=0;
//piulas ascendente(oA), descendente(oD)
Pila<int> oD(5);
Pila<int> oA(5);

/*
Orden des  Orden Asc    Resultado
| 5 |       | 6 |         	| 9 |
| 4 |       | 7 |			| 8 |
| 3 |       | 8 |			| 7 |
| 2 |       | 9 |			| 6 |
| _ |       | _ |			| 5 |
                        	| 4 |
							| 3 |
							| 2 |
							| _ |
*/
//funcion auxiliar para volver la ascendete descendete
template < class T >
void volcarEnOtraPila(Pila<T> mD, Pila<T> mA){
	T aux1;
	if(!oA.vacia()){
		aux1 = oA.sacar();
		volcarEnOtraPila(mD, mA);
		oD.meter(aux1);
		i++;
	}
}
//funcion para volver la ascendete descendete
template < class T >
void volverAsc(Pila<T> mD, Pila<T> mA){
	volcarEnOtraPila(mD, mA);
	while(i!=0){
		oA.meter(oD.sacar());
		i--;
	}
}
//funcion para ordenar implementando recursion
template < class T >  
void ordenar2(Pila<T> mD, Pila<T> mA){
	T aux1, aux2;
	//oD.meter(222);
	if(!oD.vacia() || !oA.vacia()){
		if(oD.vacia()){
			//cout<<"Entro"<<endl;
			aux1 = oA.sacar();
			ordenar2(mD,mA);
			//cout<<aux1<<endl;
			oD.meter(aux1);
			//cout<<"Sacando: "<<oD.sacar()<<endl;;
		}else if(oA.vacia()){
			aux1 = oD.sacar();
			ordenar2(mD,mA);
			oD.meter(aux1);
		}else{
			aux1 = oA.sacar();
			aux2 = oD.sacar();
			if(aux1>aux2){
				oD.meter(aux2);
				ordenar2(mD,mA);
				oD.meter(aux1);
			}else{
				oA.meter(aux1);
				ordenar2(mD,mA);
				oD.meter(aux2);
			}
		}
	}
}
int main(int argc, char** argv) {
	//se ingresan datos de manera descendente 
	oD.meter(10);
	oD.meter(20);
	oD.meter(30);
	oD.meter(40);
	//se ingresan datos de manera ascendente	
	oA.meter(8);
	oA.meter(7);
	oA.meter(6);
	oA.meter(5);
	//se organiza la pila ascendete
	volverAsc(oD, oA);
	//se ordena
	ordenar2(oD,oA);
	
	cout<<"Pila ordenada descendentemente (oD): "<<endl;
	while(!oD.vacia()){
		cout<<oD.sacar()<<endl;
	}
	return 0;
}
