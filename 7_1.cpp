#include <iostream>
using namespace std;
template <typename Algo>	
Algo Mayor(Algo primero, Algo segundo){
//	return primero>segundo ? primero : segundo;
		if(primero>segundo){return primero;}
		else{return segundo;}
}

struct Persona{
	string nombre;
	string apellido;
	int dni;
};
ostream &operator<<(ostream &sale, Persona a){
	sale<<a.nombre<<" "<<a.apellido<<endl;
	sale<<"Con dni: "<<a.dni<<".";
	return sale;
}
bool operator>(Persona a, Persona b){
	if(a.dni<b.dni){return true;}
	else{return false;}
}
istream &operator>>(istream &entra,Persona a){
	cout<<"Ingrese el nombre: ";
	string nam;entra>>nam;a.nombre=nam;
	cout<<"Ingrese el apellido: ";
	string ape;entra>>ape;a.apellido=ape;
	cout<<"Ingrese el dni: ";
	int dni;entra>>dni;a.dni=dni;
	return entra;
}
int main(int argc, char *argv[]) {
//	int a,b;
//	cout<<"Ingrese a y b de int"<<endl;
//	cin>>a>>b;
//	cout<<"El mayor es "<<Mayor(a,b)<<endl;
//	float c,d;
//	cout<<"Ingrese a y b de float"<<endl;
//	cin>>c>>d;
//	cout<<"El mayor es "<<Mayor(c,d)<<endl;
//	string e,f;
//	cout<<"Ingrese a y b de string"<<endl;
//	cin>>e>>f;
//	cout<<"El mayor es "<<Mayor(e,f)<<endl;
	Persona a1,a2;
	cout<<"Ingrese el a y b de Persona"<<endl;
	cin>>a1>>a2;
	cout<<"El mayor es "<<Mayor(a1,a2);
	return 0;
}

