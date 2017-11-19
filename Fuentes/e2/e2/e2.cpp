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

inline uint32_t to_bigendian(uint32_t num)
{
	return ((num >> 24) & 0xff) | // move byte 3 to byte 0
		((num << 8) & 0xff0000) | // move byte 1 to byte 2
		((num >> 8) & 0xff00) | // move byte 2 to byte 1
		((num << 24) & 0xff000000);
}

int main()
{
		list<Ficha*> *listaFichas;
		Ficha** listaFichasV;
		int Colores[NUMCOLORES][NUMCOLORES+1];
		//Helpers::iniciaColores(Colores);
		listaFichas = Helpers::cargafichas();
		//listaFichasV = Helpers::cargafichasV(listaFichas);
		//Helpers::ProcesaColores(Colores, listaFichas);
		////Helpers::imprimeColores(Colores);
		//Helpers::ReordenaColores(Colores);
		//Helpers::ReasignaFichas(listaFichas, Colores);
		//Helpers::ReordenaFichas(listaFichas);
		//Helpers::ImprimeFichas(listaFichas);

		//system("PAUSE");
		//ofstream idx3("t10k-images.idx3-ubyte",ios::binary);
		//ofstream idx1("t10k-labels.idx1-ubyte", ios::binary);
		//uint32_t DATO = to_bigendian(2051);
		//idx3.write(reinterpret_cast<char*>(&DATO), sizeof(uint32_t));
		//DATO = to_bigendian(2049);
		//idx1.write(reinterpret_cast<char*>(&DATO), sizeof(uint32_t));
		//DATO = to_bigendian(55000);
		//idx3.write(reinterpret_cast<char*>(&DATO), sizeof(uint32_t));
		//idx1.write(reinterpret_cast<char*>(&DATO), sizeof(uint32_t));
		//DATO = to_bigendian(32);
		//idx3.write(reinterpret_cast<char*>(&DATO), sizeof(uint32_t));
		//idx3.write(reinterpret_cast<char*>(&DATO), sizeof(uint32_t));
		//if (idx3.good() && idx1.good()) {
		//	
		//	for (int i = 0; i < 55000; i++)
		//	{
		//		list<Ficha*> *puzzlenuevo = GeneraPuzzle::ObtenerPuzzleSimilar(listaFichas);
		//		//Helpers::ImprimeFichas(puzzlenuevo);
		//		Helpers::ProcesaColores(Colores, puzzlenuevo);
		//		Helpers::ReordenaColores(Colores);
		//		//Helpers::imprimeColores(Colores);
		//		Helpers::ReasignaFichas(puzzlenuevo, Colores);
		//		Helpers::ReordenaFichas(puzzlenuevo);
		//		//Helpers::ImprimeFichas(puzzlenuevo);
		//		for (Ficha* F : *puzzlenuevo) {
		//			if (F->getIndice() == 1) { 
		//				unsigned char caracter = (unsigned char)(F->getNumero() - 1);
		//				idx1.put(caracter);
		//			}
		//			DATO = F->GetInt32();
		//			idx3.write(reinterpret_cast<char*>(&DATO), sizeof(uint32_t));
		//		}
		//		cout << "Generados: " << i << endl;
		//	}
		//	idx1.flush();
		//	idx3.flush();
		//	idx3.close();
		//	idx1.close();
		//}
		//cout << "EUREKA!!";

		

		system("PAUSE");
     return 0;
}

