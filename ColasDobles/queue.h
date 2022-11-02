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
		//cabeza de la Queue
		Nodo<T> *cab;
		//cola de la Queue
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
		bool QueueVacia();
		int TamQueue();
		void enQueue(T dato, char lado);
		T deQueue(char lado);
		void imprimir_queue(char lado);
};

//Método para vaciar la Queue
template < class T >  
bool Queue<T>::QueueVacia(){return (tam == 0);}

//Método para obtener el tamanio de la Queue
template < class T >  
int Queue<T>::TamQueue(){return tam;}

//atender la Queue
template < class T >  
T Queue<T>::deQueue(char lado){
	//se verifica si la bicola esta vacia
	if(tam != 0){
		Nodo<T> *n_n = new Nodo<T>;
		//Si es por la izquierda atiende desde la izquierda
		if(lado == 'I'){
			n_n->info = cab->sig->info;
			n_n->sig = cab->sig;
			//Asigna el apuntador a cabeza al nodo anterior
			cab->sig->sig->ant = cab;
			cab->sig = n_n->sig->sig;
			//eliminamos el nodo que sacamos de memoria
			delete n_n->sig;
		}else{
			n_n->info = cent->ant->info;
			n_n->ant = cent->ant;
			//Asigna el apuntador a cent al nodo siguiente
			cent->ant->ant->sig = cent;
			cent->ant = n_n->ant->ant;
			//eliminamos el nodo que sacamos de memoria
			delete n_n->ant;
		}
		tam--;
		return n_n->info;
	}
	return NULL;
}

//Imprimir Queue
template < class T >  
void Queue<T>::imprimir_queue(char lado){
	if(lado == 'I'){
		//Auxiliar para que recorra la Queue nodo por nodo desde la cabe
		Nodo<T> *aux;
		aux = cab;
		while(aux->sig != cent){
			cout<<aux->sig->info<<" | ";
			aux=aux->sig;
		}
	}else{
		//Auxiliar para que recorra la Queue nodo por nodo desde la cola
		Nodo<T> *aux;
		aux = cent;
		while(aux->ant != cab){
			cout<<aux->ant->info<<" | ";
			aux=aux->ant;
		}
	}
}

//insertar en la bicola
template < class T >  
void Queue<T>::enQueue(T dato, char lado){
	Nodo<T> *n_n = new Nodo<T>;
	n_n->info = dato;
	//para insertar a la bicola desde la derecha
	if(lado == 'D'){
		n_n->sig = cab->sig;
		n_n->ant = cab;
		cab->sig->ant = n_n;
		cab->sig = n_n;
	//para insertar a la bicola desde la izquierda
	}else{
		n_n->sig = cent;
		n_n->ant = cent->ant;
		cent->ant->sig = n_n;
		cent->ant = n_n;
	}
	tam++;
}

#endif