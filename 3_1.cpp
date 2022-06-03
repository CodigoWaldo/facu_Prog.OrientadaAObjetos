#include <iostream>
using namespace std;
class Persona{
	string nombre;
	int DNI,fecha;
	bool estdCivil;
public:
//	Persona(string name,int docu,int fech,bool estado){
//		nombre=name;
//		DNI=docu;
//		fecha=fech;
//		estdCivil=estado;
//	}
	Persona(string nam,int docu,int fech,bool estado):nombre(nam),DNI(docu),fecha(fech),estdCivil(estado){}
	
	int Edad(int fechAct){
		int fechResul=(fechAct-fecha);
		return fechResul;
	}
};
class Alumno: public Persona{
	float m_prom;
	int m_mat;
public:
	Alumno(float prom,int materia,string nombre,int documento,int fecha,bool estado)
		:Persona(nombre,documento,fecha,estado),m_prom(prom),m_mat(materia){}
	float MeritoAcademico(){
		return m_prom*m_mat;
	}
};

class Docente: public Persona{
	int m_fechaing;
public:
	Docente(int fech,string nombre,int documento,int fecha,bool estado):Persona(nombre,documento,fecha,estado){
		m_fechaing=fech;
	}
	int Antiguedad(int fecha){
		return fecha-m_fechaing;
	}
};
int main() {
	string nombre;
	float prom;
	int documento,fecha,fecha1,materias;
	bool estado;
	cout<<"Ingrese el nombre: ";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Documento,fecha de nacimiento(yyyymmdd),estado civil(0 o 1),promedio y materias:\n";
	cin>>documento>>fecha>>estado>>prom>>materias;
	Alumno a(prom,materias,nombre,documento,fecha,estado);
	cout<<"Ingrese el nombre docente: ";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Documento,fecha de nacimiento(yyyymmdd),fecha antigüedad(yyyymmdd),estado civil(0 o 1)";
	cin>>documento>>fecha>>fecha1>>estado;
	Docente b(fecha1,nombre,documento,fecha,estado);
	cout<<"El merito del alumno es: "<<a.MeritoAcademico()<<endl;
	cout<<"La antiguedad del docente: "<<b.Antiguedad(20180707)<<endl;
	return 0;
}

