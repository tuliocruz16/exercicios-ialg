/*Esse programa organiza os funcionarios com base no ID deles,
o programa recebe um numero inteiro do total de funcionarios(precisa ser par pois a matriz eh quadrada),
depois ele insere o id dos funcionarios seguido do salario, e organiza-os em
ordem crescente de acordo com o id*/

#include <iostream>
#include <cmath>
using namespace std;
struct funcionarios {
	int id;
	int salario;
};
float particiona(funcionarios v[], int comeco, int fim) {
    float aux = v[fim].id;
    int i = comeco, j;
    for(j = comeco; j < fim; j++) {
        if(v[j].id <= aux) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[fim]);
    return i;
}
void quick_sort(funcionarios v[], int pos_pivo, int fim) {
    int pos_novo_pivo;
    if (pos_pivo < fim) {
        pos_novo_pivo = particiona(v, pos_pivo, fim);
        quick_sort(v, pos_pivo, pos_novo_pivo - 1); 
        quick_sort(v, pos_novo_pivo + 1, fim);
    } 
}
int main () {
	int total, i, j;
	cin >> total;
	int tam = sqrt(total);
	funcionarios matriz[tam][tam];
	for (i=0; i<tam; i++) {
		for (j=0; j<tam; j++) {
			cin >> matriz[i][j].id >> matriz[i][j].salario;
		}
	}
	quick_sort(matriz[0], 0, total-1);
	for (i=0; i<tam; i++) {
		for (j=0; j<tam; j++) {
			cout << matriz[i][j].id << " " << matriz[i][j].salario << " ";
		}
		cout << endl;
	}
	return 0;
}
	
