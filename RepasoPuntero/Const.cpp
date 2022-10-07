#include<iostream>
using namespace std;

int main(){
	int x,y,z;
	int *const p=&x; //si puedo cambiar a donde apunta es decir, cambiar en x, pero no puedo cambiar la direccion de p
	const int *r=&z; //se puede cambiar la direccion pero no el contenido a donde apunta
	const int *const g=&y; //estamos diciendo que tanto la direccion como a donde apunta no se puede cambiar
	//*g=10; -> solo lectura
	*p=7;
	//*r=3; ->solo lectura
	//g=&z; ->Solo lectura
	r=&x;
	//p=&y; ->Solo lectura
	return 0;
}