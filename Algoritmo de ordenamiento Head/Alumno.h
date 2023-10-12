#pragma once
#include <string>
//author: Christopher Xavier Sanchez Duran
//UAMC

using namespace std;
using std::string;

class Alumno
{
public:
    int id;
    string nombre;
    int edad;
    float estatura;
    
    Alumno() : id(0), nombre(""), edad(0), estatura(0) {}
    Alumno(int id, string nom, int edad, float estatura);
};

Alumno::Alumno(int id, string nom, int edad, float estatura)
{
    this->id = id;
    this->nombre = nom;
    this->edad = edad;
    this->estatura = estatura;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/



