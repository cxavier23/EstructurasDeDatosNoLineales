#include <iostream> 
#include <cmath>     
#include <iomanip>   //para setw, que inserta espacios.
#include <algorithm> //para funciones_heap()
//author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

template <typename T>
void mostrarNivel(T x[], int numFilas, int nivel, int inicio, int fin)
{
  int espacio = int(pow(2.0, numFilas - nivel) - 1);
  for (int i = inicio; i <= fin; i++)
  {
      cout << setw(espacio) << " ";
      cout << setw(2) << x[i];
      cout << setw(espacio) << " ";
  }
  cout << endl << endl;
}

template <typename T>
void mostrarArbol(T x[], int n)
{
    int inicio = 0, fin = 0;
    int longNivel;
    int numNiveles = int(ceil(log(double(n)) / log(2.0)));

    for (int nivel = 0; nivel < numNiveles; nivel++)
    {
        mostrarNivel(x, numNiveles, nivel, inicio, fin);
        longNivel = fin - inicio + 1;
        inicio = fin + 1;
        fin = min(fin + 2 * longNivel, n - 1);
    }
}

int main()
{
  int x[15] = {87, 35, 74,67, 79, 84, 76, 73, 81, 32, 0, 0, 0, 0, 0};
  make_heap(x, x + 10); 
  cout << endl << " Heap inicial con el arreglo:" << endl <<endl;
  mostrarArbol(x, 10);

  x[10] = 83;
  push_heap(x, x + 11);
  cout << endl << " Heap despues de ejecutar el push:" << endl <<  endl;
  mostrarArbol(x,11);

  pop_heap(x, x + 11); 
  cout << endl << " Heap despues de ejecutar el pop:" << endl<< endl;
  mostrarArbol(x, 10); 

  sort_heap(x, x + 10);
  cout << endl << " Ejecutar Heap, el vector contiene" << endl<< endl;
  for(int i = 0; i < 10; i++)
  {
    cout << x[i] << " ";
  }
  cout << endl;

	return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

