#include <iostream>
#ifndef MONTICULO_H
#define MONTICULO_H
using namespace std;

class Monticulo{ 
	private:
		int *Arr, tam, PosAct;
	public: 
		Monticulo(int t){
			tam = t;
			Arr = new int[tam];
			//posicion 0 de control para saber posicion libre, para saber por donde crecer
			Arr[0] = 1;
			for(int i=1;i<tam;i++){Arr[i]=0;}
		}
		bool insertar(int);
		int atender();
		void imprimirArreglo();
		bool monticulo_lleno();
		void organizar(int);
};
bool Monticulo::monticulo_lleno(){return (Arr[0] == tam) ? true : false;}

void Monticulo::imprimirArreglo(){
	for(int i=1;i<tam;i++){cout<<Arr[i]<<" | ";}
	cout<<endl;
}

bool Monticulo::insertar(int d){
	if(!monticulo_lleno()){
		Arr[Arr[0]] = d;
		cout<<"val Arr0: "<<Arr[0]<<"Con dato: "<<d<<endl;
		organizar(Arr[0]);
		Arr[0] = Arr[0]+1;
		return true;
	}else{return false;}
}

void Monticulo::organizar(int pos){
	int pad;
	if(pos != 1){
		pad = pos/2;
		if(Arr[pad]<Arr[pos]){
			int aux=Arr[pad];
			Arr[pad] = Arr[pos]; 
			Arr[pos] = aux;
			organizar(pad);
		}		
	}
}
	
#endif
