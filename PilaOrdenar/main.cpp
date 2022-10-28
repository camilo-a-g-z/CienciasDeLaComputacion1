#include <iostream>
#include "PILA.h"
using namespace std;

/*
Orden des  Orden Asc    Resultado
| 10|       | 6 |         	| 9 |
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
Pila<T> ordenar(Pila<T> oD, Pila<T> oA){
	T aux1, aux2;
	Pila<int> aux(100);
	Pila<int> auxInterno(100);
	if(!oD.vacia()){
		while(!oD.vacia())	{auxInterno.meter(oD.sacar());}
	}
	while( !auxInterno.vacia() || !oA.vacia() ){
		//en caso de que solo este la pila de orden descendente llena
		if(oA.vacia()){
			while(!auxInterno.vacia())	{aux.meter(auxInterno.sacar());}
		}else if(auxInterno.vacia()){
			while(!oA.vacia())	{aux.meter(oA.sacar());}
		}else{
			aux1 = auxInterno.sacar();
			aux2 = oA.sacar();
			if(aux1<aux2){
				aux.meter(aux1);
				oA.meter(aux2);
			}else{
				aux.meter(aux2);
				auxInterno.meter(aux1);
			}
		}
	}
	return aux;
}

int main(int argc, char** argv) {
	//template < class T >  ;
	Pila<int> oD(5);
	oD.meter(14);
	oD.meter(16);
	oD.meter(18);
	oD.meter(20);
	
	Pila<int> oA(5);
	oA.meter(19);
	oA.meter(17);
	oA.meter(15);
	oA.meter(13);
	
	Pila<int> res = ordenar(oD,oA);
	while(!res.vacia()){
		cout<<res.sacar()<<endl;
	}
	return 0;
}
