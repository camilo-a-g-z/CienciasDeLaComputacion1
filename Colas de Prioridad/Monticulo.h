#include <iostream>
#ifndef MONTICULO_H
#define MONTICULO_H
using namespace std;

class Monticulo{ 
	private:
		int *Arr, tam, PosAct;
		void organizar(int);
	public: 
		Monticulo(int t){
			tam = t +1;//+1 teniendo en cuenta que 0 es posicion de control
			Arr = new int[tam];
			Arr[0] = 1;//posicion 0 de control para saber posicion libre, para saber por donde crecer
			for(int i=1;i<tam;i++){Arr[i]=0;}
		}
		bool insertar(int);
		int atender();
		void imprimirArreglo();
		bool monticulo_lleno();
};
bool Monticulo::monticulo_lleno(){return (Arr[0] == tam) ? true : false;}

void Monticulo::imprimirArreglo(){
	for(int i=1;i<tam;i++){cout<<Arr[i]<<" | ";}
	cout<<endl;
}

bool Monticulo::insertar(int d){
	if(!monticulo_lleno()){
		//se agrega al final
		Arr[Arr[0]] = d;
		//se organiza acorde a la prioridad
		organizar(Arr[0]);
		//se aumenta pos final
		Arr[0] = Arr[0]+1;
		return true;
	}else{return false;}
}

void Monticulo::organizar(int pos){
	//en caso de que no sea el padre la raiz
	if(pos != 1){
		//se encuentra el padre
		int pad = pos/2;
		//si es mayor se cambia de pos y se genera recursividad
		if(Arr[pad]<Arr[pos]){
			//se hace intercambio
			int aux=Arr[pad];
			Arr[pad] = Arr[pos]; 
			Arr[pos] = aux;
			//se hace recursion
			organizar(pad);
		}		
	}
}
	
#endif
