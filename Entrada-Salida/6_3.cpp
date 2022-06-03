#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream maker("Lista_Arreglada",ios::binary);
	if(!maker.is_open()){
		cout<<"Error 404 Not Found.";
		return 1;
	}
	int valor=0;
	for(int i=0;i<=200;i++) { 
		valor=i*5;
		maker.write(reinterpret_cast<char*>(&valor),sizeof(int));
	}maker.close();
	///////////////////////////////////////////////////////////////////////
	fstream reader("Lista_Arreglada",ios::binary|ios::ate|ios::in|ios::out);
	if(!reader.is_open()){
		cout<<"Error 404 Not Found.";
		return 2;
	}
	int total=reader.tellg()/sizeof(int);
	reader.seekg(0);									//Se puede usar seekg(0,ios::end) para ir al fin del binario
	cout<<"Ingrese el valor a buscar: ";				//Tambien con seekg(-10,ios::cur) para la 10 menos de
													// de la posicion actual
	cin>>valor;
	int comparador,pos;
	for(int i=0;i<total;i++){
		reader.read(reinterpret_cast<char*>(&comparador),sizeof(int));
		if(comparador<=valor){
			pos=i;
		}else break;
	}pos++;
	for(int i=(total-1);i>=pos;i--) { 
		reader.seekg(i*sizeof(int));
		reader.read(reinterpret_cast<char*>(&comparador),sizeof(int));
//		reader.seekg((i+1)*sizeof(int));
		reader.write(reinterpret_cast<char*>(&comparador),sizeof(int));
	}
	reader.seekg(pos*sizeof(int));
	reader.write(reinterpret_cast<char*>(&valor),sizeof(int));
	reader.seekg(0);
	for(int i=0;i<total;i++) { 
		reader.read(reinterpret_cast<char*>(&comparador),sizeof(int));
		cout<<comparador<<endl;
	}
	
	return 0;
}

