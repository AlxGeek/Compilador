#pragma once

#include <vector>
#include <iostream>
#include "Elemento.h"
#include "Node.h"

class Sintactico
{
private:
	std::vector<Elemento> elementos;
	int position;	
	bool error;

	bool esValida();
	Node* getTree();

public:
	Sintactico(std::vector<Elemento> _elementos);
	~Sintactico();

	bool nextPosition();
	void comprueba(std::string simbolo);
	void comprueba(Tipos tipo);


	Node* arith_expr();
	Node* term();
	Node* factor();
	Node* atom();

};

