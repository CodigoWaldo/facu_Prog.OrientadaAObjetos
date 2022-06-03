#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
struct Comision{
	vector<string> Alumnos;
	int nAlum=0;
};
istream &operator>>(istream &entra,Comision &a){
	string nombre;getline(entra,nombre);
	a.Alumnos.push_back(nombre);a.nAlum++;
	return entra;
}
int main() {
	ifstream entrada("inscriptos.txt");
	Comision General;
	while(entrada>>General){}
	entrada.close();
	int nComi=(General.nAlum/30)+1;
	stringstream ss;

	int contador=1;
	for(int i=0;i<General.nAlum;i++) {
		ss.str("");
		ss<<"Comision"<<contador;
		ofstream salida(ss.str(),ios_base::app);
		//ComiIndi[contador].Alumnos.push_back(General.Alumnos[i]);
		salida<<General.Alumnos[i]<<endl;
		salida.close();
		if(contador<nComi){contador++;}
		else {contador=1;}
	}
//	salida.close();													
	return 0;
}

