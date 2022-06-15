#include <iostream>
#include <string>
using namespace std;
struct Cartinha {
    string nome;
    string pedido;
};
struct Brinquedo {
    string tipo_brinquedo;
    int brinquedo_disponivel;
    int quantidade_pedida=0;
};
int main () {
    int cartas, i;
    cin >> cartas;
    Cartinha crianca[cartas];
    for (i=0; i < cartas; i++) {
        cin >> crianca[i].nome >> crianca[i].pedido;
    }
    int quantidade_brinquedo;
    cin >> quantidade_brinquedo;
    Brinquedo informacoes[quantidade_brinquedo];
    for (i=0; i < quantidade_brinquedo; i++) {
        cin >> informacoes[i].tipo_brinquedo >> informacoes[i].brinquedo_disponivel;
    }
    for (i=0; i < cartas; i++) {
        for (int j=0; j < quantidade_brinquedo; j++) {
            if (crianca[i].pedido == informacoes[j].tipo_brinquedo) {
                informacoes[j].quantidade_pedida++;
                if (informacoes[j].quantidade_pedida > informacoes[j].brinquedo_disponivel) {
                    cout << informacoes[j].tipo_brinquedo << " ";
                }
            }
        }
    }
    cout << endl;
    return 0;
}
