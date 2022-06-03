#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Alumno{
	string nombre;
	int nota1,nota2;
	float prom;
	unsigned char estado;
};
void modificar(ofstream &sale,Alumno a, vector<Alumno> &vec){
	for(unsigned int i=0;i<vec.size();i++) { 
		if(a.nombre==vec[i].nombre){
			vec[i]=a;
		}
	}
}
istream &operator>>(istream &entrada, Alumno &a){
	getline(entrada,a.nombre);
	entrada>>a.nota1>>a.nota2;
	entrada.ignore();
	return entrada;
}
ostream &operator<<(ostream &salida,Alumno a){
	salida<<a.nombre<<endl;
	salida<<a.nota1<<" "<<a.nota2<<endl;
	return salida;
}
void promedio(vector<Alumno> &vec){
	ofstream salida("promedio.txt",ios::trunc);
	float prom;
	for(unsigned int i=0;i<vec.size();i++) { 
		prom=(vec[i].nota1+vec[i].nota2)/2;
		vec[i].prom=prom;
		if(prom>=60){
			vec[i].estado=65;
		}else{
			vec[i].estado=68;
		}
		salida<<vec[i].nombre<<endl;
		salida<<vec[i].prom<<" "<<vec[i].estado<<endl;
	}
}
int main() {
	ifstream entrada("lista.txt");
	vector<Alumno> vecAlum;
	Alumno a;
//	cout<<entrada.is_open()<<endl;					//Booleano que identifica si la entrada esta activa
	while(entrada>>a){
		vecAlum.push_back(a);
		cout<<a;
	}
	cout<<"Ingrese el nombre del alumno y la nota 1 y 2 que desea cambiar.";
	entrada.close();
	cin>>a;
	ofstream salida("lista.txt",ios::trunc);
	modificar(salida, a,vecAlum);
	for(unsigned int i=0;i<vecAlum.size();i++) { 
		salida<<vecAlum[i];
		cout<<vecAlum[i];
	}
	promedio(vecAlum);
	return 0;
}

