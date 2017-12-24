#pragma once
#include <list>
#include "Ficha.h"
#include <fstream>
#include <iostream>

#define L 16
#define N 256
#define NUMCOLORES 23

#define IZQUIERDA 0
#define ARRIBA 1
#define DERECHA 2
#define ABAJO 3


using namespace std;

class Helpers
{
public:
	static void imprimeColores(int Colores[NUMCOLORES][NUMCOLORES+1]);
	static void CopiaColores(int Colores[NUMCOLORES][NUMCOLORES + 1], int Destino[NUMCOLORES][NUMCOLORES + 1]);
	uint32_t to_bigendian(uint32_t num);
	static void ProcesaColores(int Colores[NUMCOLORES][NUMCOLORES+1], list<Ficha*> *lista);
	static void iniciaColores(int Colores[NUMCOLORES][NUMCOLORES+1]);
    
	static void ReordenaColores(int Colores[NUMCOLORES][NUMCOLORES+1]);
	static int localizaFila(int Colores[NUMCOLORES][NUMCOLORES + 1], int indice,int  elemento);
	static void intercambiaFilasOrdenadas(int M[NUMCOLORES][NUMCOLORES + 1], int F1, int F2);
	static int comparaFila(int M[NUMCOLORES][NUMCOLORES + 1], int F1, int F2);
	static void intercambiaFilas(int Colores[NUMCOLORES][NUMCOLORES + 1], int Fila1, int Fila2);
	static void ReasignaFichas(list<Ficha*>*listaFichas, int Colores[NUMCOLORES][NUMCOLORES + 1]);
	static void ImprimeFichas(list<Ficha*>*lista);
	static list<Ficha*> *cargafichas();
	static Ficha ** cargafichasV(list<Ficha*>* lista);
	static void ReordenaFichas(list<Ficha*>*lista);
	static void GiraFichaAMayorValor(Ficha *ficha);
	Helpers();
	~Helpers();
};

