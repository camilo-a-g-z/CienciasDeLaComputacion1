#include <iostream>
#include <stdlib.h>
#include<windows.h>

using namespace std;

int N = 5;	
int **tablero;

//desplazamientos que el caballo puede hacer en la matriz
int d[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

void escribir_tablero(){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
				cout<<tablero[i][j]<<"|";
		}
		cout<<endl;
	}
	cout<<endl;
}

void salto_caballo(int i, int x, int y, bool &exito){
	int nx, ny;
	int k = 0;//iterador para controlar los movimientos del caballo
	exito = false;
	
	do{
		k++;
		
		nx = x + d[k-1][0];
		ny = y + d[k-1][1];
		
		//verificando
		if((nx >=0)&&(nx < N)&&(ny>=0)&&(ny< N)&&(tablero[nx][ny]==0)){
			//guardamos el movimiento
			tablero[nx][ny] = i;
			//escribir_tablero();//mostramos como el caballo se va moviendo
			
			if(i < N*N){
				salto_caballo(i+1,nx,ny,exito);
				
				if(!exito){
					tablero[nx][ny] = 0;
				}
			}
			else{
				exito = true;
			}
		}
		
	}while((k<8) &&!exito);
}


int main(){
	for(int q=8 ; q<=50000;q++){
		bool exito;
		int fila = 2;
		int columna = 2;
		
		tablero = new int*[q];
		for(int p=0;p<q;p++){
			tablero[p]=new int[q];
		}
		tablero[fila][columna] = 1;
		
		//variables para cronometrar
		double time=0;  
		LARGE_INTEGER nFreq;  
		LARGE_INTEGER nBeginTime;  
		LARGE_INTEGER nEndTime;  
		QueryPerformanceFrequency(&nFreq);  
		QueryPerformanceCounter(&nBeginTime);// Comienza a cronometrar
		/**************************************************************************/
		//inicio codigo a medir
		salto_caballo(2,fila,columna,exito);
		//Fin codigo a medir
	    /**************************************************************************/
		QueryPerformanceCounter(&nEndTime);// deja de cronometrar  
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;// Calcular la unidad de tiempo de ejecuci?n del programa como s  
		//cout<<"Tiempo de ejecuci?n:"<<time*1000<<"ms"<<endl;
		cout<<time<<endl;
		for(int p=0;p<q;p++){
			delete tablero[p];
		}
		delete tablero;
	}
	return 0;
}