#include <iostream>
#include <queue>
//author: Christopher Xavier Sanchez Duran
//UAMC
#include "Alumno.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////

class comparaEstatura
{
	public:
	bool operator()(Alumno x, Alumno y)
	{
		return x.estatura > y.estatura;
	}
};
///////////////////////////////////////////////////////////////////////////////////////

class comparaNombre
{
	public:
	bool operator()(Alumno x, Alumno y)
	{
		if (x.nombre == y.nombre)
			return x.nombre[0] > y.nombre[0];
		int i = 0;
		while (x.nombre[i] == y.nombre[i])
		{
			i++;
		}
		return x.nombre[i] > y.nombre[i];
	}
};
///////////////////////////////////////////////////////////////////////////////////////

class comparaEdads
{
	public:
	bool operator()(Alumno x, Alumno y)
	{
		return x.edad > y.edad;
	}
};

///////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
  
	Alumno a1(1, "Alma", 21, 1.60);
	Alumno a2(2, "Beto", 25, 1.55);
	Alumno a3(3, "Cesar", 19, 1.85);
	Alumno a4(4, "Diana", 24, 1.65);
	Alumno a5(5, "Estela", 30, 1.75);
	Alumno a6(6, "Fer", 23, 1.65);


// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/
	

	cout << endl;

//PARA nombre
//	priority_queue<Alumno, vector<Alumno>, comparaNombre> cp2;

//	cp2.push(a1);
//	cp2.push(a2);
//	cp2.push(a3);
//	cp2.push(a4);
//	cp2.push(a5);
//	cp2.push(a6);

//	cout << endl;
 // cout<<"Nombre"<<endl;
//  cout<<"<<Prioridad>> "<<endl;
//	cout << "Tamaño: " << cp2.size() << endl;
//	cout << "Mayor prioridad: "  << cp2.top().nombre << endl;
//	cout << "<<ELIMINAA>> " << endl;
//	cp2.pop();
//	cout << "Mayor prioridad ColaP2: "<< cp2.top().nombre << endl;


///////////////////////////////////////////////////////////////////////////////////////

//Para Edad
//  priority_queue<Alumno, vector<Alumno>, comparaEdads> cp2;

//    cp2.push(a1);
//    cp2.push(a2);
//    cp2.push(a3);
//    cp2.push(a4);
//    cp2.push(a5);
//    cp2.push(a6);
//
//    cout << endl;

//cout << "Tamaño Prioridad: " << cp2.size() << endl;
//	cout << "Individuo mayor prioridad: " <<  cp2.top().nombre << ": " << cp2.top().edad << endl;
//	cout << "<<ELIMINAR>>" << endl;
//	cp2.pop();
//	cout << "Nuevo con mayor prioridad: " <<  cp2.top().nombre << ": " << cp2.top().edad << endl;

///////////////////////////////////////////////////////////////////////////////////////







	cout << endl;


	return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

