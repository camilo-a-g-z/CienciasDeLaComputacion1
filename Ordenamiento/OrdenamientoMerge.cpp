#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;

void mezcla(int a[], int izq, int medio, int der){
	int* aux;
	int i,k,z;
	aux = new int(der-izq+1);
	cout<<"Tamaño: "<<der-izq+1<<endl;
	i = z = izq;
	k = medio+1;
	
	//ordenamos los elementos en el arregloa aux
	while(i<=medio && k<=der){
		if(a[i] <= a[k]){
			aux[z++] = a[i++];
		}
		else{
			aux[z++] = a[k++];
		}
	}
	
	//ahora copiamos los elementos de la lista que no quedo vacia
	while(i<=medio){
		aux[z++] = a[i++];
	}
	while(k<=der){
		aux[z++] = a[k++];
	}
	
	//copiamos los elementos del arreglo aux al arreglo a
	for(int i=izq; i <=der; i++){
		cout<<"Izquierda: "<<der<<" Derecha: "<<izq<<endl;
		a[i] = aux[i];
	}
	delete aux;
	
}


void margesort(int a[], int primero, int ultimo){
	int central;
	if(primero < ultimo){
		central = (primero + ultimo)/2;
		margesort(a,primero,central);//se organiza la sublista izq
		margesort(a,central+1,ultimo);//se organiza la sublista der
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
