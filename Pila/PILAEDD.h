#ifndef PILA_H
#define PILA_H

class Pila
{public:
      Pila (int max);
   ~Pila();
      void meter(char V);
      char sacar();
     int vacia();
 private:
    struct nodo
       {char clave; struct nodo *siguiente;};
   struct  nodo *cabeza, *z;
 };
 Pila::Pila(int max)
{ cabeza = new nodo;  z=new nodo;
  cabeza->siguiente=z; z->siguiente =z;
}

Pila::~Pila()
{struct nodo *t=cabeza;
 while (t!=z)
       {cabeza=t;  t->siguiente;  delete cabeza;}
}

void Pila:: meter (char V)
{struct nodo *t=new nodo;
 t->clave = V;  t->siguiente=cabeza->siguiente;
cabeza->siguiente=t;
}

char Pila:: sacar()
{char x;
 struct nodo *t = cabeza->siguiente;
cabeza->siguiente = t->siguiente; x=t->clave;
delete t; return x;
}

int Pila::vacia()
{return cabeza->siguiente == z;}

#endif

