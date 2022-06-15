

#include <iostream>
using namespace std;
struct Hidrocarboneto {
	int C, H;
};
int main () {
	int carbono, hidrogenio;
	cin >> carbono >> hidrogenio;
	Hidrocarboneto *ptr;
	int tam = sizeof (Hidrocarboneto);
	ptr = new Hidrocarboneto[tam];
	cout << ((carbono * 12) + (hidrogenio * 1));
	delete[] ptr;
	return 0;
}
	
