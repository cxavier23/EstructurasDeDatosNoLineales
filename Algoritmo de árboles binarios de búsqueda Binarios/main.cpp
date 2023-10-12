#include <iostream>
#include "AB.h"
//author: Christopher Xavier Sanchez Duran
//UAMC

using namespace std;

int main()
{
	AB<char> arbol;
  char entrada[10] = {'O','C','T','O','A','M','P','U','R','M'};

  for(char c : entrada)
  {
    arbol.insertar(c);
  }

	cout << endl << " PREORDEN: \t";
  arbol.preorden(cout);
  cout << endl << endl << " INORDEN: \t";
  arbol.inorden(cout);
  cout << endl << endl << " POSORDEN: \t";
  arbol.posorden(cout);
  cout << endl << endl;
	
	return 69;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/
