/*Esse programa recebe um vetor de inteiros e o ordena de forma
decrescente, mostrando todas as operacoes feitas durante o processo 
de ordenacao*/

#include <iostream>
using namespace std;
int merge_sort (int v[], int comeco, int metade, int fim) {
	int c = comeco;
	int m = metade + 1;
	int aux = fim - comeco + 1;
	int vetor[aux];
	for (int i=0; i<aux; i++) {
		if (c > metade) {
			vetor[i] = v[m];
			m++;
		}
		else if (c <= metade and m <= fim) {
			if (v[c] <= v[m]) {
				vetor[i] = v[m];
				m++;
			}
			else if (v[c] >= v[m]) {
				vetor[i] = v[c];
				c++;
			}
		}
		else {
			vetor[i] = v[c];
			c++;
		}
	}
	for (int i=0; i<aux; i++) {
		v[i + comeco] = vetor[i];
	}
	return c;
}
void imprime (int v[], int tam) {
	int i, j, aux;
	for (aux = 1; aux < tam; aux = 2 * aux) {
		for (i=0; i + aux < tam; i = i + 2 * aux) {
			j = i + 2 * aux;
			if (j > tam) {
				j = tam;
			}
			merge_sort (v, i, i+aux-1, j-1);
			for (int i=0; i<tam; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}
}
int main () {
	int tam;
	cin >> tam;
	int vetor[tam];
	for (int i=0; i<tam; i++) {
		cin >> vetor[i];
	}
	imprime (vetor, tam);
	return 0;
}
