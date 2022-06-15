/*Esse programa recebe o numero de linhas e colunas de uma matriz e depois
le duas matrizes com os requisitos passados, entao gera uma terceira matriz
com a soma do elemento aij da primeira com o elemento aij da segunda*/

#include <iostream>
#include <iomanip>
using namespace std;

int **AlocarMatriz(int nLins, int nCols) {
    int **matriz;
    matriz = new int*[nLins];
    for (int i = 0; i < nLins; i++){
		matriz[i] = new int[nCols];
	}
	return matriz;
}

void DesalocarMatriz(int **matriz, int nLins) {
	for (int i = 0; i < nLins; i++){
		delete[] matriz[i];
	}
	delete[]matriz;
}

int **Somar(int **m1, int **m2, int nroLinhas, int nroColunas, int **m3) {
    for (int lin = 0; lin < nroLinhas; ++lin) {
        for (int col = 0; col < nroColunas; ++col) {
            m3[lin][col] = m1[lin][col] + m2[lin][col];
        }
    }
    return m3;
}

void LerMatriz(int **matriz, int nroLinhas, int nroColunas) {
    for (int lin = 0; lin < nroLinhas; ++lin) {
        for (int col = 0; col < nroColunas; ++col) {
            cin >> matriz[lin][col];
        }
    }
}
int main() {
    int nLins, nCols;
    cin >> nLins >> nCols;
    
    int** m1 = AlocarMatriz(nLins, nCols);
    LerMatriz(m1, nLins, nCols);

    int** m2 = AlocarMatriz(nLins, nCols);
    LerMatriz(m2, nLins, nCols);

    int** m3 = AlocarMatriz(nLins, nCols);
    Somar(m1, m2, nLins, nCols, m3);

    for (int lin = 0; lin < nLins; ++lin) {
        for (int col = 0; col < nCols; ++col) {
            cout << setw(5) << m3[lin][col];
        }
        cout << "\n";
    }

    DesalocarMatriz(m1, nLins);
    DesalocarMatriz(m2, nLins);
    DesalocarMatriz(m3, nLins);
    return 0;
}
