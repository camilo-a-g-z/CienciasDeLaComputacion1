//Metodo de inserccion

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
		int i,pos,aux;
		//rellenar arraglo
		for(int w = 0; w<tam ; w++){
			//peor caso
			array[w] = tam - w;
			//mejor caso
			//array[w] =w;
		}
		//prueba de arreglo
		/*for(int c=0;c<tam;c++){
			cout<<array[c]<<endl;
		}*/
		t0 = clock();
		/**************************************************************************/
		//inicio codigo a medir
		for(i=0;i<tam;i++){
			pos = i; 
			aux = array[i];
			
			while((pos>0) && (array[pos-1] > aux)){
				array[pos] = array[pos-1];
				pos--;
			}
			array[pos] = aux;
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
