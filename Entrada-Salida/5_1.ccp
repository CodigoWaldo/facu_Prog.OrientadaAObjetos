#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream entrada("Datos.txt");
	vector<string> Palabras;
	string lectura;
	while(entrada>>lectura){
		Palabras.push_back(lectura);
	}entrada.close();
	
	for(int i=0;i<Palabras.size();i++) { 
		cout<<"Palabra "<<i+1<<": "<<Palabras[i]<<endl;
	}
	sort(Palabras.begin(),Palabras.end());
	ofstream salida("Datos.txt",ios::trunc);
	
	for(int i=0;i<Palabras.size();i++) { 
		salida<<Palabras[i]<<endl;
	}
	return 0;
}

