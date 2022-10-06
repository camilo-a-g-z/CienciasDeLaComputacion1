#include <iostream>
#include <stdlib.h>

using namespace std;

void janoi(char varilla_inicial, char  varilla_central, char varilla_final, int n){
	if(n == 1){//caso basse
		cout<<"\nMover disco "<<n<<" desde la variila "<<varilla_inicial
		<<" a varilla "<<varilla_final;
	}
	else{//caso recursivo
		janoi(varilla_inicial, varilla_final, varilla_central,n-1);
		cout<<"\nMover disco "<<n<<" desde la varilla "<<varilla_inicial
		<<" a varilla "<<varilla_final;
		janoi(varilla_central, varilla_inicial, varilla_final, n-1);
	}
	
}

int main(){
	janoi('A','B','C',7);
	cout<<endl;
	system("pause");
	return 0;
}
