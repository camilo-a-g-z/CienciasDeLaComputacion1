#include<iostream>

using namespace std;

struct nodo {
	int x, y;
	nodo *sig;
};

int main(){
	int N, i, j;
	nodo *cab = NULL, *Aux;
	int sum = 0;
    sum += sizeof(N);
    sum += sizeof(i);
    sum += sizeof(j);
    sum += sizeof(cab);
    sum += sizeof(Aux);
	cin >> N;
	for(i=0;i<N;i++){
		Aux = new nodo;
		Aux -> x = i;
		Aux -> y = N-i;
		Aux -> sig = cab;
		cab = Aux;
		sum += sizeof(*Aux);
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
	cout<<"Bytes final: "<<sum;
	
	return 0;
}
