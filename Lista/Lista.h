#include <iostream>
#ifndef PARQUEADERO_H
#define PARQUEADERO_H

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
		~Lista();
		bool ListaVacia();
		int TamLista();
		bool Insertar(T dato, int pos);
		T Eliminar(int pos);
		T ObtenerDatos(int pos);
};
#endif