#include "Lexico.h"

Lexico::Lexico(std::string _cadena)
{
	position = -1;
	cadena = _cadena;
	noError = true;
	createLexico();
	indent = 0;
}


Lexico::~Lexico()
{
}

std::vector<Elemento> Lexico::getElementos()
{
	return elementos;
}

bool Lexico::esValida()
{
	return noError;
}

bool Lexico::nextPosition()
{
	if (position < (int)(cadena.size() - 1)) {
		position++;
		if ((int)cadena[position] < 0 || (int)cadena[position] > 255)
		{
			noError = false;
			return false;
		}
		return true;
	}
	return false;
}

void Lexico::createLexico()
{
	bool sig;
	int nTab = 0;
	while (noError && (sig = nextPosition()))
	{
		sig = false;
		if (isdigit(cadena[position])) {
			elementos.push_back(Elemento(std::string(1, cadena[position]), T_ENTERO));
			while (nextPosition()) {
				if (isdigit(cadena[position]))
				{
					elementos.back().simbolo.append(1, cadena[position]);
				}
				else if (cadena[position] == '.') {
					elementos.back().tipo = T_FLOTANTE;
					while ((sig = nextPosition()) && isdigit(cadena[position]))
					{
						elementos.back().simbolo.append(1, cadena[position]);
					}
					if (sig)	position--;
					break;
				}
				else
				{
					position--;
					break;
				}
			}
		}
		else if (isalpha(cadena[position]) || cadena[position] == '_') {
			elementos.push_back(Elemento(std::string(1, cadena[position]), T_ID));
			while ((sig = nextPosition()) && isalnum(cadena[position]) || cadena[position] == '_')
			{
				elementos.back().simbolo.append(1, cadena[position]);
			}
			if (sig)	position--;
		}
		else {
			switch (cadena[position]) {
			case ' ':
			case '\t':
				break;
			case '\n':
			case '\r':
				elementos.push_back(Elemento(std::string(1, cadena[position]), T_SALTO_LINEA));				
				nTab = 0;
				while ((sig = nextPosition()) && cadena[position] == '\t')
				{
					nTab++;
				}
				if (sig)
				{
					position--;
				}
				if (indent > nTab)
				{
					elementos.push_back(Elemento(std::string(1, cadena[position]), T_DEDENT));
				}
				else if (indent < nTab)
				{
					elementos.push_back(Elemento(std::string(1, cadena[position]), T_INDENT));
				}
				indent = nTab;
				break;							
			case ':':
				elementos.push_back(Elemento(std::string(1, cadena[position]), T_DOS_PUNTOS));
				break;
			case '+':
			case '-':
				elementos.push_back(Elemento(std::string(1, cadena[position]), T_ADICION));
				break;
			case ',':
				elementos.push_back(Elemento(std::string(1, cadena[position]), T_COMA));
				break;
			case '(':
			case ')':
				elementos.push_back(Elemento(std::string(1, cadena[position]), T_PARENTESIS));
				break;
			case '*':
			case '/':
				elementos.push_back(Elemento(std::string(1, cadena[position]), T_MULTIPLICACION));
				break;
			case '=':
				if ((sig = nextPosition()) && cadena[position] == '=') {
					elementos.push_back(Elemento("==", T_IGUAL_QUE));
				}
				else
				{
					if (sig) position--;
					elementos.push_back(Elemento("=", T_ASIGNACION));
				}
				break;
			case '&':
				if ((sig = nextPosition()) && cadena[position] == '&') {
					elementos.push_back(Elemento("&&", T_AND));
				}
				else
				{
					noError = false;
				}
				break;
			case '|':
				if ((sig = nextPosition()) && cadena[position] == '|') {
					elementos.push_back(Elemento("||", T_OR));
				}
				else
				{
					noError = false;
				}
				break;
			case '!':
				if ((sig = nextPosition()) && cadena[position] == '=') {
					elementos.push_back(Elemento("!=", T_DIFERENTE));

				}
				else
				{
					if (sig) position--;
					elementos.push_back(Elemento("!", T_NOT));
				}
				break;
			case '<':
			case '>':
				if ((sig = nextPosition()) && cadena[position] == '=') {
					elementos.push_back(Elemento(cadena.substr(position - 1, 2), T_MAYOR_MENOR_IGUAL_QUE));
				}
				else
				{
					if (sig) position--;
					elementos.push_back(Elemento(std::string(1, cadena[position]), T_MAYOR_MENOR_QUE));
				}
				break;
			default:
				noError = false;
			}
		}
	}
}
