#include <fstream>
#include "Lexico.h"

using namespace std;

int main() {
	ifstream in_file("entrada.txt");
	string cadena = string((std::istreambuf_iterator<char>(in_file)), (std::istreambuf_iterator<char>()));
	in_file.close();

	Lexico lex(cadena);	
	ofstream out_file("salida.txt");
	out_file << lex.esValida();	

	out_file.close();
	return 0;
}