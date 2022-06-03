#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream salida("codigo_ascii");
	unsigned char a=0;
	for(unsigned i=32;i<256;i++){
		a=i;
		cout<<"@+"<<i<<"="<<a<<endl;
		salida<<"@+"<<i<<"="<<a<<endl;
	}
	return 0;
}

