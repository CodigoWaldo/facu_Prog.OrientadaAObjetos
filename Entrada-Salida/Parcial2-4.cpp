#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
class Factura{
	struct Cliente{
		string nombre,apellido;
		int dni;
		float saldo;
	};
	vector<Cliente> v;
public:
	bool Guardar(string file){
		ofstream archi(file,ios::binary);
		if(!archi.is_open()){return false;}
		for(Cliente x:v){
			char nom[30],ape[30];
			strcpy(nom,x.nombre.c_str());
			strcpy(ape,x.apellido.c_str());
			archi.write(nom,30);
			archi.write(ape,30);
			archi.write(reinterpret_cast<char*>(&x.dni),sizeof(int));
			archi.write(reinterpret_cast<char*>(&x.saldo),sizeof(float));
		}
		return true;
	}
	bool Leer(string file){
		ifstream archi(file,ios::binary|ios::ate);
		if(!archi.is_open()){return false;}
		int tot=archi.tellg()/sizeof(Cliente);
		archi.seekg(0);
		for(int i=0;i<tot;i++) { 
			Cliente a;
			char nom[30],ape[30];
			archi.read(nom,30);
			archi.read(ape,30);
			archi.read(reinterpret_cast<char*>(&a.dni),sizeof(int));
			archi.read(reinterpret_cast<char*>(&a.saldo),sizeof(float));
			a.nombre=nom;a.apellido=ape;
			v.push_back(a);
		}return true;
	}
	void Agregar(Cliente a){
		v.push_back(a);
	}
	bool Eliminar(int dni){
		for( vector<Cliente>::iterator it=v.begin(); it!=v.end(); ++it ) { 
			if(*it.dni==dni){v.erase(it);return true;}else{return false;}
		}
	}
	Cliente operator[](int i){
		return v[i];
	}
};
int main() {
	
	return 0;
}

