#include <iostream>
using namespace std;

int main() {
	int size;
		int a[10];
		int *b=new int;
		int	*c= new int[20];
		int (*d)[10]=new int[4][10];
		//////////////////
		int **e= new int*[X];
		for(int i=0;i<X;i++) { 
			e[i]=new int*[Y];
		}
		for(int i=0;i<Y;i++) { 
			delete []e[i];
		}
		delete []e;
		//////////////////
		delete a,b,[]c;
	
	return 0;
}

