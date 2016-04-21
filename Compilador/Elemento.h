#pragma once

#include <string>
#include "Constantes.h"



class Elemento
{
public:
	Elemento();
	Elemento(std::string _simbolo, Tipos _tipo);
	~Elemento();
	std::string simbolo;
	Tipos tipo;	
	std::string getXmlApertura();
	std::string getXmlCierre();
	std::string specialToXml(std::string c);
};

