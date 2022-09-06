#include<iostream>

using namespace std;

int main(){
	int N, i, j, **a;
	cin>> N;
	a = new int *[N];
	for(i = 0; i<N; i++){
		a[i]= new int [N];
		for(j = 0;j<N; j++){
			a[i][j] = j*i;
		}		
	}
	for(i=0;i<N;i++){
		for(j=0;j<N; j++){
			cout << a[i][j];
		}
		cout<<endl;
		delete a[i];
	}
	delete a;
}
