#include <iostream>
using namespace std;
int main () {
	int qtd, qtdAsteriscos;
	cin >> qtd;
	string palavras[qtd];
	int maior = 0;
	for (int i = 0; i < qtd; i++) {
		cin >> palavras[i];
		if ((int)palavras[i].length() > maior) {
			maior = palavras[i].length();
		}
	}
	for (int i = 0; i < qtd; i++) {
		qtdAsteriscos = maior - palavras[i].length();
		for (int j = 0; j < qtdAsteriscos; j++) {
			cout << "*";
		}
		cout << palavras[i] <<endl;
	}
	return 0;
}
