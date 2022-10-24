#include <iostream>
#include "PILAEDD2.h"

using namespace std;

int main(int argc, char** argv) {
	char c; Pila acc(50); int x;

	while(cin.get(c) && c != '\n')
	{	x=0;
		while (c==' ') {cin.get(c);} 
		while(c>= '0' && c<='9')
		{x=10*x + (c-'0'); cin.get(c);}
		if (c == '+') x= acc.sacar() + acc.sacar();
		if (c== '*') x= acc.sacar() * acc.sacar();
		acc.meter(x);

	}
	cout << acc.sacar()<< '\n';
	return 0;
}
