#include <iostream>

using namespace std;

int main()
{
    int N, i, j, *a;
    int sum = 0;
    cin>> N;
    sum += sizeof(N);
    sum += sizeof(i);
    sum += sizeof(j);
    sum += sizeof(a);
    
    for (i=0;i<N;i++){
        a= new int [N];
        for(j=0;j<N;j++){
            a[j]=j*i;
            //cout<<a[j]<<" | ";
            //cout<< "numero" <<a[j]<<"   |   ";
            //cout<< "direccion: " << &a[j]<<endl;
            //sum += sizeof(a[j]);
            //cout<<"Tamaño: "<<sizeof(a[j])<<" ";
        }
        sum += sizeof(*a);
        //cout<<endl;
        delete []a;
    }
    cout<<"Bytes final: "<<sum;
    return 0;
}
