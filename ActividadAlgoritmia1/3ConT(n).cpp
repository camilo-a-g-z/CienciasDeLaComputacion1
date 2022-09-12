#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
#include<iostream>

using namespace std;

struct nodo {
	int x, y;
	nodo *sig;
};

// función principal para encontrar el tiempo de ejecución de un programa en C
int main()
{
    // para almacenar el tiempo de ejecución del código
    double time_spent = 0.0;
 
    clock_t begin = clock();
    /**************************************************************************/
    //Inicio codigo a medir
    int N, i, j;
	nodo *cab = NULL, *Aux;
	cin >> N;
	for(i=0;i<N;i++){
		Aux = new nodo;
		Aux -> x = i;
		Aux -> y = N-i;
		Aux -> sig = cab;
		cab = Aux;
	}
	Aux = cab;
	while(Aux != NULL){
		//cout << Aux ->x << " | " << Aux ->y <<endl;
		Aux = Aux -> sig;
	}
	for(Aux = cab -> sig; Aux != NULL; Aux = Aux ->sig){
		delete cab;
		cab= Aux;
	}
    //Fin codigo a medir
    /**************************************************************************/
    clock_t end = clock();
 
    // calcula el tiempo transcurrido encontrando la diferencia (end - begin) y
    // dividiendo la diferencia por CLOCKS_PER_SEC para convertir a segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    //printf("The elapsed time is %f seconds", time_spent);
    cout<<"Tiempo empleado: "<<time_spent<<endl;
    return 0;
}