#include <iostream>
#ifndef MONTICULO_H
#define MONTICULO_H
using namespace std;

class Monticulo{ 
	private:
		int *Arr, tam, PosAct;
	public: 
		Monticulo(int tam){
			this.tam = tam;
			Arr = new int[tam];
			//posicion 0 de control para saber posicion libre, para saber por donde crecer
			Arr[0] = 1;
		}
		bool insertar(int);
		int atender();
		void imprimirArreglo();
		bool monticulo_lleno();
};
bool Monticulo::monticulo_lleno(){
	return (Arr[0] == tam-1) ? true : false;
}

void Monticulo::imprimirArreglo(){
	for(int i=1;i<tam;i++){cout<<Arr[i]<<" | ";}
	cout<<endl;
}


#endif
