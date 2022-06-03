#include <iostream>
#include <ctime>
using namespace std;
class VectorDinamico{
private:
	int *p=nullptr;
	int size;
public:
	VectorDinamico(int a){
		size=a;
		p=new int[size];
		for(int i=0;i<size;i++) { 
		*(p+i)=rand()%100;	
		}
	}
	~VectorDinamico(){
		delete []p;
	}
	void Duplicar(){
		size*=2;
		int *n=new int[size];
		for(int i=0;i<(size);i++) { 
			if(i<size){
				*(n+i)=*(p+i);
			}else{
				*(n+i)=rand()%100;
			}
		}
		delete []p;
		p=n;
		delete n;
	}
	int VerElemento(int pos){
		return *(p+(pos));
	}
};
int main() {
	int tamanio,pos;
	srand(time(NULL));
	cout<<"Ingrese el tamaño del arreglo:";
	cin>>tamanio;
	VectorDinamico a(tamanio);
	for(int i=0;i<tamanio;i++) { 
		cout<<i<<":\t"<<a.VerElemento(i)<<endl;
	}
	cout<<"Ingrese el valor que desea ver(de 0 a "<<(tamanio-1)<<"):";
	cin>>pos;
	cout<<"El valor de la posicion "<<pos<<" es= "<<a.VerElemento(pos)<<endl;
	a.Duplicar();
	cout<<"El arreglo duplicado es: \n";
	for(int i=0;i<tamanio*2;i++) { 
		cout<<i<<":\t"<<a.VerElemento(i)<<endl;
	}
	a.~VectorDinamico();
	return 0;
}

