#pragma once

#include <string>


enum Tipos {
	T_ADICION, T_MULTIPLICACION, T_PARENTESIS, T_AND, T_OR, T_MAYOR_MENOR_QUE, T_DIFERENTE,
	T_MAYOR_MENOR_IGUAL_QUE, T_IGUAL_QUE, T_NOT, T_CADENA, T_COMA, T_ENTERO, T_FLOTANTE, T_ASIGNACION,
	T_DOS_PUNTOS, T_ID, T_TAB, T_SALTO_LINEA, T_INDENT, T_DEDENT, T_BLOQUE, T_SIGNO, T_PRINT, T_WHILE, 
	T_IF, T_ELSE, T_SENTENCIAS, T_ERROR
};



enum TipoSemantico {S_ENTERO, S_FLOTANTE, S_VACIO, S_ERROR};

std::string tipoToString(Tipos tipo);


