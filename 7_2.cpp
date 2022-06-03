#include <iostream>
using namespace std;
template <typename temp>

void Clamp(temp &var,temp min,temp max){
	if(var>max){
		var=max;
	}else if(var<min){
		var=min;
	}
}
int main() {
	int val1;
	float val2;
	string val3,comp1,comp2;
	cin>>val1>>val2>>val3>>comp1>>comp2;
	Clamp(val1, 10, 100);
	Clamp(val2, 5.f, 10.f);
	Clamp(val3, comp1,comp2);
	cout<<val1<<endl<<val2<<endl;
	return 0;
}

