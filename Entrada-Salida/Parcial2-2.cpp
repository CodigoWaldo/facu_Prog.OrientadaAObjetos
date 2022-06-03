#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
struct DataUser{
	int codigo;
	string sector,nombre,apellido;
};
istream &operator>>(istream &i,DataUser val){
	int cod;string sector,nombre,apellido;
	i>>cod>>sector>>nombre>>apellido;
	val.codigo=cod;val.sector=sector;val.nombre=nombre;val.apellido=apellido;
	return i;
}
class Seguridad{
	fstream entrada;
	vector<string> password;
	vector<DataUser> datos;
	string file;
public:
	Seguridad(string filename){
		entrada.open(filename);
		if(!entrada.is_open()){cout<<"Eror";}
		DataUser val;
		while(entrada>>val){
			datos.push_back(val);
			cout<<val.codigo<<" "<<val.sector<<" "<<val.nombre<<" "<<val.apellido<<endl;
		}
		entrada.close();
	}
	void GeneratePassword(){
		for(size_t i=0;i<datos.size();i++) { 
			string val=datos[i].sector+datos[i].nombre[0]+datos[i].apellido[0];
			password.push_back(val);
		}
	}
	void CreaBinario(){
		ofstream salida("passUsuarios.dat",ios::binary);
		for(size_t i=0;i<password.size();i++) { 
			char c[30];
			strcpy	(c,password[i].c_str());
			salida.write(reinterpret_cast<char*>(&c),sizeof(c));
		}
		salida.close();
	}
};
int main() {
	string a;
	cin>>a;
	Seguridad lista(a);
	return 0; 
}


