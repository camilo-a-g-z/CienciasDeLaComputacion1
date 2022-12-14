/*
	Integrantes:
	Camilo Andres Garcia Zambrano(20201020047)
	Miguel Angel Veloza Ortiz(20192020012)
*/

#include <iostream>
#include "PILA.h"
#include "queue.h"
#ifndef ARBOL_H
#define ARBOL_H
using namespace std;

struct Nodo{
	//segun tarea es el ID
	int dato;
	int info;
	Nodo *der;
	Nodo *izq;
};

class Arbol
{
	private:
		Nodo *raiz;
		//colaIn de enteros que es la que se va a retornar
		Queue<int> colaIn;
		Queue<int> colaPs;
		Queue<int> colaPre;
		Queue<int> colaPos;
		Nodo *crear_nodo(int, int);
		void insertar_nodo(Nodo *&, int, int);
		void mostrar_arbol(Nodo *, int);
		Nodo *buscar_padre(Nodo *, int);
		
		void eliminar(Nodo *, int);
		void eliminar_nodo(Nodo *);
		Nodo *minimo(Nodo *);
		void reemplazar(Nodo *, Nodo *);
		void destruir(Nodo *);
		Nodo *buscar_nodo(Nodo *, int);
	public: 
		Arbol(){
			raiz = NULL;
		}
		Nodo *buscar_nodo_p(int);
		void insertar_nodo_p(int, int);
		void mostrar_arbol_p();
		void eliminar_p(int);
		bool arbol_vacio();
		Queue<int> pre_orden();
		Queue<int> in_orden();
		Queue<int> post_orden();
};
//funcion para saber si el arbol esta vacio
bool Arbol::arbol_vacio(){return raiz == NULL ? true : false;}

//Metodo para buscar nodo publico, se creo este metodo para simplificar acceso
//desde fuerda de la clase y lograr hacer un metodo recursivo
Nodo *Arbol::buscar_nodo_p(int n){
	return buscar_nodo(raiz,n);
}
//Metodo para eliminar publico, se creo este metodo para simplificar acceso
//desde fuerda de la clase y lograr hacer un metodo recursivo
void Arbol::eliminar_p(int n){
	eliminar(raiz,n);
}
//Metodo para mostrar arbol publico, se creo este metodo para simplificar acceso
//desde fuerda de la clase y lograr hacer un metodo recursivo
void Arbol::mostrar_arbol_p(){
	mostrar_arbol(raiz,0);
}
//Metodo para insertar publico, se creo este metodo para simplificar acceso
//desde fuerda de la clase y lograr hacer un metodo recursivo
void Arbol::insertar_nodo_p(int n, int info){
	insertar_nodo(raiz,n,info);
}
//funcion para crear un nuevo nodo
Nodo *Arbol::crear_nodo(int n, int info){
	Nodo *nuevo_nodo = new Nodo ();
	nuevo_nodo->dato = n;
	nuevo_nodo->info = info;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}
//funcion para asignar valor a nodo
void Arbol::insertar_nodo(Nodo *&arbol, int n, int info){
	if(arbol == NULL){ //sie el arbol esta vacio
		Nodo *nuevo_nodo = crear_nodo(n,info);
		arbol = nuevo_nodo;
		cout<<"\nElemento "<<n<<" insertado correctamente."<<endl;
	}else{//si el arbol tiene un nodo o mas de un nodo
		int valRaiz = arbol->dato; //obtenemos el valor de la raiz
		if(n<valRaiz){//si el elemento es menor a la raiz lo insertamos a la izquierda
			insertar_nodo(arbol->izq,n,info);
		}else if(n>valRaiz){//si el elemento es mayor de la raiz lo insertamos a la derecha
			insertar_nodo(arbol->der,n,info);
		}else{//en caso de que el valor ya exista
			cout<<"Nodo ya existente"<<endl;
		}
	}
}
//funcion para mostrar el arbol verticalmente
void Arbol::mostrar_arbol(Nodo *arbol, int cont){
	if(arbol == NULL){return;}
	else{
		mostrar_arbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){cout<<"   ";}
		cout<<arbol->dato<<endl;
		mostrar_arbol(arbol->izq,cont+1);
	}
}
//funcion para buscar elemento en el arbol
Nodo *Arbol::buscar_nodo(Nodo *arbol, int n){
	//si el arbol esta vacio
	if(arbol == NULL){return NULL;}
	//si el nodo es igual al elemento 
	else if(arbol->dato == n){return arbol;}
	//si el elemento que estamos buscando es menor al elemento del arbol en el que vamos
	else if(n < arbol->dato){return buscar_nodo(arbol->izq,n);}
	//si el elemento que estamos buscando es mayor al elemento del arbol en el que vamos
	else{return buscar_nodo(arbol->der,n);}
}

Nodo *Arbol::buscar_padre(Nodo *padre, int n){
	//si el arbol esta vacio
	if(padre == NULL){return NULL;}
	//si el nodo es igual al elemento quiere decir que es la raiz
	else if(padre->dato == n){return NULL;}
	//si alguno de los hijos es el datos se encontro el padre
	else if(padre->der->dato == n  ||  padre->izq->dato == n){return padre;}
	//si el elemento que estamos buscando es menor al elemento del arbol en el que vamos
	else if(n < padre->dato){return buscar_padre(padre->izq,n);}
	//si el elemento que estamos buscando es mayor al elemento del arbol en el que vamos
	else{return buscar_padre(padre->der,n);}
}

