#include <iostream>
using namespace std;
template<typename temp, int N=3>
class vectorEs{
	temp vec[N];
	int tot=N;
public:
	vectorEs(){
		for(int i=0;i<tot;i++) { 
			vec[i]=0;
		}
	}
	vectorEs(temp val){
		for(int i=0;i<tot;i++) { 
			vec[i]=val;
		}
	}
	int GetTotal(){return tot;}
	temp &operator[](int i){
		return vec[i];
	}
};

template<typename temp, int N>
vectorEs<temp,N> operator+(vectorEs<temp,N> &a,vectorEs<temp,N> &b){
	for(int i=0;i<a.GetTotal();i++) { 
		a[i]+=b[i];
	}
	return a;
}
int main() {
	vectorEs<int,5> a(10), b(30);
	a=b+a;
	for(int i=0;i<a.GetTotal();i++) { 
		cout<<a[i]<<" ";
	}
	return 0;
}

