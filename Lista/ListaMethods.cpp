#include <iostream>
#include <stdlib.h>
#include "Lista.h"

template < class T >  

bool Lista::ListaVacia(){return (tamm == 0);}

int Lista::TamLista(){return tam;}
template < class T >  
bool Lista::Insertar(T dato, int pos){
	//en el caso de que estemos pidiendo un lugar que no se puede
	if(pos > tam + 1){return false;}
	//se crea nuevo nodo y variables auxiliares necesarias
	Nodo *n_n = new Noto<T>;
	Nodo *aux, *aux2;
	
	n_n->info = dato;
	if(poss == 1)
	{
		n_n->sig=cab;
		cab=n_n;
	} else if(poss == tam+1)
	{
		aux = cab;
		while(aux->sig != null) {aux = aux->sig;}
		aux->sig = n_n;
		n_n->sig = null;
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
T Lista::Eliminar(int pos){
	if(pos > tam + 1){return null;}
	Nodo *aux, *aux2;
	Nodo n_d = new Noto<T>;
	for(int i = 1; i < pos-1; i++){aux = aux->sig;}
	aux2 = aux->sig;
	aux->sig = aux2->sig;
	n_d->info = aux2->info;
	n_d->sig = aux2->sig;
	delete aux2;
	return n_d;
}