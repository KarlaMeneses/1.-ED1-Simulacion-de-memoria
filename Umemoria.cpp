//---------------------------------------------------------------------------

#pragma hdrstop

#include "Umemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>   //  { Para poder usar el cout<< }
#include <iomanip>    //  { Para usar el setw }

//#include <ctype.h>//////////para la funcion esalpha
#include<string>
//using namespace std;
//#include <stdio.h>
//#include <ctype.h>

/************METODOS AUXILIARES ***********************************************/
void trim(string& cadena_id) {
	int i = 0;
	while(i < cadena_id.length())
	{
		if (cadena_id[i] ==' ' && (cadena_id[i+1] == ' ' || i+1==cadena_id.length() || i==0 )) // si se encuentra espacio y (el siguiente es espacio, estamos en la ultima posicion, estamos al principio)
		{
			cadena_id.erase(i, 1); //borramos el espacio incorrecto
		}
		else {
			i++;
		}
	}
}
//
//bool es_separador(char z){  //wchar_t
//	string  separadores= " ,.-,_:;�?!�";
//	return	separadores.Pos(z)>0;
//}
//

int numero_ids(string cadena_id){
	int cont=0;
	for (int i = 0; i < cadena_id.length(); i++) {
		if (cadena_id[i]==',') {
			cont++;
		}
	}
	cont++;
	return cont;
}

string obtener_id(string cadena_id,int &�){//
	string palabra="";   //"hola  ,  como estan ,????"
	int i=0;             // 0123456789
	int aux=�;
	string prueba=cadena_id;
	while (palabra==""){
		if (cadena_id[�]==',' || ((aux+i)==cadena_id.length()-1) ) {
			palabra=cadena_id.substr(aux,i);
			if ((aux+i)==cadena_id.length()-1) {
				palabra=cadena_id.substr(aux,i+1);
			}
		}
		i++;
		�++;
	}
	trim(palabra);
	return palabra;
}


string Eliminar_flecha(string cadena_id){ //Entra si tiene una flecha, ya verificada sin espacios
	cadena_id.erase(0,2);
	return cadena_id;
}

//-----------Funciones y procesos auxiliares---------------
//Mayuscula
void ConverMay(string &cad){
	int n=cad.length();
	for (int i = 0; i < n; i++) {
		cad[i]=toupper(cad[i]);
	}
}
//Contador de comillas
int contdordec(string pal){
	int n=pal.length();
	int j=1;
	for (int i = 0; i < n; i++) {
		if (pal[i]==',') {
			j++;
		}
	}
	return j;
}
//almacenador de palbra nueva
string palnew(string cad){
int i=cad.rfind('>');
string cadnueva="";
cadnueva=cad.substr(i+1);cad;
return cadnueva;
}

/************METODOS DE LA CLASE MEMORIA***************************************/
CSMemoria::CSMemoria(){
	for (int i = 0; i < MAX; i++) {
		MEM[i].Link=i+1;
		MEM[i].Dato=0;
	}
	MEM[MAX-1].Link=-1;
	MEM[MAX-1].Dato=0;
	Libre =0;
}

direccion CSMemoria::new_espacio(string cadena_id){
	int d=Libre;
	int dir=Libre;
	int �=0;
	trim(cadena_id);
	int cant=numero_ids(cadena_id);
	for (int i=0; i < cant-1; i++) {
		MEM[d].Id=obtener_id(cadena_id,�);
		d=MEM[d].Link;
	}
	Libre=MEM[d].Link;
	MEM[d].Link=-1;
	MEM[d].Id=obtener_id(cadena_id,�);
	return dir;
}

void CSMemoria::poner_dato(int dir,string cadena_id,int valor ){
	trim(cadena_id);
	int z=dir;  //dir direccion de la variable E.g: dir=3
	if ((cadena_id[0] == '-') && (cadena_id[1] == '>')) {
		cadena_id=Eliminar_flecha(cadena_id);
		while (z != NULO){  //mientras que mi direccion de variable sea diferente a fin de direccion (-1)
			if (MEM[z].Id == cadena_id) {
				MEM[z].Dato= valor;//????
			}
			z=MEM[z].Link;
		}
	}else{
		cout << "ERROR, Verificar el valor asignado: "<<cadena_id<<endl;
		cout << "Ejemplo: hola mundo \n " << "Insertar con la flecha: '->hola mundo'"<<endl;
	}
}


