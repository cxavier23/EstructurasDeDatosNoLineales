#include <iostream>
#include <string>

#include "ListaAdyacencia.h"
 //author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

int main(int argc, char const *argv[])
{
    ListaAdyacencia<char> g3;

    g3.nuevoVertice('A');
    g3.nuevoVertice('B');
    g3.nuevoVertice('C');
    g3.nuevoVertice('D');
    g3.nuevoVertice('H');
    g3.nuevoVertice('R');
    g3.nuevoVertice('T');

    g3.nuevaArista('R', 'C');
    g3.nuevaArista('R', 'H');
    g3.nuevaArista('H', 'T');
    g3.nuevaArista('H', 'D');
    g3.nuevaArista('H', 'A');
    g3.nuevaArista('D', 'C');
    g3.nuevaArista('D', 'B');
    g3.nuevaArista('C', 'R');
    g3.nuevaArista('B', 'H');

    g3.imprimeLista();

    g3.recorridoProfundidad('D');

    return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

