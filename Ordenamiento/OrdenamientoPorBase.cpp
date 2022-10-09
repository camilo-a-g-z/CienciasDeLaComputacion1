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
 
//funcion para obtener el maximo del arreglo con n tama�o
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
 
    // Se almacenan coincidencias en el contador
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Cambio del contador para que ahora poseea la posicion actual del contador
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Se construye el nuevo arreglo
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Se actualiza arreglo
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 //funcion principal
void radixsort(int arr[], int n)
{
    // Se obtiene el numero maximo
    int m = getMax(arr, n);
 
    // Se hace el orden de conteo por cada digito 
    // implementando el exp ya que con este sabemos
    // en que unidad (decena, centena, etc) esta
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
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
	    //cout<<"Tam "<<sizeof(a)<<" and q: "<<q<<endl;
	    //variables para cronometrar
		double time=0;  
		LARGE_INTEGER nFreq;  
		LARGE_INTEGER nBeginTime;  
		LARGE_INTEGER nEndTime;  
		QueryPerformanceFrequency(&nFreq);  
		QueryPerformanceCounter(&nBeginTime);// Comienza a cronometrar
		/**************************************************************************/
		//inicio codigo a medir

     
      	// Function Call
      	radixsort(a, q);
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
