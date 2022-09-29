#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;

void cambioresiduos(int a[], int izq, int der, int b)
{ 
	int i,j;
	if (der>izq && b>0)
	{
		i= izq; j=der;
		while(j!=i)
	{
	while(!((a[i]>>b)&~(~0<<1))&& i<j)i++;
	while( ((a[j]>>b)&~(~0<<1)) && j>i)j--;
	//intercambio
	int aux = a[i];
	a[i]=a[j];
	a[j]=aux;
	}
	if (!((a[i]>>b)&~(~0<<1))) j++;
	
	cambioresiduos(a, izq, j-1, b-1);
	cambioresiduos(a, j, der, b-1);
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
	    cambioresiduos(a,0,(q-1),16);
	    /*for(int i=0;i<q;i++){
	        cout<<a[i]<<endl;
	    }*/
    	//Fin codigo a medir
	    /**************************************************************************/
		QueryPerformanceCounter(&nEndTime);// deja de cronometrar  
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;// Calcular la unidad de tiempo de ejecución del programa como s  
		//cout<<"Tiempo de ejecución:"<<time*1000<<"ms"<<endl;
		cout<<time<<endl;
	}
    return 0;
}
