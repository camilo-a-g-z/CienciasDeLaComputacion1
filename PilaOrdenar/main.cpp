/*
Integrantes: 
	Camilo Andres Garcia Zambrano(20201020047)
	Miguel Angel Veloza Ortiz(20192020012)
*/

#include <iostream>
#include "PILA.h"
using namespace std;
Pila<int> oD(5);
Pila<int> oA(5);
int i=0;
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

template < class T >
void volverAsc(Pila<T> mD){
	T aux1;
	if(!oA.vacia()){
		aux1 = oA.sacar();
		volverAsc(mD);
		oD.meter(aux1);
		i++;
	}
}
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
			ordenar2(oD,oA);
			oD.meter(aux1);
		}else{
			aux1 = oA.sacar();
			aux2 = oD.sacar();
			if(aux1>aux2){
				oD.meter(aux2);
				ordenar2(oD,oA);
				oD.meter(aux1);
			}else{
				oA.meter(aux1);
				ordenar2(oD,oA);
				oD.meter(aux2);
			}
		}
	}
}
int main(int argc, char** argv) {
	//template < class T >  ;
	
	oD.meter(14);
	oD.meter(16);
	oD.meter(18);
	oD.meter(20);
	
	
	oA.meter(19);
	oA.meter(17);
	oA.meter(15);
	oA.meter(13);
	volverAsc(oD);
	while(i!=0){
		oA.meter(oD.sacar());
		i--;
	}
	ordenar2(oD,oA);
	cout<<"oD"<<endl;
	while(!oD.vacia()){
		cout<<oD.sacar()<<endl;
	}
	cout<<"oA"<<endl;
	while(!oA.vacia()){
		cout<<oA.sacar()<<endl;
	}
	return 0;
}
