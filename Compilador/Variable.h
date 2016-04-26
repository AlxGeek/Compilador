#pragma once

#include "Constantes.h"

class Variable
{
public:
	Variable(TipoSemantico _tipoS, std::string _simbolo);
	~Variable();

	TipoSemantico tipoS;
	std::string simbolo;

};

