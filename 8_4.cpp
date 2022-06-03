#include <iostream>
#include <algorithm>

using namespace std;
int generate_10(){
	int a=(rand()%20)-10;
	return a;
}
bool menor_abs(int a,int b){
	a=abs(a);
	b=abs(b);
	return a<b;
}
bool es_par(int a){if(a>0){return a%2==0;}else{return false;}}
int main() {
	int v[20];
	generate(v,v+20,generate_10);
	for(int i=0;i<20;i++) { 
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<"La cantidad de pares="<<count_if(v,v+20,es_par)<<endl;
	sort(v,v+20,menor_abs);
	for(int i=0;i<20;i++) { 
		cout<<v[i]<<" ";
	}
	cout<<endl;
	sort(v,v+20);
	auto it_e=unique(v,v+20);
	int dist=distance(v,it_e);
	int* a=new int[dist];
	for(int i=0;i<dist;i++) { 
		a[i]=v[i];
	}
	sort(a,a+20,menor_abs);
	for(int i=0;i<dist;i++) { 
		cout<<a[i]<<" ";
	}
	delete []a;
	return 0;
}

