#include "Sintactico.h"



Sintactico::Sintactico(std::vector<Elemento> _elementos)
{
	position = 0;
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
	if (elementos.size() > 0)
		return sentencias();
	return NULL;
}

void Sintactico::comprueba(std::string simbolo) {
	if (elementos[position].simbolo == simbolo)
		nextPosition();
	else {
		error = true;
		/*std::cout << "Error simbolo: " << simbolo
			<< " Simbolo: '" << elementos[position].simbolo
			<< "' Tipo: " << tipoToString(elementos[position].tipo) << std::endl;*/
	}
}

void Sintactico::comprueba(Tipos tipo) {
	if (elementos[position].tipo == tipo)
		nextPosition();
	else {
		error = true;
		/*std::cout << "Error tipo: " << tipoToString(tipo)
			<< " Simbolo: '" << elementos[position].simbolo
			<< "' Tipo: " << tipoToString(elementos[position].tipo) << std::endl;*/
		/*
		std::cout << "Error tipo menos uno: " << tipoToString(tipo)
			<< " Simbolo: '" << elementos[position-1].simbolo
			<< "' Tipo: " << tipoToString(elementos[position-1].tipo) << std::endl;*/

	}
}

Node * Sintactico::condicion()
{
	Node *t, *aux = NULL;
	t = arith_expr();
	aux = opLogico();
	aux->left = t;
	aux->right = arith_expr();
	return aux;
}

Node* Sintactico::opLogico()
{
	Node *aux = new Node(elementos[position]);
	if (elementos[position].simbolo == "<" || elementos[position].simbolo == ">" ||
		elementos[position].simbolo == "<=" || elementos[position].simbolo == ">=" ||
		elementos[position].simbolo == "==" || elementos[position].simbolo == "!=")
	{
		nextPosition();
	}
	else
	{
		//std::cout << "Error: " << elementos[position].simbolo << " OpLogico" << std::endl;
		error = true;
	}
	return aux;
}

Node* Sintactico::asignacion() {
	Node *aux = new Node();
	aux->left = new Node(elementos[position]);
	comprueba(T_ID);
	aux->data = elementos[position];
	comprueba(T_ASIGNACION);
	aux->right = arith_expr();
	comprueba(T_SALTO_LINEA);	
	return aux;
}

Node* Sintactico::arith_expr() {
	Node* aux = term();
	while (elementos[position].tipo == T_ADICION) {
		aux = new Node(elementos[position], aux);
		nextPosition();
		aux->right = term();
	}
	return aux;
}

Node * Sintactico::term()
{
	Node* aux = factor();
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
		aux = new Node(Elemento(elementos[position].simbolo, T_SIGNO));
		nextPosition();
		aux->left = factor();
	}
	else
	{
		aux = atom();
	}
	return aux;
}

Node * Sintactico::atom()
{
	Node *aux = new Node(elementos[position]);
	if (elementos[position].tipo == T_ID || elementos[position].tipo == T_ENTERO || elementos[position].tipo == T_FLOTANTE) {		
		nextPosition();
	}
	else if (elementos[position].simbolo == "(") {
		nextPosition();
		aux = arith_expr();
		comprueba(")");
	}
	else {
		//std::cout << "Error: " << elementos[position].simbolo << " atom" << std::endl;
		error = true;
	}
	return aux;
}

Node* Sintactico::sentencias() {
	Node *aux = new Node(Elemento("", T_SENTENCIAS));
	if ((aux->left = sentencia()) != NULL)
		aux->right = sentencias();
	return aux;
}

Node* Sintactico::sentencia() {
	Node *aux = NULL;
	if (elementos[position].simbolo == "if")
	{
		aux = If();
	}
	else if (elementos[position].simbolo == "while")
	{
		aux = While();
	}
	else if (elementos[position].simbolo == "print")
	{
		aux = Print();
	}
	else if (elementos[position].simbolo == "else")
	{

	}
	else if (elementos[position].tipo == T_ID)
	{
		aux = asignacion();
	}
	else if (elementos[position].tipo != T_DEDENT && nextPosition())
	{
		//std::cout << "Error: " << elementos[position - 1].simbolo << " Sentencia" << std::endl;
		//std::cout << "Error: Sentencia" << std::endl;
		error = true;
	}
	return aux;
}

Node * Sintactico::If()
{	
	Node *aux = new Node(elementos[position]);
	comprueba("if");
	aux->data.tipo = T_IF;
	aux->left = condicion();
	comprueba(":");
	comprueba(T_SALTO_LINEA);
	aux->right = new Node;
	comprueba(T_INDENT);
	aux->right->left = new Node(Elemento("BLOQUE", T_BLOQUE));
	aux->right->left->left = sentencias();
	comprueba(T_DEDENT);
	if (elementos[position].simbolo == "else")
	{
		nextPosition();
		comprueba(":");
		comprueba(T_SALTO_LINEA);
		comprueba(T_INDENT);
		aux->right->right = new Node(Elemento("OTRO", T_ELSE));
		aux->right->right->left = sentencias();
		comprueba(T_DEDENT);
	}
	return aux;
}

Node* Sintactico::While()
{
	Node *aux = new Node(elementos[position]);
	comprueba("while");
	aux->data.tipo = T_WHILE;
	aux->left = condicion();
	comprueba(":");
	comprueba(T_SALTO_LINEA);
	comprueba(T_INDENT);
	aux->right = new Node(Elemento("BLOQUE", T_BLOQUE));
	aux->right->left = sentencias();
	comprueba(T_DEDENT);
	return aux;
}

Node * Sintactico::Print()
{
	Node *aux = new Node(elementos[position]);
	comprueba("print");
	aux->data.tipo = T_PRINT;
	comprueba("(");
	aux->left = arith_expr();
	comprueba(")");
	comprueba(T_SALTO_LINEA);
	return aux;
}
