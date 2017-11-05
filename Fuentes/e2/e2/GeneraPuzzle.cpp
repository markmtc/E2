#include "stdafx.h"
#include "GeneraPuzzle.h"
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <ctime>


void GeneraPuzzle::obtenerNumColoresPorFicha(int listaColores[NUMCOLORES][2], list<Ficha*>*listaFichas)
{
	for (int i = 0; i < NUMCOLORES; i++)
	{
		listaColores[i][0] = 0;
		listaColores[i][1] = 0;
	}
	for (Ficha* F: *listaFichas)
	{
		listaColores[F->getDerecha()][0]++;
		listaColores[F->getIzquierda()][0]++;
		listaColores[F->getArriba()][0]++;
		listaColores[F->getAbajo()][0]++;
		listaColores[F->getDerecha()][1]|= F->getTipoFicha();
		listaColores[F->getIzquierda()][1] |= F->getTipoFicha();
		listaColores[F->getArriba()][1] |= F->getTipoFicha();
		listaColores[F->getAbajo()][1] |= F->getTipoFicha();

	}
	for (int i = 0; i < NUMCOLORES; i++)
	{
		listaColores[i][0] = listaColores[i][0]/2;
	}
}

void GeneraPuzzle::IniciaBordePuzzle(int listaColores[NUMCOLORES][2], Ficha* PuzzleNuevo[L][L]) {
	for (int i = 0; i < L; i++)
	{
		(PuzzleNuevo[0][i])->setArriba(0);
		(PuzzleNuevo[L-1][i])->setAbajo(0);
		(PuzzleNuevo[i][0])->setIzquierda(0);
		(PuzzleNuevo[i][L - 1])->setDerecha(0);
		listaColores[0][0] = 0;
		listaColores[0][1] = 0;
	}
}

void GeneraPuzzle::IniciaPuzzle( Ficha* Puzzle[L][L]) {
	int numFicha = 1;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (Puzzle[i][j] !=NULL) {
				//Puzzle[i][j]->~Ficha();
				delete(Puzzle[i][j]);
			}
			Puzzle[i][j] = new Ficha(-1, -1, -1, -1, numFicha);
			numFicha++;
		}
	}
}

list<Ficha*>*GeneraPuzzle::ObtenerPuzzleSimilar(list<Ficha*>*listaFichas)
 {
	int reinicios = 0;
	int profmaxima = 0;
	list<Ficha*> *NuevaListaFichas = new list<Ficha*>();
	Ficha* PuzzleNuevo[L][L];
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			PuzzleNuevo[i][j] = NULL;
		}
	}
	int listaColores[NUMCOLORES][2];
	obtenerNumColoresPorFicha(listaColores, listaFichas);
	IniciaPuzzle(PuzzleNuevo);
	IniciaBordePuzzle(listaColores, PuzzleNuevo);
	//Tratar condiciones especificas de las fichas según su posición, limitando así los colores posibles
	srand(time(NULL));
	int contador = 0;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			TipoFicha tipoFicha = Interior;
			if (((i == 0 && j == 0)) || (i == L - 1 && i == L - 1) || (i == L - 1 && i == 0) || (i == 0 && i == L - 1))
			{
				tipoFicha = Esquina;
			}
			else if (i==0 || i==L-1 || j==0|| j==L-1)
			{
				tipoFicha = Lateral;
			}
			bool FichaValida = false;
			
			while (!FichaValida) {
				contador++;
				if (PuzzleNuevo[i][j]->getArriba() < 0) {
					int color = ObtenerColorAleatorio(listaColores, tipoFicha);
					PuzzleNuevo[i][j]->setArriba(color);
				}
				if (PuzzleNuevo[i][j]->getAbajo() < 0) {
					PuzzleNuevo[i][j]->setAbajo(ObtenerColorAleatorio(listaColores, tipoFicha));
					PuzzleNuevo[i + 1][j]->setArriba(PuzzleNuevo[i][j]->getAbajo());
				}
				if (PuzzleNuevo[i][j]->getDerecha() < 0) {
					PuzzleNuevo[i][j]->setDerecha(ObtenerColorAleatorio(listaColores,tipoFicha));
					PuzzleNuevo[i][j + 1]->setIzquierda(PuzzleNuevo[i][j]->getDerecha());
				}
				if (PuzzleNuevo[i][j]->getIzquierda() < 0) {
					PuzzleNuevo[i][j]->setIzquierda(ObtenerColorAleatorio(listaColores, tipoFicha));
				}
				FichaValida = ValidaFichaEnPuzzleEnProgreso(PuzzleNuevo, i, j, listaFichas );
				if (!FichaValida) {
					if (contador > 10000) {
						if (profmaxima < i*L + j) profmaxima = i*L + j;
						cout << "Reinicios: " << reinicios << ", profundidad: " << i*L + j << ", prof.Max.: "<< profmaxima << endl;
						i = 0;
						j = -1;
						contador = 0;
						obtenerNumColoresPorFicha(listaColores, listaFichas);
						IniciaPuzzle(PuzzleNuevo);
						IniciaBordePuzzle(listaColores, PuzzleNuevo);
						FichaValida = true;
						reinicios++;
					}
					else {
						if (PuzzleNuevo[i][j]->getAbajo() != 0) {
							listaColores[PuzzleNuevo[i][j]->getAbajo()][0]++;
							PuzzleNuevo[i][j]->setAbajo(-1);
						}
						if (PuzzleNuevo[i][j]->getDerecha() != 0) {
							listaColores[PuzzleNuevo[i][j]->getDerecha()][0]++;
							PuzzleNuevo[i][j]->setDerecha(-1);
						}
					}
				}
			}
		}
	}
	// Obtenemos las fichas
	NuevaListaFichas = ObtenerFichasDePuzzle(PuzzleNuevo);
	return NuevaListaFichas;
 }

