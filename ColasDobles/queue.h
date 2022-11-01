#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
//TAREA :
//Queue ordenada, imprimirla, eliminar elementos y volver a imprimir en MAIN
template < class T >  
//Estructura a emplear para Queue
struct Nodo
{
	T info;
	Nodo<T> *sig;
	Nodo<T> *ant;
};
//Template de tipo dato a usar
template < class T >  
class Queue
{
	private:
		Nodo<T> *cab;
		Nodo<T> *cent;
		int tam;
	public:
		Queue()
		{
			cab = new Nodo<T>; 
			tam = 0; 
			cent = new Nodo<T>;
			cab->sig = cent; 
			cent->sig = NULL;	
		};
		//~Queue<T>();
		bool QueueVacia();
		int TamQueue();
		void enQueue(T dato, int pos);
		T deQueue(int pos);
		void imprimir_queue(char lado);
};

template < class T >  
bool Queue<T>::QueueVacia(){return (tam == 0);}

template < class T >  
int Queue<T>::TamQueue(){return tam;}

template < class T >  
T Queue<T>::dequeue(int pos){
	
}

template < class T >  
void Queue<T>::imprimir_queue(char lado){
	
}

template < class T >  
void Queue<T>::enQueue(T dato){
	
	return true;
}

#endif
