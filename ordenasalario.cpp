/* Esse exercicio organiza os funcionarios de acordo
com seus salarios em ordem crescente
primeiro ele recebe um id do funcionario, suas horas
trabalhadas e o valor das horas, depois ele multiplica 
o valor pelas horas trabalhadas e obtem o salario do funcionario*/

#include <iostream>
using namespace std;
struct funcionario {
	int identificador;
	float horas_trabalhadas;
	float valor_hora;
	float salario;
};
int particiona(funcionario v[], int comeco, int fim){
	int i = comeco + 1, j = fim;
	float pivo = v[comeco].salario;
	while (i <= j){
		if (v[i].salario <= pivo){
			i++;
		} 
		else if (pivo <= v[j].salario){
			j--;
		} 
		else {
			swap (v[i], v[j]);
			i++;
			j--;
		}
	}
	swap (v[comeco], v[j]);
	return j;
}
void quicksort(funcionario v[], int pos_pivo, int fim){
	if (pos_pivo < fim){
		int novo_pivo= particiona(v, pos_pivo, fim);
		quicksort(v, pos_pivo, novo_pivo - 1);
		quicksort(v, novo_pivo + 1, fim);
	}
}
void leitura (funcionario v[], int n) {
	for (int i=0; i<n; i++) {
		cin >> v[i].identificador >> v[i].horas_trabalhadas >> v[i].valor_hora;
		v[i].salario = v[i].horas_trabalhadas * v[i].valor_hora;
	}
}
void saida (funcionario v[], int limite){
	for (int i=0; i<limite; i++){
		cout << v[i].identificador << " " << v[i].salario << endl;
	}
}
int main () {
	int qtd_funcionario;
	cin >> qtd_funcionario;
	funcionario vetor[qtd_funcionario];
	leitura (vetor, qtd_funcionario);
	quicksort(vetor, 0, qtd_funcionario - 1);
	saida(vetor, qtd_funcionario);
	return 0;
}
