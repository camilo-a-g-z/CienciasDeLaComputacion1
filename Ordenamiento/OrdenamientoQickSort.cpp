/*
Integrantes:
Miguel Angel Veloza Ortiz - 20192020012
Camilo Andres Garcia Zambrano - 20201020047
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;

void intercambio(int a[], int i, int j){
	//intercambio(a, i, j);
	int aux = a[i];
	a[i]=a[j];
	a[j]=aux;
}

void quicksort(int a[], int izq, int der)
{
	int i, j; int v;
	if (der> izq)
	{
		v= a[der]; i = izq -1; j= der;
		for(;;)
		{
			while (a[++i]<v);
			while (a[--j] >v);
			if(i>=j) break;
			intercambio(a,i,j);
		}
		intercambio(a, i, der);
		quicksort(a, izq, i-1);
		quicksort(a, i+1,der);
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
	srand(time(0));
	for(int q=10 ; q<=500;q +=10){
	    //arreglo a ordenar
	    int *a = new int[q];
	    //bucle para llenar arreglo
	    for(int i=0;i<q;i++){
	        do{
	        	val = 1 + rand() % (q+15); 
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
	    quicksort(a,0,(q-1));
	    /*for(int i=0;i<q;i++){
	        cout<<a[i]<<endl;
	    }*/
    	//Fin codigo a medir
	    /**************************************************************************/
		QueryPerformanceCounter(&nEndTime);// deja de cronometrar  
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;// Calcular la unidad de tiempo de ejecuci�n del programa como s  
		//cout<<"Tiempo de ejecuci�n:"<<time*1000<<"ms"<<endl;
		cout<<time<<endl;
	}
	
    return 0;
}
