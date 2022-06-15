/*Esse programa recebe uma matriz e um elemento e verifica se
o elemento pertence ou nao a matriz, retorna 1 caso seja verdadeiro
e 0 caso seja falso*/

#include <iostream>
using namespace std;
void verifica (int **matriz, int linha, int coluna, int elemento) {
	int existe = 1;
	for (int i=0; i<linha; i++) {
		for (int j=0; j<coluna; j++) {
			if (elemento == matriz[i][j] and existe == 1) {
				cout << existe << endl;
				existe = 0;
			}
		}
	}
	if (existe == 1) {
		cout << "0" << endl;
	}
}
int main () {
	int linha, coluna, elemento;
	int **matriz;
	cin >> linha >> coluna;
	matriz = new int*[linha];
	for (int i=0; i<linha; i++) {
		matriz[i] = new int[coluna];
	}
	for (int i=0; i<linha; i++){
		for (int j=0; j<coluna; j++){
			cin >> matriz[i][j];
		}
	}
	cin >> elemento;
	verifica (matriz, linha, coluna, elemento);
	for (int i=0; i<linha; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
	return 0;
}
