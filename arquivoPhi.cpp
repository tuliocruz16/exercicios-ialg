/*Esse programa gera um arquivo com o calculo do numero de 
phi baseado em quantos termos foram lidos no comeco do programa*/

#include <iostream>
#include <fstream>
using namespace std;
double calcula (int limite) {
	double phi = 0;
	ofstream arquivo ("phi.txt");
	for (int n=1; n<=limite; n++) {
		if (limite == 1) {
			arquivo << 1;
			cout << 1;
		}
		else {
			phi = 1 /(n-1);
			arquivo << phi;
		}
	}
	return phi;
}
int main () {
	int num_termos;
	cin >> num_termos;
	calcula (num_termos);
	return 0;
}
