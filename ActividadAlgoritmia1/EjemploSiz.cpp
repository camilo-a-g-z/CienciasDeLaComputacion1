#include <iostream>
using namespace std;
int main(){
    //declaracion variables
    int i, *P;
    long n;
    float j, *q;
    double k;
    char c;
    unsigned l;
    bool b;
    P = new int[20];
    //impresión de sizeof
    cout<<"Size of int i: "<<sizeof(i)<<endl; //Cuanta memoria reserva en bytes para la var i -> 4 bytes = 32 bits
    cout<<"Size of float j: "<<sizeof(j)<<endl;
    cout<<"Size of int P: "<<sizeof(*P)<<endl; //con * nos referimos al lugar donde estamos apuntando
    cout<<"Size of char c: "<<sizeof(c)<<endl;
    cout<<"Size of unsigned l: "<<sizeof(l)<<endl;
    cout<<"Size of long n: "<<sizeof(n)<<endl;
    cout<<"Size of float q: "<<sizeof(q)<<endl;
    cout<<"Size of bool b: "<<sizeof(b)<<endl;
	return EXIT_SUCCESS;
}
