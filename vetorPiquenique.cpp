/* Esse programa simula um piquenique, no qual professores levam alimentos.
primeiro ele recebe quantos tipos de alimentao serao e a quantidade de
cada alimento, depois o nome dos professores e a quantidade que cada professor
vai comer dentre dois tipos de alimentos, e retorna o que sobrou do que foi
comido no piquenique */

#include <iostream>
#include <string>
using namespace std;

struct alimentos {
	string tipo_alimento;
	int alimento_necessario;
};

struct professores {
	string nome_professores;
	string primeiro_alimento;
	int quantidade_primeiro;
	string segundo_alimento;
	int quantidade_segundo;
};

int main () {
	int quantidade_alimento, i;
	cin >> quantidade_alimento;
	alimentos comida[quantidade_alimento];
	for (i=0; i < quantidade_alimento; i++) {
		cin >> comida[i].tipo_alimento >> comida[i].alimento_necessario;
	}
	int participantes;
	cin >> participantes;
	professores individuo[participantes];
	for (i=0; i < participantes; i++) {
		cin >> individuo[i].nome_professores;
		cin >> individuo[i].primeiro_alimento;
		cin >> individuo[i].quantidade_primeiro;
		cin >> individuo[i].segundo_alimento;
		cin >> individuo[i].quantidade_segundo;
	}
	int sobra=0;
	for (i=0; i < quantidade_alimento; i++) {
		for (int j=0; j < participantes; j++) {
			if (comida[i].tipo_alimento == individuo[j].primeiro_alimento) {
				sobra = comida[i].alimento_necessario - individuo[j].quantidade_primeiro;
				comida[i].alimento_necessario = sobra;
			}
			if (comida[i].tipo_alimento == individuo[j].segundo_alimento) {
				sobra = comida[i].alimento_necessario - individuo[j].quantidade_segundo;
				comida[i].alimento_necessario = sobra;
			}
			else {
				sobra = comida[i].alimento_necessario;
			}
		}
		cout << comida[i].tipo_alimento << " " << sobra << endl;
	}
	return 0;
}	
