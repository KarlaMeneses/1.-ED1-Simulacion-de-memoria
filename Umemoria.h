//---------------------------------------------------------------------------

#ifndef UmemoriaH
#define UmemoriaH
//---------------------------------------------------------------------------
//added
//#include <iostream>
#include<string>       //without this it makes an error in type string!
using namespace std;   //without this it makes an error in type string!

const int MAX=11;
const int NULO=-1;

const char separadores[12]={' ',',','.','-','_',':',';','"','¿','?','!','¡'};

typedef int direccion;

struct NodoM{
	int Dato;
	int Link;
	string Id;
};

class CSMemoria {
	private:
		NodoM MEM[MAX];
		int Libre;

	public:
		CSMemoria();
		direccion new_espacio(string cadena_id);
		void poner_dato(int dir,string cadena_id,int valor );
		int obtener_dato(int dir,string cadena_id);
		void delete_espacio(int dir);
		int espacio_disponible();
		int espacio_ocupado();
		bool dir_libre(int dir);
		void mostrar_memoria();

};
#endif
/*
string obtener_id(string cadena_id,int &a){//si o si entra si es mayor a 2 id
	string palabra="";
	string aux="";
	//aux=cadena_id;
	int i;
	char auxchar;
	bool es=false;
	while (es!=true){
		for (i = 0; i < sizeof(separadores)&& es!=true; i++  ) {
			if (cadena_id[a]== separadores[i]) {
				es=true;
			}
			auxchar=separadores[i];
		}
		a++;
	}
	palabra=cadena_id.substr(0,a);
	return palabra;
}*/

/*
string obtener_id(string cadena_id,int &ñ){//Algoritmo no efectivo si hay varios espacios
	string palabra="";
	int i=0;
	int aux=ñ;
	string prueba=cadena_id;
	while (palabra==""){
		if (cadena_id[ñ]==' ' || cadena_id[ñ]==',' || ((aux+i)==cadena_id.length()-1) ) {
			palabra=cadena_id.substr(aux,i);
			if ((aux+i)==cadena_id.length()-1) {
				palabra=cadena_id.substr(aux,i+1);
			}
		}
		i++;
		ñ++;
	}
	return palabra;
}
*/