int CSMemoria::obtener_dato(int dir,string cadena_id){
	int z=dir;
	bool ex=false;
	//Eliminar_flecha(cadena_id);
	cadena_id=Eliminar_flecha(cadena_id); //last modified
	while(z!=NULO){
		if (MEM[z].Id == cadena_id){
			return MEM[z].Dato;
		}
		z=MEM[z].Link;
	}
}

void CSMemoria::delete_espacio(int dir){  //
	int x=dir;
	while(MEM[x].Link!=-1){
		x=MEM[x].Link;
	}
	MEM[x].Link=Libre;
	Libre=dir;
}

int CSMemoria::espacio_disponible(){
	int x= Libre;
	int c=0;
	while (x!=-1){
		c++;
		x=MEM[x].Link;
	}
	return c;
}

int CSMemoria::espacio_ocupado(){ ///La inversa
	//int c =(MAX+1) - espacio_disponible();
	int c =MAX - espacio_disponible();//last modified
	return c;
}

bool CSMemoria::dir_libre(int dir){ ///
	int x=Libre; bool c=false;
	while (x!=-1 && c==false){
		if (x==dir) {
			c=true;
		}
		x=MEM[x].Link;
	}
	return c;
}

void CSMemoria::mostrar_memoria(){
	cout.fill('-'); // rellena los espacios vacios con el char asigando
	cout << "+" << setw(6) << "-" << setw(15) << "-" << setw(10) << setw(7)
		<< "-" << setw(10) << "+" << endl;
	cout << "|" << " DIR " << "|" << "  DATO  " << "|" << "      ID       |" <<
		" LINK |" << endl;
	for (int i = 0; i < MAX ; i++) { //{ MAX+1 wait! }
		cout.fill('-');//RELLENA TODOS LOS ESPACIOS EN BLANCO
		cout << "+" << setw(6) <<  "-" << setw(10)<< "-" << setw(15)
			<< "-" <<setw(7)<< "+" << endl;
		cout.fill(' ');
		cout << "|";

		cout.width(5); //distancia del proximo cout e.g.: 40 hasta la distacia 5
		cout << i << "|";

		cout.width(8);
		cout << MEM[i].Dato << "|";

		cout.width(15);
		cout << MEM[i].Id << "|";

		cout.width(6);

		cout << MEM[i].Link << "|" << endl;
	}
	cout.fill('-');
	cout << "+" << setw(6) << "+" << setw(9) << "+" << setw(16) << "+" << setw(7)
		<< "+" << endl;
	cout.fill(' ');
	//setw() = espacios en blancos hasta cierto punto
	cout<<"Libre: "<<Libre<<endl;
}

bool CSMemoria::lleno() { // me dice si consumio toda la memoria de libre
	return espacio_disponible() == 0; // max=10   0=false; 1=true;
}

bool CSMemoria::vacio() { // Me indica si esta limpio la memoria
	return espacio_disponible() == MAX;
}

int CSMemoria::Obtener_Link(int dir){
   return MEM[dir].Link;
}

bool CSMemoria::Estado_Dir(int dir){
	 if (dir>=0 && dir<MAX){
		bool sw = false;
		int x = Libre;
		while (x!=-1 && !sw){
		   if(x==dir){
			  return true; //si esta libre
		   }
		   x=MEM[x].Link;
		}
		return false; //esta ocupado
	 }else{
		return false;
	 }
}

void CSMemoria::NuevoMostrar(char z){
	if (z=='o'||z=='O') {
		cout << "OCUPADO VERSION" << endl;
		cout << "------------------------------------" << endl;
		cout << "        Dato   Link    " << endl;
		int y;
		for (int i = 0; i < MAX; i++) {
		   if(!Estado_Dir(i)){
			   cout<<"   "<<i<<"     "<<" [ "<<MEM[i].Dato<<"  ,  "<<MEM[i].Link<<" ]  "<<endl;
		   }
		}

	}else if (z=='l'||z=='L') {
		int x = Libre;
		cout << "LIBRE VERSION" << endl;
		cout << "------------------------------------" << endl;
		cout << "        Dato   Link    " << endl;
		while (x!=-1){
		   cout<<"   "<<x<<"     "<<" [ "<<MEM[x].Dato<<"  ,  "<<MEM[x].Link<<" ]  "<<endl;
		   x=MEM[x].Link;
		}
		cout<<endl<<   "Libre: "<<Libre<<endl;
	}else{
	  cout<<"Error al insertar "<<endl;
	}
}

