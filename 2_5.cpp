#include <iostream>
using namespace std;
struct Alumno{
	string nombre;
	float nota;
};
class Materia{
private:
	Alumno *p=nullptr;
	Alumno *pmax=nullptr;
	int AlumCant,AlumCantAnt;
	float prom;
	float max=0;
public:
	Materia(int cant){
		AlumCant=cant;
		AlumCantAnt=0;
		if(cant<=40){
			p=new Alumno[AlumCant];
		}else{
			p=new Alumno[40];
		}
	}
	void SetAlum(int pos,string nom, float val){
		(*(p+pos)).nombre=nom;
		(*(p+pos)).nota=val;
	}
	void AddAlum(string nom, float val){
		AlumCant++;
		Alumno *n=new Alumno[AlumCant];
		for(int i=0;i<AlumCant;i++) { 
			if(i<(AlumCant-1)){
				(*(n+i)).nombre=(*(p+i)).nombre;
				(*(n+i)).nota=(*(p+i)).nota;
			}else{
				(*(n+i)).nombre=nom;
				(*(n+i)).nota=val;
			}
		}
		delete []p;
		p=n;
		delete n;
	}
	Alumno * GetMaxNota(){
		if(AlumCantAnt!=AlumCant){
			for(int i=0;i<AlumCant;i++) { 
				if((*(p+i)).nota>=max){
					max=(*(p+i)).nota;
					pmax=(p+i);
				}
			}
			AlumCantAnt=AlumCant;
			return pmax;
		}else{
			return pmax;
		}
		
	}
	float Promedio(){
		for(int i=0;i<AlumCant;i++) { 
			prom+=(*(p+i)).nota;
		}
		return (prom/AlumCant);
	}
	~Materia(){
		delete []p;
		delete pmax;
	}
};

int main() {
	int alumnos;
	float nota;
	Alumno *p=nullptr;
	string nombre;
	cout<<"Ingrese la cantidad de alumnos que hay en la materia (<40): ";
	cin>>alumnos;
	Materia Lengua(alumnos);
	for(int i=0;i<alumnos;i++) { 
		cout<<"Ingrese el Nombre del alumno "<<(i+1)<<": ";
		cin.ignore();
		getline(cin,nombre);
		cout<<"Ingrese la Nota: ";
		cin>>nota;
		Lengua.SetAlum(i,nombre,nota);
	}
	cout<<"Ingrese el nombre y nota del alumno a agregar\n";
	cin.ignore();
	getline(cin,nombre);
	cin>>nota;
	Lengua.AddAlum(nombre,nota);
	cout<<"El promedio de la materia es: "<<Lengua.Promedio()<<endl;
	p=Lengua.GetMaxNota();
	cout<<"El alumno que tuvo la nota mas alta es: "<<endl;
	cout<<(*p).nombre<<"\t"<<(*p).nota;
	Lengua.~Materia();
	delete p;
	return 0;
}

