#include <iostream>
using namespace std;
class Tecla{
	bool estado;
	string nota;
public:
	Tecla(string a):nota(a),estado(0){}
	string VerNota(){return nota;}
	void Apretar(){estado=true;}
	void Soltar(){estado=false;}
	bool EstaApretada(){
		return estado;
	}
};
class Pedal{
	float presion;
public:
	Pedal():presion(0){}
	float GetPresion(){return presion;}
	void SetPresion(float a){presion=a;} 
};
class Piano{
	Tecla a[7];
	Pedal ped;
public:
	Piano(){
		for(int i=0;i<7;i++) { 
			string nota;
			cin>>nota;
			a[i](nota);
		}
	}
};
int main() {
	Piano xd;
	return 0;
}

