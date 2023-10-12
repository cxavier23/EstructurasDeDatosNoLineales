#include <iostream>
//author: Christopher Xavier Sanchez Duran
//UAMC
#include "ABB.h"

using namespace std;

int main() 
{
	ABB<char> raizABB;

	raizABB.insertar('O');
    raizABB.insertar('C');
    raizABB.insertar('T');
    raizABB.insertar('O');
    raizABB.insertar('A');
    raizABB.insertar('M');
    raizABB.insertar('P');
    raizABB.insertar('U');
    raizABB.insertar('R');
    raizABB.insertar('M');

	cout<<"\nArbol binario de busqueda de caracteres"<<endl;
	raizABB.preorden(cout);
	cout<<endl;

	cout<<"Elemento encontrado O: " << raizABB.buscar('O')<<endl;
	cout<<"Elemento encontrado X: " << raizABB.buscar('X')<<endl;

	cout<<"Eliminar O"<<endl;
	raizABB.eliminar('O');
	raizABB.preorden(cout);
	cout<<endl;

	cout<<"Eliminar M"<<endl;
	raizABB.eliminar('M');
	raizABB.preorden(cout);
	cout<<endl;


	ABB<int> raizEnt;

	raizEnt.insertar(10);
	raizEnt.insertar(20);
	raizEnt.insertar(30);
	raizEnt.insertar(40);
	raizEnt.insertar(50);
	raizEnt.insertar(60);
	raizEnt.insertar(70);
	raizEnt.insertar(80);


	cout<<"\nArbol binario de busqueda"<<endl;
	raizEnt.preorden(cout);
	cout<<endl;

	cout<<"Nuevo Arbol:"<<endl;
	raizEnt.eliminar(50);
	raizEnt.preorden(cout);
	cout<<endl;

	cout<<"Nuevo Arbol:"<<endl;
	raizEnt.eliminar(80);
	raizEnt.preorden(cout);
	cout<<endl;

	cout<<"Nuevo Arbol:"<<endl;
	raizEnt.eliminar(10);
	raizEnt.preorden(cout);
	cout<<endl;
	
	return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/


