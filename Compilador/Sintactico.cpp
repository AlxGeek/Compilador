#include "Sintactico.h"



Sintactico::Sintactico(std::vector<Elemento> _elementos)
{
	elementos = _elementos;
}


Sintactico::~Sintactico()
{
}

bool Sintactico::nextPosition()
{
	if (position < (int)(elementos.size() - 1)) {
		position++;
		return true;
	}
	return false;
}

bool Sintactico::esValida()
{
	return !error;
}

Node * Sintactico::getTree()
{
	return NULL; //sentencias();
}

void Sintactico::comprueba(std::string simbolo) {
	if (elementos[position].simbolo == simbolo)
		nextPosition();
	else {
		error = true;
		std::cout << "Error: " << elementos[position].simbolo << " simbolo: " << simbolo << std::endl;
	}
}

void Sintactico::comprueba(Tipos tipo) {
	if (elementos[position].tipo == tipo)
		nextPosition();
	else {
		error = true;
		std::cout << "Error: " << elementos[position].simbolo << "simbolo: " << tipo << std::endl;
	}
}


Node* Sintactico::arith_expr() {
	Node* aux = NULL;
	aux = term();
	while (elementos[position].tipo == T_ADICION) {
		aux = new Node(elementos[position], aux);
		nextPosition();
		aux->right = term();
	}
	return aux;
}

Node * Sintactico::term()
{
	Node* aux = NULL;
	aux = factor();
	while (elementos[position].tipo == T_MULTIPLICACION) {
		aux = new Node(elementos[position], aux);
		nextPosition();
		aux->right = factor();
	}
	return aux;
}
Node * Sintactico::factor()
{
	Node* aux = NULL;
	if (elementos[position].tipo == T_ADICION) {
		nextPosition();
		aux = factor();
	}
	else
	{
		aux = atom();
	}
	return aux;
}

Node * Sintactico::atom()
{
	Node *aux = NULL;
	if (elementos[position].tipo == T_ID || elementos[position].tipo == T_ENTERO || elementos[position].tipo == T_FLOTANTE) {
		aux = new Node(elementos[position]);
		nextPosition();
	}
	else if (elementos[position].simbolo == "(") {
		nextPosition();
		aux = arith_expr();
		comprueba(")");
	}
	else {
		error = true;
	}
	return aux;
}
