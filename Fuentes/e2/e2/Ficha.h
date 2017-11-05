#pragma once
#include <iostream>

enum TipoFicha {Esquina = 1, Lateral=2, Interior=4 };

class Ficha
{
public:
	int getArriba() { return _Arriba; }
	void setArriba(int value) { _Arriba = value; 
	}
	int getAbajo() { return _Abajo; }
	void setAbajo(int value) { _Abajo = value; }
	int getIzquierda() { return _Izquierda; }
	void setIzquierda(int value) { _Izquierda = value; }
	int getDerecha() { return _Derecha; }
	void setDerecha(int value) { _Derecha = value; }
	int getNumero() { return _Numero; }
	void setNumero(int value) { _Numero = value; }
	int getIndice() { return _Indice; }
	TipoFicha getTipoFicha();

	// class constructor
	Ficha(int Izquierda, int Arriba, int Derecha, int Abajo, int Numero) {
		_Izquierda = Izquierda;
		_Derecha = Derecha;
		_Arriba = Arriba;
		_Abajo = Abajo;
		_Numero = Numero;
		_Indice = Numero;
		int numceros = 0;
		if (Izquierda == 0) numceros++;
		if (Derecha == 0) numceros++;
		if (Abajo == 0) numceros++;
		if (Arriba == 0) numceros++;
		if (numceros == 0) _TipoFicha = Interior;
		else if (numceros == 1) _TipoFicha = Lateral;
		else if (numceros == 2) _TipoFicha = Esquina;
	};
	~Ficha();
	Ficha();
	bool operator> (Ficha &f1);
	bool operator< (Ficha &f1);
	bool operator>= (Ficha &f1);
	bool operator<= (Ficha &f1);
	bool operator== (Ficha &f1);
	bool operator!= (Ficha &f1);
	uint32_t GetInt32();
private:
	
	int _Izquierda;
	int _Derecha;
	int _Arriba;
	int _Abajo;
	int _Numero;
	int _Indice;
	TipoFicha _TipoFicha;
};

