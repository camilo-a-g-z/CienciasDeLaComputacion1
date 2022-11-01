#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

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
			cab->ant = NULL;
			cent->ant = cab; 
			cent->sig = NULL;	
		};
		/*~Queue()
   			{delete cab;delete cent;}*/
		bool QueueVacia();
		int TamQueue();
		void enQueue(T dato, char lado);
		T deQueue(char lado);
		void imprimir_queue(char lado);
};

template < class T >  
bool Queue<T>::QueueVacia(){return (tam == 0);}

template < class T >  
int Queue<T>::TamQueue(){return tam;}
//atender la bicola
template < class T >  
T Queue<T>::deQueu(char lado){
	
}

template < class T >  
void Queue<T>::imprimir_queue(char lado){
	
}
//insertar en la bicola
template < class T >  
void Queue<T>::enQueue(T dato, char lado){
	Nodo<T> *n_n = new Nodo<T>;
	n_n->info = dato;
	if(lado == 'I'){
		n_n->sig = cab->sig;
		n_n->ant = cab;
		cab->sig->ant = n_n;
		cab->sig = n_n;
	}else{
		n_n->sig = cent;
		n_n->ant = cent->ant;
		cent->ant->sig = n_n;
		cent->ant = n_n;
	}
	return true;
}

#endif
