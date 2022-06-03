#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<typename temp>
class ManejadorArchivo{
	int regis_t;
	string filename;
	fstream registro;
	vector<temp> registro_mem;
public:
	ManejadorArchivo(string name){
		filename=name;
		registro.open(filename,ios::binary|ios::in|ios::out|ios::ate);
		regis_t=registro.tellg()/sizeof(temp);
		registro.seekg(0);
		temp val;
		for(int i=0;i<regis_t;i++) {
			registro.read(reinterpret_cast<char*>(&val),sizeof(temp));
			registro_mem.push_back(val);
		}
	}
	bool is_open(){return registro.is_open();}
	int size(){return regis_t;}
	temp &operator[](int pos){
		return registro_mem[pos];
	}
	void guardar(){
		for(int i=0;i<regis_t;i++) { 
			registro.seekg(0,ios::end);
			registro.write(reinterpret_cast<char*>(&registro_mem[i]),sizeof(registro_mem));
//			registro.seekg(0);
		}
	}
};
int main() {
	string filename;
	getline(cin,filename);
	ManejadorArchivo<int> regis(filename);
	if(regis.is_open()){cout<<"Error en la carga.";}
	//
	return 0;
}

