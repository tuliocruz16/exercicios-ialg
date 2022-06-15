
/*Exercicio para verificar se um vetor é palindromo.
O programa retorna 0 para falso e 1 para verdadeiro.
Disciplina de Indroducao aos Algoritmos*/

#include <iostream>
using namespace std;
void inverte (int novoVetor [], int vetor[], int tamanho) {
	int j = 0;
	for (int i = tamanho -1; i >= 0; i--) {
		novoVetor[j] = vetor[i];
		j++;
	}
}
int main () {
	int tamanho, i;
	cin >> tamanho;	
	int vetor[tamanho];
	for (i=0; i < tamanho; i++) {
		cin >> vetor[i];
	}
	int novoVetor[tamanho];
	inverte(novoVetor, vetor, tamanho);
	int cont = 0;
	for (i = 0; i < tamanho; i++) {
		if (vetor[i] == novoVetor[i]) {
			cont++;
		}
	}
	if (cont == tamanho) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
	return 0;
}

	

	
