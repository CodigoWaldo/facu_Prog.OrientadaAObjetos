#include <iostream>
using namespace std;
class Racional{
	int num,den;
public:
	Racional(){num=0;den=0;}
	Racional(int a, int b):num(a),den(b){}
	int GetNum(){return num;}
	int GetDen(){return den;}
	void SetNum(int a){num=a;}
	void SetDen(int a){den=a;}
	Racional &operator++(){
		num+=den;
		return *this;
	}
};
int denominador(int a,int b){
	int c=a*b;
	return c;
}
int numerador(Racional a, int denom){
	int c=a.GetNum()*(denom/a.GetDen());
	return c;	
}
Racional operator+(Racional a,Racional b){
	int denom=denominador(a.GetDen(),b.GetDen());
	int num=numerador(a,denom)+numerador(b,denom);
	
	Racional c(num,denom);
	return c;
}
Racional operator=(Racional a){
	Racional c(a.GetNum(),a.GetDen());
	return c;
}
Racional operator-(Racional a, Racional b){
	int denom=denominador(a.GetDen(),b.GetDen());
	int num=numerador(a,denom)-numerador(b,denom);
	
	Racional c(num , denom);
	return c;
}

Racional operator*(Racional a, int b){
	Racional c(a.GetNum()*b,a.GetDen()*b);
	return c;
}
Racional operator*(Racional a, Racional b){
	Racional c(a.GetNum()*b.GetNum(),a.GetDen()*b.GetDen());
	return c;
}
Bool operator==(Racional a,Racional b){
	if((a.GetNum()==b.GetNum())&&(a.GetDen()==b.GetDen())) return true;
	else return false;
}
ostream &operator<<(ostream &o,Racional a){
	o<<a.GetNum()<<"/"<<a.GetDen();
	return o;
}
istream &operator>>(istream &i, Racional a){
	int b;i>>b;a.SetNum(b);
	int c;i>>b;a.SetDen(c);
	return i;
}

int main() {
	Racional a(5,3),b(3,2),c;
	c=a+b;
	cout<<"C="<<c<<endl;
	c=c*5;
	++c;
	cout<<"C="<<c<<endl;
	c=c*a;
	cout<<"C="<<c;
	return 0;
}

