#include <iostream>
#include <cmath>
using namespace std;
float PI=3.141696;
class Tanque{
public:
	float m_vol,m_peso;
	Tanque(float pes):m_peso(pes){}
	void SetPeso(float a){m_peso=a;}
	void virtual CalcularVol() =0;
	float GetVol(){return m_vol;}
	float GetPeso(){return m_peso;}
};
class Cilindro: public Tanque{
	float radio,altura;
public:
	Cilindro(float rad, float alt,float peso):Tanque(peso) {radio=rad;altura=alt;}
	void CalcularVol(){
		m_vol=(PI*pow(radio,2))*altura;
	}
};
class Esfera: public Tanque{
	float radio;
public:
	Esfera(float rad,float peso):Tanque(peso){radio=rad;}
	void CalcularVol(){
		m_vol=((4/3)*PI)*pow(radio,3);
	}
};
int main() {
	float radio,altura,peso;
	cout<<"Ingrese los datos del cilindo."<<endl;
	cout<<"Radio:";cin>>radio;
	cout<<"Altura:";cin>>altura;
	cout<<"Peso:";cin>>peso;
	Cilindro objA(radio,altura,peso);
	Tanque *p;
	p=&objA;
	objA.CalcularVol();
	cout<<"Vol= "<<p->GetVol()<<" Peso= "<<p->GetPeso()<<endl;
	cout<<"Ingrese los datos de la esfera."<<endl;
	cout<<"Radio:";cin>>radio;
	cout<<"Peso:";cin>>peso;
	Esfera objB(radio,peso);
	p=&objB;
	objB.CalcularVol();
	cout<<"Vol= "<<p->GetVol()<<" Peso= "<<p->GetPeso()<<endl;
	return 0;
}

