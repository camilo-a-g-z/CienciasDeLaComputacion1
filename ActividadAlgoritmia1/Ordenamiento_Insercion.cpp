//Metodo de inserccion

#include<windows.h>
#include <iostream>

using namespace std;

int main(){
	for(int q=10 ; q<=500;q +=10){
		//variables para algoritmo
		int tam = q;
		int array[tam];
		int i,pos,aux;
		//rellenar arraglo
		for(int w = 0; w<tam ; w++){
			//peor caso
			//array[w] = tam - w;
			//mejor caso
			array[w] =w;
		}
		//variables para cronometrar
		double time=0;  
		LARGE_INTEGER nFreq;  
		LARGE_INTEGER nBeginTime;  
		LARGE_INTEGER nEndTime;  
		QueryPerformanceFrequency(&nFreq);  
		QueryPerformanceCounter(&nBeginTime);// Comienza a cronometrar
		/**************************************************************************/
		//inicio codigo a medir
		for(i=0;i<tam;i++){
			pos = i; 
			aux = array[i];
			
			while((pos>0) && (array[pos-1] > aux)){
				array[pos] = array[pos-1];
				pos--;
			}
			array[pos] = aux;
		}
		//Fin codigo a medir
	    /**************************************************************************/
		QueryPerformanceCounter(&nEndTime);// deja de cronometrar  
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;// Calcular la unidad de tiempo de ejecución del programa como s  
		//cout<<"Tiempo de ejecución:"<<time*1000<<"ms"<<endl;
		cout<<time<<endl;
	}
	return 0;
}
