#include<iostream>

using namespace std;

struct nodo {
	int x, y;
	nodo *sig;
};

int main(){
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
		cout << Aux ->x << " | " << Aux ->y <<endl;
		Aux = Aux -> sig;
	}
	for(Aux = cab -> sig; Aux != NULL; Aux = Aux ->sig){
		delete cab;
		cab= Aux;
	}
	return 0;
}
