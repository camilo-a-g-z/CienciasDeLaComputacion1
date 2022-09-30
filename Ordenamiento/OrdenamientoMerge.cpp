#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;

void mezcla(int list[], int start1, int end1, int start2, int end2){
	int* result;
	result = new int(end2-start1+1);
	int finalStart = start1;
	int finalEnd = end2;
	int indexC = 0;
	while((start1<=end1)&&(start2<=end2)){
		if(list[start1] < list[start2]){
			result[indexC]=list[start1];
			start1=start1 + 1;
		}else{
			result[indexC]=list[start2];
			start2=start2+1;
		}
		indexC = indexC +1;
	}
	if(start1<=end1){
		for(int i = start1; i<end1;i++){
			result[indexC]=list[i];
			indexC=indexC+1;
		}
	}else{
		for(int i = start2; i<end2;i++){
			result[indexC]=list[i];
			indexC=indexC+1;
		}
	}
	indexC=1;
	for(int i=finalStart;i<finalEnd;i++){
		list[i]=result[indexC];
		indexC=indexC+1;
	}
	delete[] result;
}


void margesort(int a[], int primero, int ultimo){
	int central;
	if(primero < ultimo){
		central = (primero + ultimo)/2;
		margesort(a,primero,central);//se organiza la sublista izq
		margesort(a,central+1,ultimo);//se organiza la sublista der
		//cout<<"Entramos a mezcla"<<endl;
		mezcla(a,primero,central,central +1,ultimo);//ordenar los elementos del arreglo
	}
}


bool verificarRepetido(int valor, int indice, int a[]){
	//posicion diferente a 0
	if(indice != 0){
		//comparacion con los demas elementos del arreglo
		for(int i=0;i<indice;i++)
			if(a[i]==valor)
				return false;
	}else{
		return true;
	}
	return true;
}

int main()
{
	//variables para generar aleatorios
	int val;
	int q=0;
	int i=0;
	srand(time(0));
	for(q = 10 ; q<=500;q+=10){
	    //arreglo a ordenar
		//cout<<"aqui"<<endl;
	    int *a = new int[q];
	    //bucle para llenar arreglo
	    for(i=0;i<q;i++){
	        do{
	        	val = 1 + rand() % (q+5); 
	        	//cout<<i<<endl;
			}while(!verificarRepetido(val, i, a));
			a[i] = val;
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

	    margesort(a,0,(q-1));
	    /*for(int i=0;i<q;i++){
	        cout<<a[i]<<endl;
	    }*/
    	//Fin codigo a medir
	    /**************************************************************************/
		QueryPerformanceCounter(&nEndTime);// deja de cronometrar  
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;// Calcular la unidad de tiempo de ejecución del programa como s  
		//cout<<"Tiempo de ejecución:"<<time*1000<<"ms"<<endl;
		cout<<time<<endl;
		delete a;
	}
    return 0;
}
