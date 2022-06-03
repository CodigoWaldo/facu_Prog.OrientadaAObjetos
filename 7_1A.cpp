#include <iostream>
#include <ArchivoBinario.h>
using namespace std;

template <typename temp>
class Rect{
	temp largo,ancho;
public:
	Rect(){largo=0;ancho=0;}
	Rect(temp largo_rec, temp ancho_rec):largo(largo_rec),ancho(ancho_rec){}
	temp GetAncho(){return ancho;}
	temp GetLargo(){return largo;}
};
template<typename temp>
ostream &operator<<(ostream &o, Rect<temp> objOut){
		o<<objOut.GetAncho()<<", "<<objOut.GetLargo()<<endl;
		return o;
}

int main() {
	Rect<int> ObjA(20,50);
	Rect<float> ObjB(10.f, 30.f);
	ArchivoBin<Rect> guardado("Rect.dat");
	cout<<ObjA<<ObjB;
	return 0;
}

