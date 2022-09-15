//Metodo Burbuja

#include <cstdlib>
#include <iostream>
#include <ctime> 

using namespace std;

int main(){
	unsigned t0, t1;
	for(int q=10 ; q<=500;q +=10){
	    int tam = 10;
	    int array[tam];
		int i,j,aux;	
		for(int w = 0; w<tam ; w++){
			//peor caso
			array[w] = tam - w;
			//mejor caso
			//array[w] =w;
		}
		/*for(int c=0;c<tam;c++){
			cout<<array[c]<<endl;
		}*/
		t0 = clock();
		/**************************************************************************/
	    //Inicio codigo a medir
		for(i=0;i<tam;i++){
			for(j=0;j<tam;j++){
				if(array[j] > array[j+1]){
					aux = array[j];
					array[j] = array[j+1];
					array[j+1] = aux;
				}
			}
		}
		//Fin codigo a medir
	    /**************************************************************************/
		t1 = clock();
	     
	    double time = (double(t1-t0)/CLOCKS_PER_SEC);
	    //cout << "Execution Time: " << time << endl;
	    //cout <<time << endl;
	}
    
	return 0;
}
