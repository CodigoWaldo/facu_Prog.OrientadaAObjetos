#include <iostream>
#include <cmath>
using namespace std;
class EcuCua {
private:
	float coef_a,coef_b,coef_c,dim;
public:
	EcuCua(float a,float b,float c){
		coef_a=a;
		coef_b=b;
		coef_c=c;
	}
	bool TieneRaicesReales(){
		dim=pow(coef_b,2)-(4*coef_a*coef_c);
		if(dim>=0){
			return true;
		}else{
			return false;
		}
	}
	float VerParteReal(){
			return(-coef_b/2*coef_a);
		}
	float VerParteImaginaria(){
			return ((sqrt(pow(-coef_b,2)-4*coef_a*coef_c))/2*coef_a);
	}
	float VerRaiz1(){
		return ((-coef_b+sqrt(pow(coef_b,2)-4*coef_a*coef_c))/2*coef_a);
	}
	float VerRaiz2(){
		return ((-coef_b-sqrt(pow(coef_b,2)-4*coef_a*coef_c))/2*coef_a);
	}
};
int main() {
	float a,b,c;
	cout<<"Ingrese los coeficiente a, b y c\n";
	cin>>a>>b>>c;
	EcuCua ecu1(a,b,c);
	if(ecu1.TieneRaicesReales()){
		cout<<"La raiz 1 es: "<<ecu1.VerRaiz1()<<endl;
		cout<<"La raiz 2 es: "<<ecu1.VerRaiz2()<<endl;
	}else{
		cout<<"Tiene raices imaginarias.\n";
		cout<<"La raiz 1 es: "<<ecu1.VerParteReal()<<"+"<<ecu1.VerParteImaginaria();
		cout<<"La raiz 2 es: "<<ecu1.VerParteReal()<<"-"<<ecu1.VerParteImaginaria();
	}
	return 0;
}

