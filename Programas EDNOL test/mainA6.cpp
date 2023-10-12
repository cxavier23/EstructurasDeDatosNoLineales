#include <iostream>

#include "Persona.h"
 //author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

int main(int argc, char const *argv[])
{
    
    Persona *p1 = new Persona("Ana",27);

    cout<< "nombre_p1:   " << p1->nombre    <<endl;
    cout<< "edad_p1:     " << p1->getEdad() <<endl;
    p1->estatura = 1.65;
    cout<< "estatura_p1: " << p1->estatura  <<endl;

    Persona p2 = Persona("Beto", 28);
    cout<< "nombre_p2:   " << p2.nombre    <<endl;
    cout<< "edad_p2:     " << p2.getEdad() <<endl;
    p2.estatura = 1.75;
    cout<< "estatura_p2: " << p2.estatura  <<endl;

    p2.setConyugue(p1);
    cout<<"conyugue_p2:  " << p2.conyugue->nombre<<endl;
    

    return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

//Compilación:  g++ mainA6.cpp
//ejecución:    ./a.out
