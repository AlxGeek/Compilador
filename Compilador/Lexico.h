#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Elemento.h"

class Lexico
{
public:
	Lexico(std::string _cadena);
	~Lexico();
	
	std::vector<Elemento> getElementos();
	
	bool esValida();

private:
	int position; 	
	int indent;
	bool noError;
	std::string cadena;

	std::vector<Elemento> elementos;
	void createLexico();
	bool nextPosition();
	

	


};

