#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
//added
#include <iostream>
#include "Umemoria.h"

///////#include<string>  ----
using namespace std;

//string obtener_id2(string cadena_id,int &a);

int _tmain(int argc, _TCHAR* argv[])
{      /////////

	CSMemoria* memoria = new CSMemoria;
	cout<<"Memoria creada con exito!\n";
	int x=memoria->new_espacio("  h   ,ola  ,  mundo,como ,TODOS  ");
   //	int y=memoria->new_espacio("   UAGRM , dinos ");
	//memoria->new_espacio("hola, como , estan ,????");
	memoria->poner_dato(x,"   ->como   ",1000);   ///
	//memoria->poner_dato(y,"->UAGRM    ",2000); ////
	memoria->mostrar_memoria();
	 /*
	if (memoria->lleno()==1) cout<<"La memoria esta llena" <<endl;//0=true
	else cout<<"La memoria NO esta llena" <<endl;//1=false
	if (memoria->vacio()==1) cout<<"La memoria esta vacia" <<endl;//0=true
	else cout<<"La memoria NO esta vacia" <<endl;//1=false
	int ebx=6;
	if (memoria->Estado_Dir(ebx)==1) cout<<"La direccion "<<ebx<<" se encuentra disponible" <<endl;//0=true
	else cout<<"La direccion NO se encuentra disponible" <<endl;//1=false
	cout<<"espacio disponible "<<memoria->espacio_disponible()<<endl;
	cout<<"espacio ocupado "<<memoria->espacio_ocupado()<<endl;    */
/*	string cad= ">hola";
	int i=cad.rfind('>');//encuentra el char de la derecha y devuelve la posicion
	//string cad[3]={'1','2','3'};

	string arr[] = {"hola","20","como","40","estan","60"};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	for (i = 0; i < arrSize; i++) {
		cout<<arr[i]<<endl;
	}
	cout<<"sizeof: "<<arrSize<<endl;
	cout<<"Prueba: "<<i<<endl;
	//memoria->NuevoMostrar('o'); //ocupado
   //	memoria->NuevoMostrar('L'); //libre    */
	system("pause");
	return 0;
}

