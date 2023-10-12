#include "MatAdyacencia.h"
 //author: Christopher Xavier Sanchez Duran
//UAMC

using namespace std;

int main(int argc, char const * argv [])
{
    if (argc<2)
    {
        cout << "./a.out nombreArchivo" << endl;
        return 420;
    }

    MatAdyacencia<int,7> grafo;
    grafo.cargarDeArchivoInt(argv[1]); // para leer archivo desde terminal: ./a.out nombreArchivo.txt 

    grafo.imprimeMtz();
    grafo.dijkstra(3, 6969);
    

    return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/
