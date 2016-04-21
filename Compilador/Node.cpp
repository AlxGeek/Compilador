#include "Node.h"

Node::Node()
{
	left = right = NULL;
}

Node::Node(Elemento _data)
{
	data = _data;
	left = right = NULL;
}

Node::Node(Node * _left)
{
	left = _left;
	right = NULL;
}

Node::Node(Node * _left, Node * _right)
{
	left = _left;
	right = _right;
}

Node::Node(Elemento _data, Node * _left)
{
	data = _data;
	left = _left;
	right = NULL;
}

Node::Node(Elemento _data, Node * _left, Node * _right)
{
	data = _data;
	left = _left;
	right = _right;
}

Node::~Node()
{
}

