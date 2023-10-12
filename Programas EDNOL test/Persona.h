#include <string>
#include <list>
 //author: Christopher Xavier Sanchez Duran
//UAMC
class Persona
{
private:
    int edad_;
    
public:
    std::string nombre;
    float estatura;

    Persona(std::string nom, int edad);

    int getEdad();
    void setConyugue(Persona *conyugue);
    Persona *conyugue;

    ~Persona();
};

Persona::Persona(std::string nom, int edad)
{
    this->nombre = nom;
    this->edad_ = edad;
}

int Persona::getEdad()
{ 
    return edad_;
}

void Persona::setConyugue(Persona *conyugue)
{ 
    this->conyugue = conyugue;
}

Persona::~Persona()
{
    delete conyugue;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

