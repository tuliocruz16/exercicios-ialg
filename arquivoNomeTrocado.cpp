/*Esse programa le duas strings e gera dois arquivos com nome baseado
nas strings que foram lidas*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main () {
	string arquivo_entrada, arquivo_saida;
	cin >> arquivo_entrada >> arquivo_saida;
	ifstream arquivoE (arquivo_entrada);
	ofstream arquivoS (arquivo_saida);
	string dados;
	if (arquivoE) {
		while (arquivoE >> dados) {
			arquivoS << dados;
		}
		arquivoS << endl;
		arquivoE.close();
		arquivoS.close();
	}
	return 0;
}
	
