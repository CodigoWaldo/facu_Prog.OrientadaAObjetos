#include <iostream>
using namespace std;

int main() {
	int var1=10;
	int *var2=new int;
	cin>>*var2;
	cout<<"Posicion de memoria: v1="<<&var1<<" y v2="<<var2<<endl;
	cout<<"Valores: v1="<<var1<<" y v2="<<*var2;
	delete var2;
	return 0;
}

