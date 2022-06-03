#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Monomio{
	float exponente,coeficiente;
public:
	
	Monomio(int a,float b):exponente(a),coeficiente(b){}
	
	float Evaluar(float a){
		if(exponente>0){
			return (coeficiente*(pow(a,exponente)));
		}else{
			return coeficiente;
		}
	}
};
class Polinomio{
	vector<Monomio> poli;
public:
	void SetValue(int grado,float coef){
		poli.push_back(Monomio(grado,coef));
	}
	float Evaluar(float x){
		float a;
		for(unsigned int i=0;i<poli.size();i++) { 
			a+=poli[i].Evaluar(x);
		}
		return a;
	}
};
int main() {
	int grado;
	cout<<"Ingrese el grado del Polinomio: ";
	cin>>grado;
	Polinomio a;
	float coe;
	for(int i=0;i<=grado;i++) {
		cout<<"Ingrese el coeficiente de grado: "<<i<<"= ";
		cin>>coe;
		a.SetValue(i,coe);
	}
	cout<<"Ingrese el X a evaluar: ";
	cin>>coe;
	cout<<"y="<<a.Evaluar(coe);
	return 0;
}

