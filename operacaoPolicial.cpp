#include <iostream>
#include <string>
using namespace std;
struct dados {
	string nome_politico;
	string partido;
};
struct operacoes {
	string nome_operacao;
	string politico_envolvido;
	int valor;
};
int main () {
	int politicos_cadastrados, i;
	cin >> politicos_cadastrados;
	dados politico[politicos_cadastrados];
	for (i=0; i < politicos_cadastrados; i++) {
		cin >> politico[i].partido >> politico[i].nome_politico;
	}
	int operacao_policia;
	cin >> operacao_policia;
	operacoes investigacao[operacao_policia];
	for (i=0; i < operacao_policia; i++) {
		cin >> investigacao[i].nome_operacao >> investigacao[i].politico_envolvido >> investigacao[i].valor;
	}
	string nome_partido, operacao_busca;
	cin >> nome_partido >> operacao_busca;
	i=0;
	int soma = 0;
	while (i < politicos_cadastrados) {
		for (int j=0; j < operacao_policia; j++) {
			if (nome_partido == politico[i].partido and operacao_busca == investigacao[j].nome_operacao) {
				if (politico[i].nome_politico == investigacao[j].politico_envolvido) {
					soma += investigacao[j].valor;
				}
			}
		}
		i++;
	}
	cout << soma << endl;
	return 0;
}
	
