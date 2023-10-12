#include <iostream>
#include "ArbolB.h"
//author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

typedef Pagina<int,5> * PuntPagina;
int main(int argc, char const * argv[])
{
  ArbolB<int,5> a1;

  cout << endl << endl << endl;

  a1.insertar(10);
  a1.insertar(5);
  a1.insertar(1);
  a1.insertar(9);
  a1.insertar(8);
  a1.insertar(3);
  a1.insertar(6);
  a1.insertar(7);
  a1.insertar(2);
  a1.insertar(4);
  a1.insertar(8); //duplicada
  a1.insertar(11);
  a1.insertar(12);
  a1.insertar(13);

  cout << endl << endl << endl << " ARBOL CRECIENTE: \t" << endl;
  a1.listaCreciente(cout);
  cout << endl << endl << endl;

  PuntPagina p = a1.buscar(8);
  cout << endl << endl << "Pagina: ";
  for(int i = 1; i <= p->cont; i++)
  {
    cout << p->claves[i] << "  ";
  }

  cout << endl << endl << endl;
  PuntPagina q = a1.buscar(100);
  cout << endl << endl << endl;
  return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

