#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
struct punto{
	float x,y;
};
class RectaExplicita{
	float m,b;
public:
	RectaExplicita(punto &p1,punto &p2){
		m=(p2.y-p1.y)/(p2.x-p1.x);
		b=(p1.y)-(m*p1.x);
	}
	string ObtenerEcu(){
		stringstream ecu;
		ecu<<setprecision(3);
		ecu<<"y= "<<m<<"*x+"<<b;
		return ecu.str();
	}
	float Ver_m(){return m;}
	float Ver_b(){return b;}
		
	};
int main() {
	punto point1,point2;
	cout<<"Ingrese el x e y, del punto 1.\nX=";
	cin>>point1.x;
	cout<<"Y=";
	cin>>point1.y;
	cout<<"Ingrese x e y, del punto 2.\nX=";
	cin>>point2.x;
	cout<<"Y=";
	cin>>point2.y;
	RectaExplicita a(point1,point2);
	cout<<"F(x)="<<a.ObtenerEcu()<<endl;
	cout<<"El valor de m="<<a.Ver_m()<<" y de b="<<a.Ver_b();
	return 0;
}

