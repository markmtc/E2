#pragma once
#include <list>
#include "Ficha.h"

using namespace std;

class GrafoHelper
{
public:
	static void ImprimeGrafo(list<Ficha*>*lista);

	GrafoHelper();
	~GrafoHelper();
};

