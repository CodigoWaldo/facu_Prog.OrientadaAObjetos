#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct Elemento{
	string campo,valor;
};
class CofigFile{
	vector<Elemento> campos;
public:
	ConfigFile(string filename){
		ifstream entrada(filename);
		Elemento pcamp;
		string aux;
		while(getline(entrada,aux)){
			if(aux.substr(0,1)!="#"){
				int pos=aux.find("=",0);
				pcamp.campo=aux.substr(0,pos-1);
				pcamp.valor=aux.substr(pos+1);
				campos.push_back(pcamp);
			}
		}
	}
};
//
//istream &operator>>(istream &entra,Elemento &a){
//	string camp,val;
//	getline(entra,camp,);getline(entra,val);
//	a.campo=camp;a.valor=val;
//	return entra;
//}

int main() {
	
	return 0;
}

