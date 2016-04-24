#include <fstream>
#include "Lexico.h"

using namespace std;

int main() {
	ifstream in_file("entrada0.txt");
	string cadena = string((std::istreambuf_iterator<char>(in_file)), (std::istreambuf_iterator<char>()));
	in_file.close();

	Lexico lex(cadena);	
	vector<Elemento> lexx = lex.getElementos();

	for (size_t i = 0; i < lexx.size(); i++)
	{
		cout << lexx[i].tipo << endl;

	}
	cin.get();

	ofstream out_file("salida.txt");
	out_file << lex.esValida();	

	out_file.close();
	return 0;
}