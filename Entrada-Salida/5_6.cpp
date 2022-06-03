#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream entrada("Don Quijote.txt");
	string Objetivo="molinos de viento";
	string Resultado;
	int contador=0;
	while(getline(entrada,Resultado)){
		int inicio=0;
//		cout<<Resultado<<endl;
		for(size_t iObjetivo.size();i<Resultado.size();i++) { 
			if(Objetivo.compare(Resultado.substr(inicio,i))){
				contador++;
			}
			inicio++;
		}
	}
	cout<<"Molino de viento, esta repetido "<<contador<<" veces en Don Quijote";
//	entrada.close();
	return 0;
}

