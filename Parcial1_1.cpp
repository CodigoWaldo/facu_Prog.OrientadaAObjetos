#include <iostream>
#include <vector>
using namespace std;
class Performance{
	vector<float> notas;
	int materias;
public:
	Performance(){
		notas.resize(0);
		materias=0;
	}
	Performance(int a){
		notas.resize(a);
		materias=a;
	}
	int GetMaterias(){return materias;}
	void SetNota(int a,float note){
		notas[a]=note;
	}
	float Ver(){
		float sum=0;
		for(int i=0;i<materias;i++) { 
			sum+=notas[i];
		}
		return sum/materias;
	}
};
class RendimientoCarrera{
	vector<Performance> m_r;
	int materias;
	float nota;
public:
	RendimientoCarrera(int anios):m_r(anios){
		for(int i=0;i<anios;i++) { 
			cin>>materias;
			m_r.push_back(Performance(materias));
			for(int j=0;j<materias;j++) { 
				cin>>nota;
				m_r[i].SetNota(j,nota);
			}
		}
		
	}
	float promedioanio(int a){
		return m_r[a-1].Ver();
	}
	float promediogral(){
		float a=0;
		for(int i=0;i<materias;i++) { 
			a+=promedioanio(i);
		}
		return a/materias;
	}
};
int main() {
	return 0;
}

