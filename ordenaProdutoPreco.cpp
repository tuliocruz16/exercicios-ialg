/*Esse exercicio recebe o nome, marca e preco de produtos de um
supermercado e organiza-os conforme o preco, do menor para o maior*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct supermercado {
	string produto;
	string marca;
	float preco;
};
void imprime (supermercado v[], int t) {
	for (int i=0; i<t; i++) {
		cout << setprecision(2) << fixed;
		cout << v[i].produto << " " << v[i].marca << " " << v[i].preco << endl;
	}
}
void shell_sort (supermercado vetor[], int tam) {
	int gaps[5] = {1, 2, 3, 5, 10};
	int pos_gap = 4;
	while (gaps[pos_gap] > tam) {
		pos_gap--;
	}
	float preco;
	int j;
	string produto, marca;
	while (pos_gap >= 0) {
		int gap = gaps[pos_gap];
		for (int i = gap; i<tam; i++) {
			preco = vetor[i].preco;
			produto = vetor[i].produto;
			marca = vetor[i].marca;
			j = i;
			while (j >= gap and (preco < vetor[j - gap].preco or (preco == vetor[j - gap].preco and produto < vetor[j - gap].produto))) {
				vetor[j].preco = vetor[j - gap].preco;
				vetor[j].marca = vetor[j - gap].marca;
				vetor[j].produto = vetor[j - gap].produto;
				j = j - gap;
			}
			vetor[j].preco = preco;
			vetor[j].marca = marca;
			vetor[j].produto = produto;
		}
		pos_gap--;
	}
}
int main () {
	int tam, i;
	cin >> tam;
	supermercado vetor[tam];
	for (i=0; i<tam; i++) {
		cin >> vetor[i].produto >> vetor[i].marca >> vetor[i].preco;
	}
	shell_sort(vetor, tam);
	imprime(vetor, tam);
	cout << endl;
	return 0;
}
	
