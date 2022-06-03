#include <iostream>
#include <ctime>
using namespace std;
void insertar(int *a,int c,int d){
	*(a+d)=c;
}
int main() {
	int N,ref;
	int *pos;
	ref=0;
	cout<<"Introdusca la cantidad de datos: ";
	cin>>N;
	int *p=new int[N];
	srand(time(NULL));
	for(int i=0;i<N;i++) { 
		*(p+i)=rand()%500+1000;
	}
	for(int i=0;i<N;i++) { 
		if(*(p+i)>=ref){
			pos=p+i;
			ref=*pos;
		}
	}
	cout<<"La posicion de memoria del mayor es: "<<pos<<"\ten el arreglo: "<<pos-p<<"\nCon valor="<<*pos<<endl;
	int val1,val2;
	cout<<"Ingrese el valor y la posicion en la que se inserte."<<endl<<"Valor:";
	cin>>val1;
	cout<<"Posicion: ";
	cin>>val2;
	insertar(p,val1,(val2-1));
	for(int i=0;i<N;i++) { 
		cout<<"Posicion: "<<i+1<<"\t en memoria: "<<p+i<<"\t con valor: "<<*(p+i)<<endl;
	}
	delete []p;
	delete pos;
	return 0;
}

