#include <iostream>
#ifndef ARBOL_H
#define ARBOL_H
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

class Arbol
{
	private:
		Nodo *arbol;
		
	public: 
		Arbol(){
		}
		Nodo *crear_nodo(int, Nodo *);
		void insertar_nodo(Nodo *&, int , Nodo *);
		void mostrar_arbol(Nodo *, int);
		bool buscar_nodo(Nodo *, int);
		void pre_orden(Nodo *);
		void in_orden(Nodo *);
		void post_orden(Nodo *);
		void eliminar(Nodo *, int);
		void eliminar_nodo(Nodo *);
		Nodo *minimo(Nodo *);
		void reemplazar(Nodo *, Nodo *);
		void destruir(Nodo *);
};

//funcion para crear un nuevo nodo
Nodo *Arbol::crear_nodo(int n, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo ();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}

//funcion para asignar valor a nodo
void Arbol::insertar_nodo(Nodo *&arbol, int n, Nodo *padre){
	
	if(arbol == NULL){ //sie el arbol esta vacio
		Nodo *nuevo_nodo = crear_nodo(n,padre);
		arbol = nuevo_nodo;
		cout<<"\nElemento "<<n<<" insertado correctamente."<<endl;
	}else{//si el arbol tiene un nodo o mas de un nodo
		int valRaiz = arbol->dato; //obtenemos el valor de la raiz
		if(n<valRaiz){//si el elemento es menor a la raiz lo insertamos a la izquierda
			insertar_nodo(arbol->izq,n,arbol);
		}else{//si el elemento es mayor de la raiz lo insertamos a la derecha
			insertar_nodo(arbol->der,n,arbol);
		}
	}
}

//funcion para mostrar el arbol verticalmente
void Arbol::mostrar_arbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrar_arbol(arbol->der,cont+1);
		
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		
		cout<<arbol->dato<<endl;
		mostrar_arbol(arbol->izq,cont+1);
	}
}
//funcion para buscar elemento en el arbol
bool Arbol::buscar_nodo(Nodo *arbol, int n){
	if(arbol == NULL){ //sie el arbol esta vacio
		return false;
	}
	else if(arbol->dato == n){ //si el nodo es igual al elemento 
		return true;
	}
	else if(n < arbol->dato){ //si el elemento que estamos buscando es menor al elemento del arbol en el que vamos
		return buscar_nodo(arbol->izq,n);
	}
	else{//si el elemento que estamos buscando es mayor al elemento del arbol en el que vamos
		return buscar_nodo(arbol->der,n);
	}
}

//funcion para recorrer el arbol en profundidad preOrden: raiz-izquierda-derecha
void Arbol::pre_orden(Nodo *arbol){
	if(arbol == NULL){//si el arbol esta vacio
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		pre_orden(arbol->izq);
		pre_orden(arbol->der);
	}
}
//funcion para recorrer el arbol en profundidad en InOrden : izquierda-raiz-derecha
void Arbol::in_orden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		in_orden(arbol->izq);
		cout<<arbol->dato<<" - ";
		in_orden(arbol->der);
	}
}
//funcion para recorrer el arbol en profundidad en PostOrden : izquierda -derecha - raiz
void Arbol::post_orden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		post_orden(arbol->izq);
		post_orden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}
//funcion para eliminar nodo encontrado
void Arbol::eliminar_nodo(Nodo *nodo_eliminar){
	if(nodo_eliminar->der &&nodo_eliminar->izq){//si el arbol tiene hiho izq y der
		Nodo *menor = minimo(nodo_eliminar->der);
		nodo_eliminar->dato = menor->dato;
		eliminar_nodo(menor);
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
	if(arbol==NULL){//si el arbol esta vacio
		return;//no hacer nada
	}
	else if(n < arbol->dato){//si el valor es menor
		eliminar(arbol->izq,n);//buscar por la izq
	}
	else if(n >arbol->dato){//si el valor es mayor
		eliminar(arbol->der,n);//buscar por la der
	}
	else{//si ya encontraste el elemento
		eliminar_nodo(arbol);
	}
}
//funcion para determinar el nodo mas izquierdo posible
Nodo *Arbol::minimo(Nodo *arbol){
	if(arbol == NULL){//si el arbol esta vacio
		return NULL;//retornar nulo
	}
	if(arbol->izq){//si tiene hijo izq
		return minimo(arbol->izq);//buscar la parte mas izq posible
	}else{//si no tiene hijo izquierdo 
		return arbol;//retornamos el mismpo onodo
	}
}
//funcion para reeemplazar dos nodos
void Arbol::reemplazar(Nodo *arbol, Nodo *nuevo_nodo){
	if(arbol->padre){
		//arbol->padre hay que asignarle su nuevo hijo
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevo_nodo;
		}else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevo_nodo;	
		}
	}
	if(nuevo_nodo){
		//procedemos a asignarle su nuvo padre
		nuevo_nodo->padre = arbol->padre;
	}
}
//funcion para destruir un nodo
void Arbol::destruir(Nodo *nodo){
	nodo->der = NULL;
	nodo->izq = NULL;
	
	delete nodo;
}


#endif
