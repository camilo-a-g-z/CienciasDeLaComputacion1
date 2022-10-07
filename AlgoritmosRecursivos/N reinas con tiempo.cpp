//Ordenamiento por Selecci?n

#include<windows.h>
#include <iostream>

using namespace std;
//Prototipos de Funciones
void ponerReina(int,bool&);
bool valido(int);
void mostrarTablero();
int N = 0;
int *reinas;

int main(){
	for(int q=4 ; q<=50;q++){
		bool solucion;
		N=q;
		reinas = new int[q];
		//variables para cronometrar
		double time=0;  
		LARGE_INTEGER nFreq;  
		LARGE_INTEGER nBeginTime;  
		LARGE_INTEGER nEndTime;  
		QueryPerformanceFrequency(&nFreq);  
		QueryPerformanceCounter(&nBeginTime);// Comienza a cronometrar
		/**************************************************************************/
		//inicio codigo a medir
		ponerReina(0,solucion);
		mostrarTablero();
		//Fin codigo a medir
	    /**************************************************************************/
		QueryPerformanceCounter(&nEndTime);// deja de cronometrar  
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;// Calcular la unidad de tiempo de ejecuci?n del programa como s  
		//cout<<"Tiempo de ejecuci?n:"<<time*1000<<"ms"<<endl;
		cout<<time<<endl;
		delete reinas;
	}
	return 0;
}

void mostrarTablero(){
	int tablero[N][N];
	
	cout<<"\nMostrar las reinas"<<endl;
	for(int i=0;i<N;i++){
		cout<<reinas[i]<<"|";
	}
	
	cout<<endl<<endl;
	
	//Inicializamos todas las casillas del tablero en 0
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tablero[i][j] = 0;
		}
	}

	//Asignamos las reinas (1) en el tablero
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tablero[reinas[j]][j] = 1;
		}
	}
	
	//Mostramos el tablero
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<tablero[i][j]<<"|";
		}
		cout<<endl;
	}
}

void ponerReina(int i,bool &solucion){
	int k=0; //Inicializa contador de movimientos
	solucion = false;
	
	do{
		reinas[i] = k; // Coloca y anota reina i en la fila k
		k++;
		
		//mostrarTablero();
		//cout<<endl;
		
		if(valido(i)){
			if(i<(N-1)){
				ponerReina(i+1,solucion);
				
				//vuelta atras
				if( !solucion ){
					reinas[i] = 0;
				}
			}
			else{ //Todas las reinas colocadas
				solucion = true;
			}
		}
	}while(!solucion && (k<N));	
}

bool valido(int i){
	/*Comprueba si la reina de la columna i es atacada por 
	alguna reina colocada anteriormente*/
	
	bool v = true;
	
	for(int r=0; r<i; r++){
		v = v && (reinas[r] != reinas[i]); //No este en la misma fila
		v = v && ((reinas[i]-i) != (reinas[r]-r)); // Diagonal 1
		v = v && ((reinas[i]+i) != (reinas[r]+r)); // Diagonal 2
	}
	
	return v;
}