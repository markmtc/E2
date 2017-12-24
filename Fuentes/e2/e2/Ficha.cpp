#include "stdafx.h"
#include "Ficha.h"


using namespace std;

Ficha::Ficha()
{
}

bool Ficha::operator>(Ficha & f1)
{
	unsigned int valor1 = _Izquierda * 256 * 256 * 256 + _Arriba * 256 * 256 + _Derecha * 256 + _Abajo;
	unsigned int valor2 = f1.getIzquierda() * 256 * 256 * 256 + f1.getArriba() * 256 * 256 + f1.getDerecha() * 256 + f1.getAbajo();

	return valor1 > valor2;
}

bool Ficha::operator<(Ficha & f1)
{
	unsigned int valor1 = _Izquierda * 256 * 256 * 256 + _Arriba * 256 * 256 + _Derecha * 256 + _Abajo;
	unsigned int valor2 = f1.getIzquierda() * 256 * 256 * 256 + f1.getArriba() * 256 * 256 + f1.getDerecha() * 256 + f1.getAbajo();

	return valor1 < valor2;

}

bool Ficha::operator>=(Ficha & f1)
{
	unsigned int valor1 = _Izquierda * 256 * 256 * 256 + _Arriba * 256 * 256 + _Derecha * 256 + _Abajo;
	unsigned int valor2 = f1.getIzquierda() * 256 * 256 * 256 + f1.getArriba() * 256 * 256 + f1.getDerecha() * 256 + f1.getAbajo();

	return valor1 >= valor2;
}

bool Ficha::operator<=(Ficha & f1)
{
	unsigned int valor1 = _Izquierda * 256 * 256 * 256 + _Arriba * 256 * 256 + _Derecha * 256 + _Abajo;
	unsigned int valor2 = f1.getIzquierda() * 256 * 256 * 256 + f1.getArriba() * 256 * 256 + f1.getDerecha() * 256 + f1.getAbajo();

	return valor1 <= valor2;
}

bool Ficha::operator==(Ficha & f1)
{
	unsigned int valor1 = _Izquierda * 256 * 256 * 256 + _Arriba * 256 * 256 + _Derecha * 256 + _Abajo;
	unsigned int valor2 = f1.getIzquierda() * 256 * 256 * 256 + f1.getArriba() * 256 * 256 + f1.getDerecha() * 256 + f1.getAbajo();

	return valor1 == valor2;
}

bool Ficha::operator!=(Ficha & f1)
{
	unsigned int valor1 = _Izquierda * 256 * 256 * 256 + _Arriba * 256 * 256 + _Derecha * 256 + _Abajo;
	unsigned int valor2 = f1.getIzquierda() * 256 * 256 * 256 + f1.getArriba() * 256 * 256 + f1.getDerecha() * 256 + f1.getAbajo();

	return valor1 != valor2;
	
}

uint32_t Ficha::GetInt32(){
	return _Izquierda * 256 * 256 * 256 + _Arriba * 256 * 256 + _Derecha * 256 + _Abajo;
}

TipoFicha Ficha::getTipoFicha()
{
	return _TipoFicha;
}

Ficha::~Ficha()
{
}
