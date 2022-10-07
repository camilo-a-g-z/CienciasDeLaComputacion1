#include<iostream>
#include <cstdlib>
using namespace std;
void arreglo (int *p){
	int i;
	for (i=0;i<10;i++){
		p[i]=i*2;
	}
}
int main(){
	int i, a[10], *pa, **ppa;
	for(i=0;i<10;i++)
		a[i]=0;
	
	pa=a;
	for(i=0;i<10;i++)
		cout<<pa[i]<<" ";
	
	arreglo(pa);
	cout<<endl;
	ppa=&pa;
	for(i=0;i<10;i++)
		cout<<*(*ppa+i)<<" ";
	cout<<endl;
	system("PAUSE");
	return 0;
}