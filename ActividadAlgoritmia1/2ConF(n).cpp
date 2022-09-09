#include<iostream>

using namespace std;

int main(){
	int N, i, j, **a;
	int sum = 0;
    sum += sizeof(N);
    sum += sizeof(i);
    sum += sizeof(j);
    sum += sizeof(a);
	cin>> N;
	a = new int *[N];
	for(i = 0; i<N; i++)
	{
		a[i]= new int [N];
		for(j = 0;j<N; j++)
		{
			a[i][j] = j*i;
			sum += sizeof(**a);
		}		
		sum += sizeof(*a);
	}
	for(i=0;i<N;i++){
		for(j=0;j<N; j++){
			//cout << a[i][j] << "    |   ";
		}
		//cout<<endl;
		delete a[i];
	}
	cout<<"Bytes final: "<<sum;
	delete a;
	return 0;
}
