#include <iostream>
#include <string>

#include "MatAdyacencia.h"
//author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

int main(int argc, char const *argv[])
{
    MatAdyacencia<string, 5> grafo;
    grafo.nuevoVertice("D");
    grafo.nuevoVertice("F");
    grafo.nuevoVertice("K");
    grafo.nuevoVertice("L");
    grafo.nuevoVertice("R");

    //grafo.nuevaArista("1", "2", 0);
    grafo.nuevaArista("D", "F", 1);
    grafo.nuevaArista("D", "K", 1);
  
    grafo.nuevaArista("F", "K", 1);
    grafo.nuevaArista("F", "D", 1);

    grafo.nuevaArista("K", "F", 1);

    grafo.nuevaArista("L", "F", 1);
    grafo.nuevaArista("L", "K", 1);

    grafo.nuevaArista("R", "D", 1);

    grafo.imprimeMtz();


    return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

