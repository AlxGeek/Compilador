#include "Constantes.h"

std::string tipoToString(Tipos tipo) {
	switch (tipo)
	{
	case T_ADICION:
		return "Adicion";
	case T_MULTIPLICACION:
		return "Multiplicacion";
	case T_PARENTESIS:
		return "Parentesis";
	case T_AND:
		return "And";
	case T_OR:
		return "Or";
	case T_MAYOR_MENOR_QUE:
		return "Mayor Menor que";
	case T_DIFERENTE:
		return "Diferente";
	case T_MAYOR_MENOR_IGUAL_QUE:
		return "Mayor Menor Igual que";
	case T_IGUAL_QUE:
		return "Igual que";
	case T_NOT:
		return "Not";
	case T_CADENA:
		return "Cadena";
	case T_COMA:
		return "Coma";
	case T_ENTERO:
		return "Entero";
	case T_FLOTANTE:
		return "Flotante";
	case T_ASIGNACION:
		return "Asignacion";
	case T_DOS_PUNTOS:
		return "Dos puntos";
	case T_ID:
		return "Id";
	case T_TAB:
		return "Tab";
	case T_SALTO_LINEA:
		return "Salto linea";
	case T_INDENT:
		return "Indent";
	case T_DEDENT:
		return "Dedent";
	case T_ERROR:
		return "Error";
	case T_WHILE:
		return "While";
	case T_PRINT:
		return "Print";
	case T_IF:
		return "If";
	case T_ELSE:
		return "Else";
	case T_SIGNO:
		return "Signo";
	case T_BLOQUE:
		return "Bloque";
	default:
		return "Mas error";
	}

	return "";
}