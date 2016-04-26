#include <fstream>
#include "Lexico.h"
#include "Sintactico.h"
#include "Semantico.h"

using namespace std;

//ofstream out_file("salida.xml");
//
//void postorder(Node* node)
//{
//	if (node == NULL)
//		return;
//	if (node->data.simbolo.compare("") != 0)
//		out_file << node->data.getXmlApertura() << "\n";
//	postorder(node->left);
//	postorder(node->right);
//
//	if (node->data.simbolo.compare("") != 0)
//		out_file << node->data.getXmlCierre() << "\n";	
//}
//

int main() {
	ifstream in_file("entrada.txt");
	string cadena = string((std::istreambuf_iterator<char>(in_file)), (std::istreambuf_iterator<char>()));
	in_file.close();
	ofstream out_fileS("salida.txt");
	Lexico lexico(cadena);		
	Sintactico sintactico(lexico.getElementos());
	Node* root = sintactico.getTree();	
	Semantico semantico(root);	
	/*
	out_file << "<PROGRAMA>\n";
	postorder(root);
	out_file << "</PROGRAMA>\n";
	out_file.close();
	*/
	out_fileS << semantico.esValido();
	//cin.get();
	
	out_fileS.close();
	return 0;
}