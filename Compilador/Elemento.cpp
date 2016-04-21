#include "Elemento.h"



Elemento::Elemento()
{
	simbolo = "";
}

Elemento::Elemento(std::string _simbolo, Tipos _tipo)
{
	simbolo = _simbolo;
	tipo = _tipo;
}


Elemento::~Elemento()
{
}

std::string Elemento::getXmlApertura()
{
	switch (tipo)
	{
	case T_DELIMITADOR:
		return "<DELIMITADOR>";

	case T_ADICION:
		return "<SUMA value=\"" + simbolo + "\">";
	case T_MULTIPLICACION:
		return "<MULT value=\"" + simbolo + "\">";

	case T_PARENTESIS:
		return "<PARENTESIS>";

	case T_AND:
		return "<AND>";

	case T_OR:
		return "<OR>";

	case T_MAYOR_MENOR_QUE:
		return "<MAYOR_MENOR_QUE value=\"" + specialToXml(simbolo) + "\">";

	case T_DIFERENTE:
		return "<DIFERENTE>";

	case T_MAYOR_MENOR_IGUAL_QUE:
		return "<MAYOR_MENOR_IGUAL_QUE value=\"" + specialToXml(simbolo) + "=\">";

	case T_IGUAL_QUE:
		return "<IGUAL_QUE>";

	case T_NOT:
		return "<NOT>";

	case T_CADENA:
		return "<CADENA>" + simbolo;

	case T_COMA:
		return "<COMA>";

	case T_ENTERO:
		return "<ENTERO>" + simbolo;

	case T_ASIGNACION:
		return "<ASIGNACION>";

	case T_ID:
		return "<ID>" + simbolo;

	case T_ERROR:
		return "error";

	default:
		return "<" + simbolo + ">";

	}
}

std::string Elemento::getXmlCierre()
{
	switch (tipo)
	{
	case T_ADICION:
		return "</SUMA>";
	case T_MULTIPLICACION:
		return "</MULT>";

	case T_PARENTESIS:
		return "</PARENTESIS>";

	case T_AND:
		return "</AND>";

	case T_OR:
		return "</OR>";

	case T_MAYOR_MENOR_QUE:
		return "</MAYOR_MENOR_QUE>";

	case T_DIFERENTE:
		return "</DIFERENTE>";

	case T_MAYOR_MENOR_IGUAL_QUE:
		return "</MAYOR_MENOR_IGUAL_QUE>";

	case T_IGUAL_QUE:
		return "</IGUAL_QUE>";

	case T_NOT:
		return "</NOT>";

	case T_CADENA:
		return "</CADENA>";

	case T_COMA:
		return "</COMA>";

	case T_ENTERO:
		return "</ENTERO>";

	case T_ASIGNACION:
		return "</ASIGNACION>";

	case T_ID:
		return "</ID>";

	case T_ERROR:
		return "error";

	default:
		return "</" + simbolo + ">";

	}
}

std::string Elemento::specialToXml(std::string c) {
	if (c[0] == '<')
		return "&lt;";
	else if (c[0] == '>')
		return "&gt;";
	return "error pato";
}