/*Esse programa recebe uma matriz 5 por 5 e soma todas as sua colunas
depois retorna um vetor de tamanho 5 onde cada elemento
do vetor é o resultado da soma das colunas*/

#include <iostream>
using namespace std;
void retorna (int **matriz) {
	int *vetor = NULL;
	vetor = new int[5]; 
	int soma = 0, j=0;
	while (j<5) {
		for (int i=0; i<5; i++) {
			soma += matriz[i][j];
			vetor[j] = soma;
		}
		cout << vetor[j] << " ";
		soma = 0;
		j++;
	}
	delete[] vetor;
}		
int main () {
	int **matriz;
	matriz = new int*[5];
	for (int i=0; i<5; i++) {
		matriz[i] = new int[5];
	}
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			cin >> matriz[i][j];
		}
	}
	retorna (matriz);
	delete[] matriz;
	return 0;
}
