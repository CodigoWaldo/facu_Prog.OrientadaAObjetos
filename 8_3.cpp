#include <iostream>
#include <list>
using namespace std;
void mostrar(const list<float> &a){
	auto it=a.begin();
	while(it!=a.end()){
	cout<<*it<<" ";
	++it;
	}
	cout<<endl;
}
int main() {
	list<float> v;
	float val;
	int tot;
	cout<<"Ingrese el total de datos: ";cin>>tot;
	for(int i=0;i<tot;i++) { 
		val=(rand()%200)/10.f;
		v.push_back(val);
	}
	mostrar(v);
	for( list<float>::iterator it=v.begin(); it!=prev(v.end()); it=next(it,2)) {
		auto it1=it;
		auto it2=next(it);
		val=(*it1+*it2)/2;
		v.insert(next(it),val);
	}
	mostrar(v);
	
	
	return 0;
}

