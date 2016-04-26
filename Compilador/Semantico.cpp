#include "Semantico.h"

std::vector<Variable> Semantico::variables;

Semantico::Semantico(Node* _root)
{
	root = _root;
}


Semantico::~Semantico()
{
}

bool Semantico::esValido()
{
	return root->getTipoSemantico() != S_ERROR;
}