list<Ficha*> *GeneraPuzzle::ObtenerFichasDePuzzle(Ficha* Puzzle[L][L]) {
	int numFicha = 1;
	list<Ficha*>*listaFichas = new list<Ficha*>();
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			Ficha* F = new Ficha(Puzzle[i][j]->getIzquierda(), Puzzle[i][j]->getArriba(), Puzzle[i][j]->getDerecha(), Puzzle[i][j]->getAbajo(), numFicha);
			numFicha++;
			listaFichas->push_back(F);
		}
	}
	return listaFichas;
}

int GeneraPuzzle::ObtenerColorAleatorio(int listaColores[NUMCOLORES][2], TipoFicha tipo) {
	//srand(time(NULL));

	int num=1+rand()%(NUMCOLORES-1);
	//cout << num << endl;
	bool encontrado = false;
	while (!encontrado)
	{
		if (listaColores[num][0] > 0 && (listaColores[num][1])&tipo==tipo) {
			listaColores[num][0] = listaColores[num][0] - 1;
			encontrado = true;
		}
		else {
			if (num == NUMCOLORES - 1) {
				num = 1;
			}
			else {
				num++;
			}
		}
	}
	return num;
}
bool GeneraPuzzle::ValidaFichaEnPuzzleEnProgreso(Ficha * Puzzle[L][L], int i, int j, list<Ficha*>*listae2)
{
	Ficha *F= Puzzle[i][j];
	Ficha *Ftmp = new Ficha(F->getIzquierda(), F->getArriba(), F->getDerecha(), F->getAbajo(), F->getNumero());
	Helpers::GiraFichaAMayorValor(Ftmp);
	
	//bool valida = false;
	//for (Ficha *F2 : *listae2) {
	//	if (*F2 == *Ftmp) {
	//		valida = true;
	//		break;
	//	}
	//}
	//if (!valida) {
	//	delete(Ftmp);
	//	return false;
	//}

	for (int k = 0; k <= i; k++)
	{
		for (int l = 0; ( k<i && l < L ) || (k==i && l<j ); l++)
		{
			Ficha *F3 = Puzzle[k][l];
			Helpers::GiraFichaAMayorValor(F3);
			if (*Ftmp == *F3) {
				delete(Ftmp);
				return false;
			}
		}
	}
	delete(Ftmp);
	return true;
}
 GeneraPuzzle::GeneraPuzzle()
{
}


GeneraPuzzle::~GeneraPuzzle()
{
}
