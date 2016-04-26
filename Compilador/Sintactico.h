#pragma once

#include <vector>
#include <iostream>
#include "Elemento.h"
#include "Node.h"

class Sintactico
{
public:
	Sintactico(std::vector<Elemento> _elementos);
	~Sintactico();

	bool esValida();
	Node* getTree();

private:
	std::vector<Elemento> elementos;	
	int position;
	bool error;

	bool nextPosition();
	void comprueba(std::string simbolo);
	void comprueba(Tipos tipo);

	Node* condicion();
	Node* opLogico();

	Node* asignacion();

	Node* arith_expr();
	Node* term();
	Node* factor();
	Node* atom();

	Node* sentencias();
	Node* sentencia();

	Node* If();
	Node* While();
	Node* Print();
};

