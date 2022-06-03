#include <iostream>
using namespace std;
class Fecha{
	int fech;
public:
	Fecha(int yyyymmdd){
		fech=yyyymmdd;
	}
	int GetFecha(){return fech;}
//	int GetDia(){return fech%100;}
//	int GetMes(){return (fech%10000)/100;}
//	int GetAnio(){return fech/10000;}

};
bool operator<=(Fecha a,Fecha b){
	if(a.GetFecha()>=b.GetFecha()){
		return true;
	}else {return false;}
}

int main() {
	Fecha a(19970326),b(19970325);
	cout<< (a<=b);
		return 0;
}

