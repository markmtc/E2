// e2.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <list>
#include "Ficha.h"
#include "e2.h"
#include "Helpers.h"
#include "GeneraPuzzle.h"



using namespace std;



int main()
{
	list<Ficha*> *listaFichas;
	Ficha** listaFichasV;
	int Colores[NUMCOLORES][NUMCOLORES+1];
	listaFichas = Helpers::cargafichas();
	Helpers::ImprimeFichas(listaFichas);
	


	system("PAUSE");
    return 0;
}

