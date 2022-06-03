#include <iostream>
#include <list>
#include <fstream>
using namespace std;

list<string> ListarIncludes(string filename){
	ifstream archi(filename);
	string val;
	string a;
	list<string> l;
	while(getline(archi,val)){
		if(val.substr(0,8)=="#include"){
			size_t ref1=val.find("<");
			if(ref1==string::npos){
				size_t ref1=val.find('"');
				if(ref1==string::npos){
					continue;
				}else{
					a=val.substr(ref1);
				}
			}else{
				a=val.substr(ref1);
			}
			l.push_back(a);
		}
	}
	return l;
}

int main() {
	list<string> algo;
	algo=ListarIncludes("Includes.txt");
	cout<<"Los includes son: "<<endl;
	for( list<string>::iterator it=algo.begin(); it!=algo.end(); ++it ) { 
		cout<<*it<<endl;
	}
	return 0;
}

