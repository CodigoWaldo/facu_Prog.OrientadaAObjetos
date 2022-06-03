/*
1)El intento de abrir archivos de diferente formato (p.e. un archivo binario en forma de txt o biceversa) solo
generara errores de lectura ya que al momento de escribir o leer los datos cada formato tiene sus propias formas 
y metodos, asi si se quiere hacer un .read en un txt dara error o un <<valor en un binario.
2)No es posible directamente (metodo .write), sino que se necesita un proceso previo de transformacion del dato,
es decir, se tiene que convertir el string a cadena de texto, osea, un char array, y luego a ese array hacerle
el metodo write del binario, ya que de lo contrario estaria solamente guardando la posicion de memoria del puntero 
al string.
3)Instanciar una plantilla es una instruccion para que el compilador pueda reconocer donde hay una plantilla, ya 
que si no, una plantilla no tiene tipo o valor, haciendo que el compilador no pueda reconocer esa forma de dato.
este proceso por entonces es totalmente necesario para el correcto funcionamiento del uso de plantilla.
El compilador reconoce como y cuando especializar la plantilla cuando, en una clase se la declara como argumento 
entre los <...> o en una funcion cuando se pasa el tipo como argunmento de la misma, en esta ultima no es necesario
aclarar el tipo ya que el compilador puede deducir solo.
4)Un iterador es un objeto que se utiliza como operador de los contenedores, es decir, dentro de todos los datos de un
contenedor (vector,lista,mapa..) un iterador es un objeto que pertenece al mismo tipo de dato dentro del contendor, asi
se pueden utilizar metodos y operaciones sin modificar directamente el contendor, agilizando los mecanismos.
5)Para poder organizar un std::vector de strucs, se puede utilizar algun metodo hecho a mano por el desarrollador, o bien
usar metodos de la STL, el cual puede ser el metodo sort que en cuyos argumentos recibe el iterador de inicio y el de fin
del vector y puede ser un puntero a funcion, la cual determine de alguna forma el valor de comparacion entre dos objetos
del tipo del struct, ej:
struct Persona{string nombre,int dni};
bool comp_menor(Persona a, Persona b){if(a.dni>b.dni){return true;} else{return false;}
sort(vector.begin(),vector.end(),comp_menor);
