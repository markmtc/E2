#include <list>
#include "stdafx.h"
#include "Helpers.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void Helpers::ProcesaColores(int Colores[NUMCOLORES][NUMCOLORES+1], list<Ficha*> *lista)
{
	iniciaColores(Colores);
	for (Ficha* F : *lista)
	{
		Colores[F->getAbajo()][F->getDerecha()] += 1;
		Colores[F->getAbajo()][F->getIzquierda()] += 1;
		Colores[F->getArriba()][F->getDerecha()] += 1;
		Colores[F->getArriba()][F->getIzquierda()] += 1;
		Colores[F->getIzquierda()][F->getArriba()] += 1;
		Colores[F->getIzquierda()][F->getAbajo()] += 1;
		Colores[F->getDerecha()][F->getArriba()] += 1;
		Colores[F->getDerecha()][F->getAbajo()] += 1;
	}
	for (int i = 0; i < NUMCOLORES; i++)
	{
		if (Colores[i][i] > 0)
			Colores[i][i] = Colores[i][i] / 2;
	}
}

void Helpers::iniciaColores(int Colores[NUMCOLORES][NUMCOLORES+1])
{
	for (int i = 0; i < NUMCOLORES; i++)
	{
		for (int j = 0; j < NUMCOLORES; j++)
		{
			Colores[i][j] = 0;
		}
		Colores[i][NUMCOLORES] = i;
	}
}

Ficha** Helpers::cargafichasV(list<Ficha*> *lista) {
	Ficha* result[N];
	for (Ficha* F : *lista) {
		result[F->getNumero()-1] = new Ficha(F->getIzquierda(), F->getArriba(), F->getDerecha(), F->getAbajo(), F->getNumero());
	}
	return result;
}

void Helpers::ReordenaFichas(list<Ficha*>* lista)
{
	list<Ficha> *listaNueva = new list<Ficha>();
	for (Ficha *F : *lista)
	{
		GiraFichaAMayorValor(F);
		listaNueva->push_back(*F);
	}
	listaNueva->sort();
	lista->clear();
	int i = 1;
	for (Ficha F : *listaNueva) {
		Ficha *F2 = new Ficha(F.getIzquierda(),F.getArriba(),F.getDerecha(),F.getAbajo(),F.getNumero());
		F2->setNumero(i);
		lista->push_back(F2);
		i++;
	}
}



//Condicionada a que no haya 2 fichas iguales
void Helpers::GiraFichaAMayorValor(Ficha * ficha)
{
	unsigned int valor1, valor2, valor3, valor4;
	valor1 = ficha->getIzquierda() * 256 * 256 * 256 + ficha->getArriba() * 256 * 256 + ficha->getDerecha() * 256 +  ficha->getAbajo() ;
	valor2 =  ficha->getAbajo() * 256 * 256 * 256   + ficha->getIzquierda() * 256 * 256 + ficha->getArriba() * 256 + ficha->getDerecha();
	valor3 = ficha->getDerecha() * 256 * 256 * 256 + ficha->getAbajo() * 256 * 256  + ficha->getIzquierda() * 256 +  ficha->getArriba() ;
	valor4 = ficha->getArriba() * 256 * 256 * 256 + ficha->getDerecha() * 256 * 256 + ficha->getAbajo() *256  +   ficha->getIzquierda() ;
	
	//Si el valor1 es el mayor, no cambio nada por lo que solo tengo en cuenta los otros casos
	if (valor2 > valor1 && valor2 > valor3 && valor2>valor4) {
		int swap = ficha->getIzquierda();
		int swap2 = ficha->getDerecha();
		ficha->setIzquierda(ficha->getAbajo());
		ficha->setDerecha(ficha->getArriba());
		ficha->setAbajo(swap2);
		ficha->setArriba(swap);
		
		
	}
	else {
		if (valor3 > valor2 && valor3 > valor4 && valor3 > valor1) {
			int swap = ficha->getArriba();
			int swap2 = ficha->getIzquierda();
			ficha->setIzquierda(ficha->getDerecha());
			ficha->setArriba(ficha->getAbajo());
			ficha->setDerecha(swap2);
			ficha->setAbajo(swap);
		}
		else {
			if (valor4 > valor1 && valor4 > valor2 && valor4 > valor3) {
				int swap = ficha->getIzquierda();
				ficha->setIzquierda(ficha->getArriba());
				ficha->setArriba(ficha->getDerecha());
				ficha->setDerecha(ficha->getAbajo());
				ficha->setAbajo(swap);
			}
		}
	}
}

list<Ficha*> *Helpers::cargafichas() {
	//ifstream input("C:\\Mis documentos\\Visual Studio 2008\\Projects\\Pruebas\\Debug\\fichas.txt");
	list<Ficha*> *lista = new list<Ficha*>();
	ifstream input("fichas.txt");
	if (input.good())
	{
		int tmp[4];


		int valor = 0, cont = 0;

		while (!input.eof())
		{
			input >> tmp[cont];
			cout << setw(3) << tmp[cont] << " ";
			cont++;
			if (cont == 4)
			{
				Ficha *F = new Ficha(tmp[0], tmp[1], tmp[2], tmp[3], valor + 1);
				//t[valor][4] = valor;
				//cout << ceros << " " << valor << endl;
				cout << " " <<setw(2)<< valor << endl;
				lista->push_back(F);
				//t[valor][5] = ceros;
				//ceros = 0;
				cont = 0;
				valor++;
			}
		}

		input.close();
	}
	else
	{
		char valor;
		cout << "Error en la apertura del fichero fichas.txt" << endl;
		cin >> valor;
	}
	return lista;
}

