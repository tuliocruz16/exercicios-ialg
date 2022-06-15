/*Esse programa cria um arquivo chamado matriz.txt e
recebe uma matriz quadrada, retorna no arquivo se a matriz
eh simetrica ou nao*/

#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int cont = 0;
	ifstream arquivo("matriz.txt");
	int M;
	arquivo >> M;
	int A[M][M];
	for (int i=0; i<M; i++) {
		for (int j=0; j<M; j++) {
			arquivo >> A[i][j];
		}
	}
	for (int i=0; i<M; i++) {
		for (int j=0; j<M; j++) {
			if (A[i][j] == A[j][i]) {
				cont ++;
			}
		}
	}
	if (cont == pow (M, 2)) {
		cout << "simetrica" << endl;
	}
	else {
		cout << "nao simetrica" << endl;
	}
	return 0;
}
	
