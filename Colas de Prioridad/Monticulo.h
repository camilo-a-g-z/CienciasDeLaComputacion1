#include <iostream>
#ifndef MONTICULO_H
#define MONTICULO_H
using namespace std;

class Monticulo{ 
	private:
		int *Arr, tam, PosAct;
		void organizar(int);
		void organizar2(int pend, int pos);
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

int Monticulo::atender(){
	int aux, aux2;
	aux = Arr[Arr[0]-1]; //guarda el ultimo elemento del arreglo
	Arr[Arr[0]-1] = 0;
	aux2 = Arr[1]; //Guarda el elemento de la raiz
	Arr[0] = Arr[0]-1; //disminuye en 1 el tamaño del arreglo
	organizar2(aux, 1);	

	
	
	return aux2;
}

void Monticulo::organizar2(int pend, int pos){
	int hijo = 2*pos; //busca al hijo de la pos
	if(hijo<Arr[0]){
		if (Arr[hijo]>pend && Arr[hijo]>Arr[hijo+1]){ //caso en el que el de la poscision hijo es mayor
			Arr[pos] = Arr[hijo];
			organizar2(pend, hijo); 
		} else if (Arr[hijo+1]>pend && Arr[hijo+1]>Arr[hijo]){ //caso en el que el de la poscision hijo+1 es mayor
			Arr[pos] = Arr[hijo+1];
			organizar2(pend, hijo+1);
		} else { //cuando el elemento pendiente es el mayor
			Arr[pos] = pend;
		}
	}
	
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
