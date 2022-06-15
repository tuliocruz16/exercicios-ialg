/*Esse programa recebe caracteristicas de um produto e pede ao cliente
para que procure um item desejado, caso nao ache, o programa retorna -1.
do contrario ele retorna o item e suas caracteristicas.*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct deposito {
    string produto;
	string descricao;
    float preco;
    int avaliacao;
};
void ordena(deposito vetor[], int comeco, int metade, int fim, string item_desejado){
    int c = comeco;
    int aux = fim - comeco + 1;
    int m = metade + 1;
    int i = 0;
    deposito vet[aux];
    while (i < aux) {
        if (c > metade) {
            vet[i] = vetor[m];
            m++;
        }
        else if (c <= metade and m <= fim) {
            if (vetor[c].avaliacao >= vetor[m].avaliacao) {
                vet[i] = vetor[c];
                c++;
            }
            else {
                vet[i] = vetor[m];
                m++;
            }
        }
        else {
            vet[i] = vetor[c];
            c++;
        }
        i++;
    }
    for (i = 0; i < aux; i++) {
        vetor[comeco + i] = vet[i]; 
    }
}
void mergesort (deposito vetor[], int comeco, int fim, string item_desejado) {
    int metade;
    if(comeco < fim) {
        metade = (comeco + fim)/2;
        mergesort(vetor, comeco, metade, item_desejado);
        mergesort(vetor, metade + 1, fim, item_desejado);
        ordena(vetor, comeco, metade, fim, item_desejado);
    }
}

int main() {
    int quantidade, i;
    cin >> quantidade;
    deposito vetor[quantidade];
    for(i=0; i<quantidade; i++) {
        cin >> vetor[i].produto >> vetor[i].descricao >> vetor[i].preco >> vetor[i].avaliacao;
    }
    string produto_desejado;
    cin >> produto_desejado;
    mergesort (vetor, 0, quantidade - 1, produto_desejado);
    
    int nao_encontrado = - 1;
    i=0;
    while (i < quantidade) {
        if (vetor[i].produto == produto_desejado) {
            cout << setprecision(2) << fixed;
            cout << vetor[i].produto << " " << vetor[i].descricao << " " << vetor[i].preco << " " << vetor[i].avaliacao << endl;
            nao_encontrado++;
        }
        i++;
    }
    if (nao_encontrado == -1) {
		cout << nao_encontrado;
	}    
    return 0;
}
