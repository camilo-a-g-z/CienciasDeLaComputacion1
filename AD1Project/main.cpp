#include <iostream>
#include "Lista.h"
using namespace std;

struct Targeta{
	string color;
	int dia;
	int mes;
	int anio;
	string motivo;
	string contrincante;
};

struct Jugador{
	string nombre;
	string pos;
	int numCamisa;
	int edad;
	string talla;
	Lista<Targeta> targetas;
};

struct Equipo{
	string nombre;
	string nombreEntrenador;
	string confederacion;
	Lista<Jugador> jugadores;
};

int main(){
	Lista<Equipo> equipos;

	for(int l=1;l<3;l++){
		Equipo colombia;
		colombia.confederacion = "conf"+l;
		colombia.nombre = "nom"+l;
		colombia.nombreEntrenador = "entrenador"+l;
		for(int m=1;m<3;m++){
			Jugador j1;
			j1.nombre = "nom"+m;
			j1.edad = 30+m;
			j1.numCamisa = m;
			j1.pos = "def"+m;
			j1.talla = "XL";
			for(int n =1;n<3;n++){
				Targeta tar1;
				tar1.color="Roja";
				tar1.dia = 10+n;
				tar1.mes=10;
				tar1.anio=2002;
				tar1.contrincante="equOtro"+n;
				tar1.motivo="Le partio la pierna al compa";
				j1.targetas.Insertar(tar1,n);
			}
			colombia.jugadores.Insertar(j1,m);
		}
		equipos.Insertar(colombia,l);
	}
	
	for(int i = 1; i<=equipos.TamLista();i++){
		Equipo  e = equipos.ObtenerDatos(i);
		cout<<"Conf: "<<e.confederacion<<endl;
		cout<<"Nombre Equipo: "<<e.nombre<<endl;
		cout<<"Nom entrenador: "<<e.nombreEntrenador<<endl;
		cout<<"Jugadores:"<<endl;
		for(int j = 1; j<=e.jugadores.TamLista();j++){
			Jugador player = e.jugadores.ObtenerDatos(j);
			cout<<"\tNombre: "<<player.nombre<<endl;
			cout<<"\tEdad: "<<player.edad<<endl;
			cout<<"\tNumero de camisa: "<<player.numCamisa<<endl;
			cout<<"\tPosicion: "<<player.pos<<endl;
			cout<<"\tTalla: "<<player.talla<<endl;
			cout<<"\tTargetas: "<<endl;
			for(int k = 1; k<=player.targetas.TamLista();k++){
				Targeta t = player.targetas.ObtenerDatos(k);
				cout<<"\t\tMotivo: "<<t.motivo<<endl;
				cout<<"\t\tDia: "<<t.dia<<endl;
				cout<<"\t\tMes: "<<t.mes<<endl;
				cout<<"\t\tAño: "<<t.anio<<endl;
				cout<<"\t\tColor: "<<t.color<<endl;
				cout<<"\t\tContrincante: "<<t.contrincante<<endl;
				cout<<"\n";
			}
		}
	}
	
	return 0;
}
