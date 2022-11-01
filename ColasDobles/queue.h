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
		bool enQueue(T dato, int pos);
		T deQueue(int pos);
		void imprimir_queue();
};

template < class T >  
bool Queue<T>::QueueVacia(){return (tam == 0);}

template < class T >  
int Queue<T>::TamQueue(){return tam;}

template < class T >  
T Queue<T>::ObtenerDatos(int pos){
	Nodo<T> *aux;
	aux = cab->sig;
	for(int i = 1; i < pos; i++){aux = aux->sig;}
	return aux->info;
}

template < class T >  
T Queue<T>::Eliminar(int pos){
	//en el caso de que estemos pidiendo un lugar que no se puede
	if(pos > tam + 1){return NULL;}
	//se crea nuevo nodo y variables auxiliares necesarias
	Nodo<T> *n_n = new Nodo<T>;
	Nodo<T> *aux, *aux2;
	aux = cab;
	for(int i = 0; i < pos-1; i++){aux = aux->sig;}
	aux2 = aux->sig;
	n_n->info = aux2->info;
	aux->sig = aux2->sig;
	delete aux2;
	tam --;
	return n_n->info;
}

template < class T >  
void Queue<T>::mostrar(){
	Nodo<T> *aux;
	aux = cab->sig;
	while(aux->sig != NULL) 
	{
		cout<<aux->info<<" | ";
		aux = aux->sig;
	}
	cout<<endl;
}

template < class T >  
bool Queue<T>::enQueue(T dato){
	//se crea nuevo nodo y variables auxiliares necesarias
	Nodo<T> *n_n = new Nodo<T>;
	Nodo<T> *aux, *aux2;
	
	n_n->info = dato;
	aux = cab;
	
	for(int i = 0; i < pos-1; i++){aux = aux->sig;}
	aux2 = aux->sig;
	n_n->sig = aux2;
	aux->sig = n_n;
	
	tam++;
	return true;
}

#endif
