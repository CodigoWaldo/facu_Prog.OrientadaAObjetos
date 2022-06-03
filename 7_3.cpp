#include <iostream>
using namespace std;
template<typename temp>
class VectorDinamico{
	temp* inicio=nullptr;
	int size;
public:
	VectorDinamico(int tamanio){
		inicio=new temp[tamanio];
		size=tamanio;
	}
	template<typename random>
	VectorDinamico(int tamanio,random generador()){ 		//Se utiliza una funcion por argumento, y el cliente debe especificar la funcion
		inicio=new temp[tamanio];
		size=tamanio;
		for(int i=0;i<tamanio;i++) { 
			inicio[i]=generador();
		}
	}
	~VectorDinamico(){delete []inicio;}
	temp &operator[](int indec){
		return inicio[indec];
	}
};
string str_rand(){
	string s(3+rand()%8,'a');
	for(char &c:s){c+=rand()%('z'-'a'+1);}
	return s;
}
struct Par{
	int i;float f;
};
Par Par_rand(Par llega){
	llega.i=rand()%100;
	llega.f=(rand()%1000)/100.f;
}
int main() {
	
	return 0;
}

