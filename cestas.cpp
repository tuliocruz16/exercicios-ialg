#include <iostream>
#include <string> 
using namespace std;
struct visitante {
	string nome_comprador;
	string cesta_comprada;
};
struct cestas {
	string nome_cesta;
	int porcoes;
};
int main () {
	int cestas_vendidas, cestas_disponiveis, i;
	cin >> cestas_disponiveis;
	cestas informacoes[cestas_disponiveis];
	for (i = 0; i < cestas_disponiveis; i++) {
		cin >> informacoes[i].nome_cesta >> informacoes[i].porcoes;
	}
	cin >> cestas_vendidas;
	visitante individuo[cestas_vendidas];
	for (i=0; i < cestas_vendidas; i++) {
		cin >> individuo[i].nome_comprador >> individuo[i].cesta_comprada;
	}
	i=0;
	int soma = 0;
	while (i < cestas_disponiveis){
		for (int j=0; j < cestas_vendidas; j++) {
			if (informacoes[i].nome_cesta == individuo[j].cesta_comprada){
				soma += informacoes[i].porcoes;
			}
		}
	i++;
	}
	cout << soma << endl;
	return 0;
}
