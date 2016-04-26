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

TipoSemantico Node::getTipoSemantico()
{
	TipoSemantico aux;
	switch (data.tipo)
	{
	case T_ENTERO:
		return S_ENTERO;
	case T_FLOTANTE:
		return S_FLOTANTE;
	case T_ADICION:
	case T_MULTIPLICACION:
		if (left->getTipoSemantico() != S_ERROR && (aux = left->getTipoSemantico()) == right->getTipoSemantico()) {
			return aux;
		}
		else
		{
			std::cout << "error adicion - mult" << std::endl;
			return S_ERROR;
		}
	case T_SIGNO:
	case T_PRINT:
	case T_BLOQUE:
		return left->getTipoSemantico();
	case T_ASIGNACION:
		if ((aux = right->getTipoSemantico()) != S_ERROR) {
			Semantico::variables.push_back(Variable(aux, left->data.simbolo));
			return S_VACIO;
		}
		else
		{
			std::cout << "error asignacion" << std::endl;
			return S_ERROR;
		}
	case T_ID:
	{
		for (size_t i = 0; i < Semantico::variables.size(); i++)
		{
			if (Semantico::variables[i].simbolo == data.simbolo) {
				return Semantico::variables[i].tipoS;
			}
		}
		std::cout << "error id" << std::endl;
		return S_ERROR;
	}
	case T_AND:
	case T_OR:
	case T_MAYOR_MENOR_QUE:
	case T_DIFERENTE:
	case T_MAYOR_MENOR_IGUAL_QUE:
	case T_IGUAL_QUE:
	case T_NOT:
		if (left->getTipoSemantico() != S_ERROR && left->getTipoSemantico() == right->getTipoSemantico()) {
			return S_VACIO;
		}
		else
		{
			std::cout << "error relacional" << std::endl;
			return S_ERROR;
		}

	case T_WHILE:
		if (left->getTipoSemantico() != S_ERROR && right->getTipoSemantico() != S_ERROR)
		{
			return S_VACIO;
		}
		else
		{
			std::cout << "error while" << std::endl;
			return S_ERROR;
		}
	case T_SENTENCIAS:
	{
		std::string debug;
		if (left != NULL)
		{
			debug = "hay izq ";
			if (left->getTipoSemantico() != S_ERROR)
			{
				debug += "izq no error ";
				if (right != NULL)
				{
					debug += "hay der ";
					if (right->getTipoSemantico() != S_ERROR)
					{
						debug += "der no error ";
						return S_VACIO;
					}
					else
					{

						return S_ERROR;
					}
				}
				else
				{
					debug += "no hay der ";
					return S_VACIO;
				}
			}
			else
			{
				std::cout << "error sentencia" << std::endl;
				return S_ERROR;
			}
		}
		else
		{
			return S_VACIO;
		}
		std::cout << debug << std::endl;

		return S_VACIO;
		std::cout << "error sentencia" << std::endl;
		return S_ERROR;
	}
	case T_IF:
		if (left->getTipoSemantico() != S_ERROR && right->left->getTipoSemantico() != S_ERROR)
		{
			if (right->right != NULL) {
				if (right->right->getTipoSemantico() != S_ERROR) {
					return S_VACIO;
				}
				else
				{
					std::cout << "error if else" << std::endl;
					return S_ERROR;
				}
			}
			else
			{
				return S_VACIO;
			}
			return S_VACIO;
		}
		else
		{
			std::cout << "error if" << std::endl;
			return S_ERROR;
		}

	case T_ELSE:
		if (left->getTipoSemantico() != S_ERROR)
		{
			return S_VACIO;
		}
		else
		{
			std::cout << "error else" << std::endl;
			return S_ERROR;
		}
	default:
		std::cout << "error default" << std::endl;
		return S_ERROR;
	}
}

