#include <iostream>
#include <cmath>
using namespace std;
class Cilindro{
private:
	float radio,altura,volumen;
public:
	Cilindro(float a,float b){
		radio=a;
		altura=b;
	}
//	void AsignarDatos(float r,float h){
//		radio=r;
//		altura=h;
//	}
	float ObtenerVolumen(){
		volumen=pow(radio,2)*PI*altura;
		return volumen;
	}
};
int main() {
	float radio,altura;
	cout<<"Ingrese los datos del cilindro 1(rad,alt): "<<endl;
	cin>>radio>>altura;
	Cilindro c1(radio,altura);
	Cilindro c2(5.3,10.2);
	cout<<"El volumen del cilindro 1 es: "<<c1.ObtenerVolumen()<<endl;
	cout<<"El volumen del cilindro 2 es: "<<c2.ObtenerVolumen()<<endl;
	return 0;
}

