//Ordenamiento por Selección

#include <cstdlib>
#include <iostream>
#include <ctime> 

using namespace std;

int main(){
	//variables para medir tiempo
	unsigned t0, t1;
	for(int q=10 ; q<=500;q +=10){
		//variables para algoritmo
		int tam = q;
		int array[tam];
		int i,j,aux,min;
		//rellenar arraglo
		for(int w = 0; w<tam ; w++){
			array[w] = tam - w;
		}
		//prueba de arreglo
		/*for(int c=0;c<tam;c++){
			cout<<array[c]<<endl;
		}*/
		t0 = clock();
		/**************************************************************************/
		//inicio codigo a medir
		for(i=0;i<tam;i++){
			min = i;
			for(j=i+1;j<tam;j++){
				if(array[j] < array[min]){
					min = j;
				}
			}
			aux = array[i];
			array[i] = array[min];
			array[min] = aux;
		}
		//Fin codigo a medir
	    /**************************************************************************/
		t1 = clock();
	     
	    double time = (double(t1-t0)/CLOCKS_PER_SEC);
	    //cout << "Execution Time: " << time << endl;
	    cout <<time << endl;
	}
	return 0;
}
