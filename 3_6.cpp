#include <iostream>
using namespace std;
class Fraccion{
	float numerador,denominador;
public:
	Fraccion(float a,float b):numerador(a),denominador(b){}
	float ConvertirADouble(){
		return numerador/denominador;
	}
	
};
class NumMixto{
	float entero;
	Fraccion impropia;
public:
	NumMixto(float a,float b,float c):entero(a),impropia(b,c){}
	float ConvertirADouble(){
		return entero+impropia.ConvertirADouble();
	}
};
int main() {
	float num,den,ent;
	cout<<"Ingrese el numerador y el denominador."<<endl;
	cin>>num>>den;
	Fraccion a(num,den);
	cout<<"La fraccion vale="<<a.ConvertirADouble()<<endl;
	cout<<"Ingrese el entero, numerador y el denominador."<<endl;
	cin>>ent>>num>>den;
	NumMixto b(ent,num,den);
	cout<<"vale= "<<b.ConvertirADouble();
	return 0;
}

