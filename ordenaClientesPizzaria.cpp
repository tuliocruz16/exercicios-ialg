/*Esse programa retorna a soma dos valores das pizzas dos
clientes mais proximos da pizzaria.
Ele recebe as coordenadas da pizzaria e dos clientes e os 
valores das pizzas, dessa forma ele analisa os locais mais proximos a pizzaria.
caso nao consiga atender a todos os clientes, ela atendera apenas aos mais proximos*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct clientes {
	string nome_cliente;
	float x_cliente;
	float y_cliente;
	float valor_pizza;
	float distancia;
};
void imprime (clientes v[], int tam) {
	float soma = 0;
	for (int i=0; i<tam; i++) {
		soma += v[i].valor_pizza;
	}
	cout << soma << endl;
}
float calculo(float x_pizzaria, float y_pizzaria, float x_cliente, float y_cliente){
	 int distancia;
	 distancia = (pow((x_pizzaria - x_cliente),2)) + (pow((y_pizzaria - y_cliente),2));
	 return sqrt (distancia);
}
void shell_sort (clientes vetor[], int tam) {
	int gaps[5] = {1, 2, 3, 8, 12};
	int pos_gap = 4;
	while(gaps[pos_gap] > tam){
		pos_gap--;
	}
	clientes valor;
	int j;
	while(pos_gap >= 0){
		int gap = gaps[pos_gap];
		for (int i = gap; i < tam; i++){
			valor = vetor[i];
			j = i;
			while ((j >= gap) and (valor.distancia < vetor[j-gap].distancia)){
				vetor[j] = vetor[j-gap];
				j = j - gap;
			}
			vetor[j] = valor;
		}
		pos_gap--;
	}
}
int main () {
	int clientes_atendidos, total_clientes;
	float x_pizzaria, y_pizzaria;
	cin >> clientes_atendidos;
	cin >> x_pizzaria >> y_pizzaria;
	cin >> total_clientes;
	clientes vetor[total_clientes];
	for (int i=0; i<total_clientes; i++) {
		cin >> vetor[i].nome_cliente;
		cin >> vetor[i].x_cliente;
		cin >> vetor[i].y_cliente;
		cin >> vetor[i].valor_pizza;
		vetor[i].distancia = calculo(x_pizzaria, y_pizzaria, vetor[i].x_cliente, vetor[i].y_cliente);
	}
	shell_sort(vetor, total_clientes);
	imprime (vetor, clientes_atendidos);
	return 0;
}
	
	
