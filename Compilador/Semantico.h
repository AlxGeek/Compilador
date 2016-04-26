#pragma once

#include "Node.h"
#include "Variable.h"

class Node;

class Semantico
{
public:
	Semantico(Node* _root);
	~Semantico();

	bool esValido();

	static std::vector<Variable> variables;

private:
	Node* root;				
};

