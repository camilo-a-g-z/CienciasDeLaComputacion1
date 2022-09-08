#include <cstdlib>
#include <iostream>
using namespace std;

struct nodo{
	int x, y;
	nodo *sig;
};

int main(){
	nodo **arr, *Aux;
	int M, tam, j, i;
	
	cout<<"Escriba el valor de M: ";
	cin>>M;
	cout<<"Escriba el valor de tam: ";
	cin>>tam;
	
	arr = new nodo *[M];
	
	for(i=0; i<M ; i++){
		arr[i] = NULL;
	}
	
	for(i=0; i<M ; i++){
		for(j=1; j<=tam; j++){
			Aux = new nodo;
			Aux->x = j;
			Aux->y = M+j*i;
			Aux->sig = arr[i];
			arr[i] = Aux;
		}
	}
	
	for(i=0; i<M ; i++){
		Aux = arr[i];
		cout<<"Lista: "<<i<<endl;
		while(Aux != NULL){
			cout<< Aux->x << " " << Aux->y << endl;
			Aux = Aux->sig;
		}
		for(Aux = arr[i]->sig ; Aux != NULL; Aux = Aux->sig){
			delete arr[i];
			arr[i] = Aux;
		}
		delete arr[i];
	}
	delete []arr;
	system("PAUSE");
	return EXIT_SUCCESS;
}
