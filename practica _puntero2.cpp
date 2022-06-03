#include <iostream>
using namespace std;

int main() {
	int* p= new int[10];
	/*p=nullptr;*/
	for(int i=0;i<10;i++) {
		*(p+i)=rand()%100;
		cout<<"En la posicion "<<p+i<<" esta almacenado:"<<p[i]<<endl;
	}
	p[1]=3;
	//DESREFERENCIA	
	cout<<"posicion: "<<p;
	delete []p;
	return 0;
}

