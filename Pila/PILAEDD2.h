#ifndef PILAEDD2_H
#define PILAEDD2_H

class Pila
{ int *pila;
  int p;
	public:
  		Pila (int max=100)
   			{pila = new int[max]; p=0;}
		~Pila()
   			{delete pila;}
		inline void meter (int v)
   			{pila[p++]=v;}
		inline int sacar()
  			{return pila [--p];}
		inline int vacia()
		  {return !p;} 
};
#endif

