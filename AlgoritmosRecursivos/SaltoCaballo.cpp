#include <iostream>
#include <stdlib.h>

using namespace std;

const int N = 5;	
int tablero[8][8];

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
			escribir_tablero();//mostramos como el caballo se va moviendo
			
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
	bool exito;
	int fila = 2;
	int columna = 2;
	
	tablero[fila][columna] = 1;
	
	salto_caballo(2,fila,columna,exito);
	
	if(exito){//si exito es verdadero
		cout<<"\nCamino encontrado."<<endl;
		escribir_tablero();
	}
	else{
		cout<<"\nCamino no encontrado."<<endl;
	}
	
	system("pause");
	return 0;
}
