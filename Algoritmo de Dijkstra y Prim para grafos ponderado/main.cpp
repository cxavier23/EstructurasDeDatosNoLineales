#include "MatAdyacencia.h"
//author: Christopher Xavier Sanchez Duran
//UAMC

using namespace std;

int main(int argc, char const *argv[])
{
    // MatAdyacencia<int,6> grafo;

    // grafo.nuevoVertice(1);
    // grafo.nuevoVertice(2);
    // grafo.nuevoVertice(3);
    // grafo.nuevoVertice(4);
    // grafo.nuevoVertice(5);
    // grafo.nuevoVertice(6);

    // grafo.nuevaArista(1,2,2);
    // grafo.nuevaArista(2,1,2);
    // grafo.nuevaArista(1,3,1);
    // grafo.nuevaArista(3,1,1);
    // grafo.nuevaArista(1,5,3);
    // grafo.nuevaArista(5,1,3);
    // grafo.nuevaArista(1,6,6);
    // grafo.nuevaArista(6,1,6);
    // grafo.nuevaArista(2,3,3);
    // grafo.nuevaArista(3,2,3);
    // grafo.nuevaArista(2,4,2);
    // grafo.nuevaArista(4,2,2);
    // grafo.nuevaArista(3,4,4);
    // grafo.nuevaArista(4,3,4);
    // grafo.nuevaArista(4,6,5);
    // grafo.nuevaArista(6,4,5);
    // grafo.nuevaArista(5,6,4);
    // grafo.nuevaArista(6,5,4);

    // double costoMinimo = grafo.Prim(1000000);

    cout << endl << endl;

    MatAdyacencia<int,10> gr10;
    gr10.cargarDeArchivoInt(argv[1]);
    //Recibe valor infinito, regresa costo mínimo
    double costoMin2 = gr10.Prim(1000);

    cout << endl << endl;

    return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

