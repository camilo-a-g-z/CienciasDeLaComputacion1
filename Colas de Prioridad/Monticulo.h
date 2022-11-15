#include <iostream>
#ifndef MONTICULO_H
#define MONTICULO_H
using namespace std;

class monticulo{ 
	private:
		int *Arr, tam, PosAct;
	public: 
		monticulo(int);
		bool insertar(int);
		int atender();
		void imprimirArreglo();
		bool monticulo_lleno();

};



#endif
