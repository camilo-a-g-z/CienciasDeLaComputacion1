#include <iostream>
#ifndef LISTA_H
#define LISTA_H
//TAREA :
//Utilizar centinelas y cabeceras
//Lista ordenada, imprimirla, eliminar elementos y volver a imprimir en MAIN
template < class T >  
//Estructura a emplear para lista
struct Nodo
{
	T info;
	Nodo<T> *sig;
};
//Template de tipo dato a usar
template < class T >  
class Lista
{
	private:
		Nodo<T> *cab;
		int tam;
	public:
		Lista()
		{
			cab = NULL ; tam = 0;
		};
		//~Lista<T>();
		bool ListaVacia();
		int TamLista();
		bool Insertar(T dato, int pos);
		bool InsertarOrdenado(T dato);
		T Eliminar(int pos);
		T ObtenerDatos(int pos);
};
template < class T >  

bool Lista<T>::ListaVacia(){return (tam == 0);}
template < class T >  
int Lista<T>::TamLista(){return tam;}
template < class T >  

bool Lista<T>::InsertarOrdenado(T dato){
	//se crea nuevo nodo y variables auxiliares necesarias
	Nodo<T> *n_n = new Nodo<T>;
	Nodo<T> *aux, *aux2;
	
	n_n->info = dato;
	aux = cab;
	while(aux->sig != NULL && aux->info < n_n->info) {aux = aux->sig;}
	aux->sig = n_n;
	n_n->sig = NULL;
	aux = cab;
	tam++;
	return true;
}

template < class T >  

bool Lista<T>::Insertar(T dato, int pos){
	//en el caso de que estemos pidiendo un lugar que no se puede
	if(pos > tam + 1){return false;}
	//se crea nuevo nodo y variables auxiliares necesarias
	Nodo<T> *n_n = new Nodo<T>;
	Nodo<T> *aux, *aux2;
	
	n_n->info = dato;
	if(pos == 1)
	{
		n_n->sig=cab;
		cab=n_n;
	} else if(pos == tam+1)
	{
		aux = cab;
		while(aux->sig != NULL) {aux = aux->sig;}
		aux->sig = n_n;
		n_n->sig = NULL;
	}else
	{
		aux = cab;
		for(int i = 1; i < pos-1; i++){aux = aux->sig;}
		aux2 = aux->sig;
		n_n->sig = aux2;
		aux->sig = n_n;
	}
	tam++;
	return true;
}

template < class T >  
T Lista<T>::Eliminar(int pos){
	if(pos > tam + 1){return NULL;}
	Nodo<T> *aux, *aux2;
	Nodo<T> n_d = new Nodo<T>;
	for(int i = 1; i < pos-1; i++){aux = aux->sig;}
	aux2 = aux->sig;
	aux->sig = aux2->sig;
	n_d->info = aux2->info;
	n_d->sig = aux2->sig;
	delete aux2;
	return n_d;
}
#endif
