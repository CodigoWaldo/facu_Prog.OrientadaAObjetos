#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


template<typename temp>
list<temp> vector_a_lista(const vector<temp> &v){
	list<temp> l;
	vector<temp> v2=v;
	sort(v2.begin(),v2.end());
	auto it_e=unique(v2.begin(),v2.end());
	v2.erase(it_e,v2.end());
	for(size_t i=0;i<v2.size();i++) { 
		l.push_back(v2[i]);
	}
	return l;
}

int main() {
	vector<int> algo={2,8,4,12,8,10,12,11,2};
	list<int> listita=vector_a_lista(algo);
	for( list<int>::iterator it=listita.begin(); it!=listita.end(); ++it ) { 
		cout<<*it<<" ";
	}
	return 0;
}

