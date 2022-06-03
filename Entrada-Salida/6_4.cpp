#include <iostream>
#include <fstream>
using namespace std;
void escribir(fstream &archi,int pos,string frase){
	archi.seekg(pos);
	archi.write(reinterpret_cast<char*>(&frase),sizeof(frase));
}
void escribir(fstream &archi,int pos,int val){
	archi.seekg(pos);
	archi.write(reinterpret_cast<char*>(&val),sizeof(val));
}
int main(int argc, char *argv[]) {
	stringstream filename;
	string cabecera="mswxp";
	for(int i=1;i<=78;i++) { 
		filename>>"desing">>i>>".wds";
		ofstream writer(filename.str(),ios::binary);
		escribir(writer,178,filename.str());
		escribir(writer,239,2016);
		writer.close();
		filename.str("");
	}
	return 0;
}

