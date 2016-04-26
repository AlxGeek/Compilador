#include "Elemento.h"



Elemento::Elemento()
{
	simbolo = "";
	//tipo = T_ERROR;
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
	case T_ADICION:
		return "<SUMA value=\"" + simbolo + "\">";

	case T_SIGNO:
		return "<SIGNO value=\"" + simbolo + "\">";

	case T_MULTIPLICACION:
		return "<MULT value=\"" + simbolo + "\">";

	case T_PARENTESIS:
		return "<PARENTESIS>";

	case T_AND:
		return "<AND>";

	case T_OR:
		return "<OR>";

	case T_MAYOR_MENOR_QUE:
		return "<EXPRESION value=\"" + specialToXml(simbolo) + "\">";

	case T_DIFERENTE:
		return "<EXPRESION value=\"!=\">";

	case T_MAYOR_MENOR_IGUAL_QUE:
		return "<EXPRESION value=\"" + specialToXml(simbolo) + "=\">";

	case T_IGUAL_QUE:
		return "<EXPRESION value=\"==\">";

	case T_NOT:
		return "<NOT>";

	case T_CADENA:
		return "<CADENA>" + simbolo;

	case T_COMA:
		return "<COMA>";

	case T_ENTERO:
		return "<ENTERO>" + simbolo;

	case T_FLOTANTE:
		return "<REAL>" + simbolo;

	case T_ASIGNACION:
		return "<ASIGNACION>";

	case T_BLOQUE:
		return "<BLOQUE>";

	case T_ELSE:
		return "<OTRO>";

	case T_WHILE:
		return "<MIENTRAS>";

	case T_IF:
		return "<SI>";

	case T_PRINT:
		return "<IMPRIME>\n<EXPRESION>";

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

	case T_SIGNO:
		return "</SIGNO>";

	case T_MULTIPLICACION:
		return "</MULT>";

	case T_PARENTESIS:
		return "</PARENTESIS>";

	case T_AND:
		return "</AND>";

	case T_OR:
		return "</OR>";

	case T_MAYOR_MENOR_QUE:
		return "</EXPRESION>";

	case T_DIFERENTE:
		return "</EXPRESION>";

	case T_MAYOR_MENOR_IGUAL_QUE:
		return "</EXPRESION>";

	case T_IGUAL_QUE:
		return "</EXPRESION>";

	case T_NOT:
		return "</NOT>";

	case T_CADENA:
		return "</CADENA>";

	case T_COMA:
		return "</COMA>";

	case T_ENTERO:
		return "</ENTERO>";

	case T_FLOTANTE:
		return "</REAL>";

	case T_ELSE:
		return "</OTRO>";

	case T_ASIGNACION:
		return "</ASIGNACION>";

	case T_BLOQUE:
		return "</BLOQUE>";

	case T_WHILE:
		return "</MIENTRAS>";

	case T_IF:
		return "</SI>";

	case T_PRINT:
		return "</EXPRESION>\n</IMPRIME>";

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