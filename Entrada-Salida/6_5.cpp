#include <iostream>
#include <fstream>
using namespace std;


class Puntos{
	fstream datos;
	int total;
public:
	Puntos(string name,int tot){
		datos.open(name,ios::binary|ios::in|ios::out|ios::ate);
		total=tot;
		if(!datos.is_open()){ cout<<"Error en la carga del archivo.";}
	}
	void escribir(int posicion,int valor){
		datos.seekg((total-1)*sizeof(int));
		for(int i=total;i>=posicion;i--) { 
			datos.write(reinterpret_cast<char*>(&datos[i-1]),sizeof(int));
		}
		datos.write(reinterpret_cast<char*>(&valor),sizeof(int));
	}
	bool nuevo_punto(int punto){
		int comparar=datos[total];
		if(comparar>=punto){return false;}
		else{
			int pos=datos.buscar(punto);
			datos.escribir(pos,punto);
			return true;
		}
	}
	int buscar(int valor){
		for(int i=1;i<=total;i++) { 
			int comparar=datos[i];
			if(comparar<=valor){
				return i;
			}
		}
	}
	int operator[](int val){
		int puntoDevolver;
		if(val==0){datos.seekg((val)*sizeof(int));}
		else{datos.seekg((val-1)*sizeof(int));}
		datos.read(reinterpret_cast<char*>(&puntoDevolver),sizeof(int));
		datos.seekg(0);
		return puntoDevolver;
	}
};
int main(int argc, char *argv[]) {
	int total=10;
	Puntos tabla("Tabla_Puntos",total);
	for(int i=0;i<total;i++) { 
		tabla.nuevo_punto(rand()%100);
		cout<<"Dato "<<i+1<<": "<<tabla[i];
	}
	tabla.nuevo_punto(105);
	for(int i=0;i<total;i++) { 
		//		tabla.nuevo_punto(rand()%100);
		cout<<"Dato "<<i+1<<": "<<tabla[i];
	}
	return 0;
}

