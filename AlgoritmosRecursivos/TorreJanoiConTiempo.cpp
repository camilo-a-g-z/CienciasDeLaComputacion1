#include <iostream>
#include <stdlib.h>
#include<windows.h>
#include<fstream>

using namespace std;

void janoi(char varilla_inicial, char  varilla_central, char varilla_final, int n){
	if(n == 1){//caso basse
		//cout<<"\nMover disco "<<n<<" desde la variila "<<varilla_inicial
		//<<" a varilla "<<varilla_final;
	}
	else{//caso recursivo
		janoi(varilla_inicial, varilla_final, varilla_central,n-1);
		//cout<<"\nMover disco "<<n<<" desde la varilla "<<varilla_inicial
		//<<" a varilla "<<varilla_final;
		janoi(varilla_central, varilla_inicial, varilla_final, n-1);
	}
	
}

int main(){
	ofstream archivo;
	archivo.open("TorreJanoiResultados.txt",ios::out); //Creamos el archivo
	
	if(archivo.fail()){ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	for(int q=4 ; q<=50;q++){
		
		//variables para cronometrar
		double time=0;  
		LARGE_INTEGER nFreq;  
		LARGE_INTEGER nBeginTime;  
		LARGE_INTEGER nEndTime;  
		QueryPerformanceFrequency(&nFreq);  
		QueryPerformanceCounter(&nBeginTime);// Comienza a cronometrar
		/**************************************************************************/
		//inicio codigo a medir
		janoi('A','B','C',q);
		//Fin codigo a medir
	    /**************************************************************************/
		QueryPerformanceCounter(&nEndTime);// deja de cronometrar  
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;// Calcular la unidad de tiempo de ejecuci?n del programa como s  
		//cout<<"Tiempo de ejecuci?n:"<<time*1000<<"ms"<<endl;
		archivo<<time<<endl;
	}
	archivo.close();
	return 0;
}

