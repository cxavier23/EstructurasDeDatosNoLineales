#include <iostream>
#include <string>

#include "MatAdyacencia.h"
 //author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

int main(int argc, char const *argv[])
{
    MatAdyacencia<char, 7> g2;
    g2.nuevoVertice('A');
    g2.nuevoVertice('B');
    g2.nuevoVertice('C');
    g2.nuevoVertice('D');
    g2.nuevoVertice('H');
    g2.nuevoVertice('R');
    g2.nuevoVertice('T');

    g2.nuevaArista('B','H');
    g2.nuevaArista('C','R');
    g2.nuevaArista('D','B');
    g2.nuevaArista('D','C');
    g2.nuevaArista('H','A');
    g2.nuevaArista('H','T');
    g2.nuevaArista('H','D');
    g2.nuevaArista('R','H');
    g2.nuevaArista('R','C');
    g2.imprimeMtz();

    g2.recorerAnchura('D');

    return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

