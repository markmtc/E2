#pragma once
#include <list>
#include "Ficha.h"
#include "Helpers.h"

using namespace std;

class GeneraPuzzle
{
public:
	static void obtenerNumColoresPorFicha(int listaColores[NUMCOLORES][2], list<Ficha*>*listaFichas);
	
	static void IniciaBordePuzzle(int listaColores[NUMCOLORES][2], Ficha * PuzzleNuevo[L][L]);
	static void IniciaPuzzle(Ficha * Puzzle[L][L]);
	static list<Ficha*>*ObtenerPuzzleSimilar(list<Ficha*> *listaFichas);
	static list<Ficha*>* ObtenerFichasDePuzzle(Ficha * Puzzle[L][L]);
	static int ObtenerColorAleatorio(int listaColores[NUMCOLORES][2], TipoFicha tipo);
	static bool ValidaFichaEnPuzzleEnProgreso(Ficha * Puzzle[L][L], int i, int j, list<Ficha*>* listae2);
	//static bool ValidaFichaEnPuzzleEnProgreso(Ficha*Puzzle[L][L], int i, int j);
	GeneraPuzzle();
	~GeneraPuzzle();
};

