#include <iostream>
#include <string>

#include "ListaAdyacencia.h"
//author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

int main(int argc, char const *argv[])
{
    ListaAdyacencia<string> grafo;

    grafo.nuevoVertice("1");
    grafo.nuevoVertice("2");
    grafo.nuevoVertice("3");
    grafo.nuevoVertice("4");
    grafo.nuevoVertice("5");

    //grafo.nuevaArista("1", "2", 0);
    grafo.nuevaArista("1", "2", 1);
    grafo.nuevaArista("1", "4", 1);
    grafo.nuevaArista("1", "5", 1);
        

    grafo.nuevaArista("2", "1", 1);
    grafo.nuevaArista("2", "3", 1);
    
    grafo.nuevaArista("3", "2", 1); 
    grafo.nuevaArista("3", "4", 1);

    grafo.nuevaArista("3", "5", 1);
    grafo.nuevaArista("4", "1", 1);
    grafo.nuevaArista("4", "3", 1);

    grafo.nuevaArista("5", "1", 1);
    grafo.nuevaArista("5", "3", 1);

    
    grafo.imprimeLista();

    return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

