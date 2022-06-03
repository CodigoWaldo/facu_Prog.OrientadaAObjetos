#include <iostream>
#include <vector>
using namespace std;

struct FichaMedico{
	FichaMedico(){NombreMedico="";}
	FichaMedico(string name){NombreMedico=name;}
	
	string NombreMedico;
	vector<long> dniPacientes;
};
class Clinica{
	vector<FichaMedico> fich;
public:
	Clinica(string nom1,string nom2string nom3,string nom4,string nom5,string nom6){
		fich.push_back(nom1);
		fich.push_back(nom2);
		fich.push_back(nom3);
		fich.push_back(nom4);
		fich.push_back(nom5);
		fich.push_back(nom6);		
	}
	void nuevo(int nDoc,long dniPas){
		fich[nDoc].dniPacientes.push_back(dniPas);
	}
	void mostrar(int doc){
		cout<<"El doctor "<<doc<<" tiene: "<<endl;
		for(int i=0;i<fich[doc].dniPacientes.size();i++) { 
			cout<<"Paciente "<<i+1<<" con dni: "<<fich[doc].dniPacientes[i]<<endl;
		}
	}
	void delet(long dni){
		for(int i=0;i<6;i++) { 
			for(int i=0;i<fich[i].dniPacientes.size();i++) { 
				auto it=find(fich[i].dniPacientes.begin(),fich[i].dniPacientes.end());
				if(it!=fich[i].dniPacientes.end()){
					break;
				}
			}
		}
		fich	
	}
};

int main() {
	
	return 0;
}

