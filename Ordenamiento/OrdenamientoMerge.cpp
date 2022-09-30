#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;
/*funcion de mezcla tomada de https://www.geeksforgeeks.org/merge-sort/
 *funcion propuesta en aula proporcionaba errores para arreglos mayores a 13
 *como se puede ver en el git
 *en el git https://github.com/camilo-a-g-z/CienciasDeLaComputacion1 
 *commit 1ec0b377ad0021755e85ac2c2ccb255d59b7d01e
*/
void mezcla(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void margesort(int a[], int primero, int ultimo){
	int central;
	if(primero < ultimo){
		central = (primero + ultimo)/2;
		margesort(a,primero,central);//se organiza la sublista izq
		margesort(a,central+1,ultimo);//se organiza la sublista der
		//cout<<"Entramos a mezcla"<<endl;
		mezcla(a,primero,central,ultimo);//ordenar los elementos del arreglo
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
