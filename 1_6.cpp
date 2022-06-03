#include <iostream>
using namespace std;
int * redimensionar(int *a,int b){
	int *c=new int[b];
	delete []a;
	return c;
}
int main() {
	int N,c;
	cout<<"Ingrese la longitud del vector: ";
	cin>>N;
	int *p=new int[N];
	for(int i=0;i<N;i++) { 
		*(p+i)=rand()%200;
	}
	cout<<"\nIngrese cuantos ceros quiere insertar:";
	cin>>c;
	p=redimensionar(p,(N+c));
	for(int i=0;i<N+c;i++) { 
		if(i<N){
			*(p+i)=
		}
		cout<<*(p+i)<<" ";
	}
	return 0;
}