void Helpers::imprimeColores(int Colores[NUMCOLORES][NUMCOLORES+1]) {
	cout << endl << "       ";
	for (size_t i = 0; i < NUMCOLORES; i++)
	{
		cout << setw(2) << i << " "<< setw(2) ;
	}
	cout << endl;
	for (int i = 0; i < NUMCOLORES; i++)
	{
		cout << setw(2) << i << " "<< setw(2)<<Colores[i][NUMCOLORES] << ": ";
		for (int j = 0; j <= NUMCOLORES; j++)
		{
			cout << setw(2) << Colores[i][j] << " ";

		}
		cout << endl;
	}
}
void Helpers::CopiaColores(int Colores[NUMCOLORES][NUMCOLORES + 1], int Destino[NUMCOLORES][NUMCOLORES + 1]) {
	for (int i = 0; i < NUMCOLORES; i++)
	{
		for (int j = 0; j < NUMCOLORES+1; j++)
		{
			Destino[i][j] = Colores[i][j];
		}
	}
}

void Helpers::ReordenaColores(int Colores[NUMCOLORES][NUMCOLORES + 1]) 
{
	int tmp[NUMCOLORES][NUMCOLORES+1];
	CopiaColores(Colores, tmp);

	for (int i = 0; i < NUMCOLORES; i++)
	{
		//reordenación del vector en tmp
		for (int j = 0; j < NUMCOLORES; j++)
		{
			for (int z = j+1; z < NUMCOLORES; z++)
			{
				if (tmp[i][j] < tmp[i][z]) {
					int swap = tmp[i][j];
					tmp[i][j] = tmp[i][z];
					tmp[i][z] = swap;
				}
			}
		}
		//Ya tenemos en tmp de mayor a menor los elementos de cada fila
		//Las ordenamos por tamaño con la ayuda de la función ComparaFila

		for (int i = 0; i < NUMCOLORES; i++)
		{
			for (int j = i+1; j < NUMCOLORES; j++)
			{
				if (comparaFila(tmp, i, j) < 0) {
					intercambiaFilasOrdenadas(tmp, i, j);
				}
			}
		}
		//Por último reordenamos los colores según el resultado:
		int pos;
		int pos2;
		for (int i = 0; i < NUMCOLORES; i++)
		{
			pos = tmp[i][NUMCOLORES];
			pos2 = localizaFila(Colores, i, pos);
			if (pos2 != i) {
				intercambiaFilas(Colores,i, pos2);
			}
		}
	}
	//imprimeColores(tmp);
	//imprimeColores(Colores);
}
int Helpers::localizaFila(int Colores[NUMCOLORES][NUMCOLORES + 1], int indice, int elemento) {
	for (int i = indice; i < NUMCOLORES; i++)
	{
		if (Colores[i][NUMCOLORES] == elemento) {
			return i;
		}
	}
}

void Helpers::intercambiaFilasOrdenadas(int M[NUMCOLORES][NUMCOLORES + 1], int F1, int F2) {
	int swap;
	for (int i = 0; i < NUMCOLORES+1; i++)
	{
		swap = M[F1][i];
		M[F1][i] = M[F2][i];
		M[F2][i] = swap;
	}
}

int Helpers::comparaFila(int M[NUMCOLORES][NUMCOLORES + 1], int F1, int F2) {
	int result = 0;
	for (int i = 0; i < NUMCOLORES; i++)
	{
		result = M[F1][i] - M[F2][i];
		if (result != 0)
			break;
	}
	return result;
}

void Helpers::intercambiaFilas(int Colores[NUMCOLORES][NUMCOLORES + 1], int Fila1, int Fila2)
{
	for (size_t i = 0; i < NUMCOLORES+1; i++)
	{
		int swap = Colores[Fila1][i];
		Colores[Fila1][i] = Colores[Fila2][i];
		Colores[Fila2][i] = swap;
	}
	for (size_t i = 0; i < NUMCOLORES; i++)
	{
		int swap = Colores[i][Fila1];
		Colores[i][Fila1] = Colores[i][Fila2];
		Colores[i][Fila2] = swap;
	}
}

void Helpers::ReasignaFichas(list<Ficha*> *listaFichas, int Colores[NUMCOLORES][NUMCOLORES + 1]) {
	
	int ConversionColores[NUMCOLORES];

	for (int j = 0; j < NUMCOLORES; j++)
	{
		ConversionColores[Colores[j][NUMCOLORES]] = j;
	}

	for (Ficha* F : *listaFichas)
	{
		F->setAbajo(ConversionColores[F->getAbajo()]);
		F->setArriba ( ConversionColores[F->getArriba()]);
		F->setIzquierda ( ConversionColores[F->getIzquierda()]);
		F->setDerecha ( ConversionColores[F->getDerecha()]);
	}
	//Reordenar dentro de cada ficha 
	//Reordenarlas según nuevos pesos

}

void Helpers::ImprimeFichas(list<Ficha*> *lista) {
	for (Ficha* F: *lista)
	{
		cout << setw(3) << F->getNumero() << ": " << setw(2) << F->getIzquierda() <<" "<< setw(2) << F->getArriba() << " " << setw(2) << F->getDerecha() << " " << setw(2) << F->getAbajo() << " " << setw(3) << F->getIndice() << endl;
	}
}

Helpers::Helpers()
{
}


Helpers::~Helpers()
{
}
