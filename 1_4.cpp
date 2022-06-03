#include <iostream>
using namespace std;
int * buscar(int *a,int b,int c){
	for(int i=0;i<b;i++) { 
		if(*(a+i)==c){
			return a+i;
		}
	}
	return nullptr;
}
int main() {
	const int a=20;
	int vec[a];
	int val;
	for(int i=0;i<a;i++) { 
		vec[i]=rand()%20+1;
	}
	cin>>val;
	int *p=buscar(vec,a,val);
	if(p==nullptr){
		cout<<"El valor indicado no existe en el arreglo.";
	}else{
		cout<<"El valor esta en la posicion de memoria: "<<p<<" y en el lugar "<<(p-vec)<<" del arreglo";
	}delete p;
	return 0;
}

