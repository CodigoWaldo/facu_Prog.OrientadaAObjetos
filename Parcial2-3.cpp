#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Carta{
	int palo,numero;	//palo de 0 a 3 son: diamante,pica,trebol,corazon
	Carta(int pal,int num){
		palo=pal;
		numero=num;
	};
};

bool operator==(Carta a, Carta b){
	if((a.palo==b.palo)&&(a.numero==b.numero)){return true;}
	else{return false;}
}

class Mazo{
	vector<Carta> baraja;
public:
	Mazo(){
		for(int i=0;i<4;i++) { 
			for(int j=0;j<12;j++) {
				Carta a(i,j);
				baraja.push_back(a);
			}
		}
	}
	Mazo(string file){
		ifstream cartasbin(file,ios::binary|ios::ate);
		int palo,valor,tot;
		tot=cartasbin.tellg()/sizeof(Carta);
		cartasbin.seekg(0);
		for(int i=0;i<tot;i++) { 
			cartasbin.read(reinterpret_cast<char*>(&palo),sizeof(int));
			cartasbin.read(reinterpret_cast<char*>(&valor),sizeof(int));
			Carta a(palo,valor);
			baraja.push_back(a);
		}
		cartasbin.close();
	}
	void Borrar(int palo, int val){
		Carta a(palo,val);
		baraja.erase(find(baraja.begin(),baraja.end(),a));
	}
};
int main() {
	
	return 0;
}

