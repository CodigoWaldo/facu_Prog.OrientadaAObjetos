#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	int val;
	vector<int> v;
	for(int i=0;i<15;i++) { 
		v.push_back(rand()%100);
	}
	for(size_t i=0;i<v.size();i++){cout<<v[i]<<" ";}
	cout<<endl;	
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){cout<<*it<<" ";}
	cout<<endl;
	for(int &x:v){cout<<x<<" ";}
	vector<int>::iterator valmax=max_element(v.begin(),v.end());
	vector<int>::iterator valmin=min_element(v.begin(),v.end());
	int tot=accumulate(v.begin(),v.end(),0);
	int prom=tot/v.size();
	
	cout<<endl;
	cout<<"el max="<<*valmax<<" el min="<<*valmin;
	cout<<endl;
	cout<<"el tot="<<tot<<" el prom="<<prom;
	
	cin>>val;
	if(count(v.begin(),v.end(),val)){
		vector<int>::iterator findi=find(v.begin(),v.end(),val);
		cout<<"Si esta y en la pos"<<findi;
	}else{cout<<"no esta";}
	
	
	return 0;
}

