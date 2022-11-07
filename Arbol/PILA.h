#ifndef PILAEDD2_H
#define PILAEDD2_H
template < class T > 
class Pila
{ T *pila;
  int p;
	public:
  		Pila (int f)
   			{pila = new T[100]; p=0;}
		~Pila()
   			{delete pila;}
		inline void meter (T v)
   			{pila[p++]=v;}
		inline T sacar()
  			{return pila [--p];}
		inline int vacia()
		  {return !p;} 
};
#endif
