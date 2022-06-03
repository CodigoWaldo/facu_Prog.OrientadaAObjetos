#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

class Polinomio{
private:
	float coef[20];
	int grado;
public:
	Polinomio(int grad){
		grado=grad;
		for(int i=0;i<20;i++) { 
			coef[i]=0;
		}
	}
	void CambCoef(int pos,float coeficiente){
		coef[pos]=coeficiente;
	}
	float VerCoef(int a){
		if(a>GetGrado()){
			return 0;
		}else{
		return coef[a];
		}
	}
	int GetGrado(){return grado;}
	Polinomio SumPol(Polinomio b){
		int c;
		if(GetGrado()>=b.GetGrado()){
			c=GetGrado();
		}else{
			c=b.GetGrado();
		}
		Polinomio a(c+1);
		for(int i=0;i<a.GetGrado();i++) { 
			a.CambCoef(i,(coef[i]+b.VerCoef(i)));
		}
		return a;
	}
	float Evaluar(float a){
		float b;
		for(int i=0;i<GetGrado();i++) { 
			b+=coef[i]*pow(a,i);
		}
		return b;
	}
	float GetCoef(int a){
		return coef[a];
	}
};
int main() {
	srand(time(NULL));
	int grado;
	float coef;
	cout<<"Ingrese el grado: ";
	cin>>grado;
	grado++;
	Polinomio a(grado);
	for(int i=0;i<a.GetGrado();i++) { 
		cout<<"Ingrese el coeficiente de grado: "<<i<<"=";
		cin>>coef;
		a.CambCoef(i,coef);
	}
	Polinomio b(3);
	for(int i=0;i<b.GetGrado();i++) { 
		coef=rand()%3;
		b.CambCoef(i,coef);
		cout<<"\nCoef "<<i<<"= "<<b.VerCoef(i);
	}
	
	Polinomio p_sum(0);
	p_sum=a.SumPol(b);
	cout<<"\nEl polinomio de la suma resultante es: \n";
	for(int i=0;i<p_sum.GetGrado();i++) { 
		cout<<p_sum.GetCoef(i)<<"x^"<<i<<" ";
	}
	cout<<"\nIngrese el valor de x a evaluar: ";
	cin>>coef;
	cout<<"\n\a Resultado="<<p_sum.Evaluar(coef);
	return 0;
}

