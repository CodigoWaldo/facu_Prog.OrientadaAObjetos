#include <iostream>
using namespace std;

template<typename temp>
void ChangePos(temp &val1,temp &val2){
	val1=val1+val2;
	val2=val1-val2;
	val1=val1-val2;
}
int main() {
	int a=2,b=5;
	float c=2.3,d=7.9;
	ChangePos(a,b);
	ChangePos(c,d);
	cout<<a<<" "<<b<<endl;
	cout<<c<<" "<<d<<endl;
	
	return 0;
}

