#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void mostrar(const vector<int> &a){
	for(int x:a){cout<< x<<" ";}
	cout<<endl;
}
bool compare(int a,int b){
	return a>b;
}
int main() {
	vector<int> v(30);
	for(int &x:v){x=(rand()%25)+1;}
	mostrar(v);
	sort(v.begin()+10,v.begin()+20,compare);
	mostrar(v);
	vector<int> a(10);
	for(size_t i=0;i<a.size();i++) { 
		a[i]=*(v.begin()+10);
		v.erase(v.begin()+10);
	}	
	mostrar(v);
	mostrar(a);
	int val;cin>>val;
	cout<<"el valor aparece: "<<count(v.begin(),v.end(),val)<<endl;
	auto it_errase=remove(v.begin(),v.end(),val);
	v.erase(it_errase,v.end());
	mostrar(v);
	
	return 0;
}

