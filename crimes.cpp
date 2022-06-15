#include <iostream>
using namespace std;
struct pessoa {
	string nome;
	string alvo;
};
struct crimes {
	string nome_plano;
	string nome_vilao;
	int prejuizo;
};
int main () {
	int quantidade_vilao, i;
	cin >> quantidade_vilao;
	pessoa vilao[quantidade_vilao];
	for (i = 0; i < quantidade_vilao; i++) {
		cin >> vilao[i].nome >> vilao[i].alvo;
	}
	int quantidade_planos;
	cin >> quantidade_planos;
	crimes planos[quantidade_planos];
	for (i=0; i < quantidade_planos; i++) {
		cin >> planos[i].nome_plano >> planos[i].nome_vilao >> planos[i].prejuizo;
	}
	string alvo_desejado;
	cin >> alvo_desejado;
	i=0;
	bool existe_plano = false;
	while (i < quantidade_vilao) {
		if (alvo_desejado == vilao[i].alvo) {
			for (int j = 0; j < quantidade_planos; j++) {
				if (vilao[i].nome == planos[j].nome_vilao) {
					existe_plano = true;
					cout << planos[j].nome_plano << " " << planos[j].prejuizo << endl;
				}
			}
		}
		i++;
	}
	if (not existe_plano) {
		cout << "-1";
	}
	return 0;
}
