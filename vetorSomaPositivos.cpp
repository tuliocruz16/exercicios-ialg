/*Esse programa recebe um vetor de tamanho 10 e soma todos
os seus elementos que sao positivos, caso o elemento seja 
negativo ele retorna quantos sao esses elementos*/

#include <iostream>
using namespace std;
int main() {
	float  vetor[10];
	int i = 0;
	float soma = 0;
	int contador = 0;
	while (i < 10) {
		cin >> vetor[i];
		if (vetor[i] >= 0) {
			soma += vetor[i];
		}
		else {
			contador++;
		}
		i++;
	}
	cout << contador << endl;
	cout << soma << endl;
}
