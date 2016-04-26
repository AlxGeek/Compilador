#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Elemento.h"
#include "Semantico.h"

class Semantico;

class Node
{
public:
	Node();
	Node(Elemento _data);
	Node(Node* _left);
	Node(Node* _left, Node* _right);
	Node(Elemento _data, Node* _left);
	Node(Elemento _data, Node* _left, Node* _right);
	~Node();

	Node* left;
	Node* right;
	Elemento data;	

	TipoSemantico getTipoSemantico();

};