//funcion para recorrer el arbol en profundidad preOrden: raiz-izquierda-derecha
Queue<int> Arbol::pre_orden(){
	while(!colaPre.QueueVacia())
		colaPre.deQueue('I');
	//Pila de Nodos
	Pila<Nodo*> pila(100);
	//Auxiliar que apunta a la raiz	
	Nodo *aux = raiz;
	if(aux == NULL){return colaPre;}
	pila.meter(aux);
	while(!pila.vacia()){
		aux = pila.sacar();
		colaPre.enQueue(aux->dato,'I');
		if(aux->der != NULL){
			pila.meter(aux->der);
		}
		if(aux->izq != NULL){
			pila.meter(aux->izq);
		}
	}																			
	return colaPre;
}
//funcion para recorrer el arbol en profundidad en InOrden : izquierda-raiz-derecha
Queue<int> Arbol::in_orden(){
	
	while(!colaIn.QueueVacia())
		colaIn.deQueue('I');
	//Pila de Nodos
	Pila<Nodo*> pila(100); //s
	//Auxiliar que apunta a la raiz	
	Nodo *aux = raiz; //nodo	
	while(!pila.vacia() || aux != NULL){
		if(aux != NULL){
			pila.meter(aux);
			aux = aux->izq;
		}else{
			aux = pila.sacar();
			colaIn.enQueue(aux->dato,'I');
			aux = aux->der;
		}
	}																	
	return colaIn;
}
//funcion para recorrer el arbol en profundidad en PostOrden : izquierda -derecha - raiz
Queue<int> Arbol::post_orden(){
	while(!colaPos.QueueVacia())
		colaPos.deQueue('I');
	//Pila de Nodos
	Pila<Nodo*> pila(100);
	//Auxiliar que apunta a la raiz	
	Nodo *aux = raiz; 
	Nodo *aux2 = NULL;
	Nodo *aux3 = NULL;
	//iteramos hasta vaciar la pila y terminar recorrido
	while(!pila.vacia() || aux != NULL){
		if(aux != NULL){
			//hacemos recorrido a la izq
			pila.meter(aux);
			aux = aux->izq;
		}else{
			//revisamos elemento actual de pila
			aux3 = pila.sacar();
			pila.meter(aux3);
			if(aux3->der != NULL && aux2 != aux3->der){
				//hacemos recorrido a la derecha
				aux = aux3->der;
			}else{
				//metemos en cola cuando ya se recorrio 
				colaPos.enQueue(aux3->dato,'I');
				//se saca de la pila
				aux2 = pila.sacar();
			}
		}
	}
	return colaPos;
}
//funcion para eliminar nodo encontrado
void Arbol::eliminar_nodo(Nodo *nodo_eliminar){
	if(nodo_eliminar->der &&nodo_eliminar->izq){//si el arbol tiene hiho izq y der
		Nodo *menor = minimo(nodo_eliminar->der);
		int d = menor->dato;
		eliminar_nodo(menor);
		nodo_eliminar->dato = d;
	}
	else if(nodo_eliminar->izq){//si tiene hijo izquierdo
		reemplazar(nodo_eliminar, nodo_eliminar->izq);
		destruir(nodo_eliminar);
		cout<<"\nElemento destruido correctamente."<<endl;
	}
	else if(nodo_eliminar->der){//si tiene hijo derecho
		reemplazar(nodo_eliminar, nodo_eliminar->der);
		destruir(nodo_eliminar);
		cout<<"\nElemento destruido correctamente."<<endl;
	}
	else{//si un nodo no tiene hijos
		reemplazar(nodo_eliminar, NULL);
		destruir(nodo_eliminar);
		cout<<"\nElemento destruido correctamente."<<endl;
	}
}
//Funcion para eliminar Nodos del arbol
void Arbol::eliminar(Nodo *arbol, int n){
	//si el arbol esta vacio
	if(arbol==NULL){return;}
	//si el valor es menor buscar por la izq
	else if(n < arbol->dato){eliminar(arbol->izq,n);}
	//si el valor es mayor buscar por la der
	else if(n >arbol->dato){eliminar(arbol->der,n);}
	//si ya encontraste el elemento
	else{eliminar_nodo(arbol);}
}
//funcion para determinar el nodo mas izquierdo posible
Nodo *Arbol::minimo(Nodo *arbol){
	//si el arbol esta vacio
	if(arbol == NULL){return NULL;}
	//si tiene hijo izq buscar la parte mas izq posible
	if(arbol->izq){return minimo(arbol->izq);}
	//si no tiene hijo izquierdo retornamos el mismo nodo
	else{return arbol;}
}
//funcion para reeemplazar dos nodos
void Arbol::reemplazar(Nodo *arbol, Nodo *nuevo_nodo){
	//buscamos el padre
	Nodo *padre = buscar_padre(raiz,arbol->dato);
	if(padre != NULL){
		//arbol->padre hay que asignarle su nuevo hijo
		if(arbol->dato == padre->izq->dato){
			padre->izq = nuevo_nodo;
		}else if(arbol->dato == padre->der->dato){
			padre->der = nuevo_nodo;	
		}
	}
}
//funcion para destruir un nodo
void Arbol::destruir(Nodo *nodo){
	nodo->der = NULL;
	nodo->izq = NULL;
	
	delete nodo;
}

#endif
