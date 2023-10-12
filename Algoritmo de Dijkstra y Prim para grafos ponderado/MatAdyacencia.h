#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
//author: Christopher Xavier Sanchez Duran
//UAMC

using namespace std;
using std::ifstream;
using std::string;
using std::stack;
using std::queue;

template <typename T, int m>
class MatAdyacencia
{
  private:
    int numVertices;
    T vertices[m];
    double mtz[m][m];

public:
    MatAdyacencia()
    {
      numVertices = 0;
      for (int i = 0; i < m; i++)
      {
          vertices[i] = T();

          for (int j = 0; j < m; j++)
          {
              mtz[i][j] = 0;
          }
      }
    }

    void nuevoVertice(T dato)
    {
      vertices[numVertices] = dato;
      numVertices++;
    }

    int buscar(T v)
    {
      for (int i = 0; i < numVertices; i++)
      {
          if (vertices[i] == v)
          {
              return i;
          }
      }
      
      return -1;
    }

    void nuevaArista(T u, T v, double w)
    {
      int indiceU, indiceV;

      indiceU = buscar(u);
      indiceV = buscar(v);

      if (indiceU >= 0 && indiceV >= 0)
      {
        mtz[indiceU][indiceV] = w;
      }
      else
      {
        cout << "Error al agregar arista" << endl;
      }
    }

    void nuevaArista(T u, T v)
    {
      nuevaArista(u, v, 1);
    }
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

    void imprimeMtz()
    {
      for (int i = 0; i < m; i++)
      {
        cout << " [\t";

        for (int j = 0; j < m; j++)
        {
            cout << mtz[i][j] << "\t";
        }
        
        cout << "]" << endl;
      }
    }

    void recorerAnchura(T v) //dijkstra sin pesos
    {
      int marcados[m], indiceV = buscar(v), w;
      queue<int> cola;

        
      for (int i = 0; i < m; i++) //iniciar los vértices como no marcados
      {
        marcados[i] = -1;
      }
      
      if (indiceV < 0)
      {
        cout << " El vertice no existe" << endl;
        return;
      }

      marcados[indiceV] = 0; //El vertice de inicio se marca como visitado
      cola.push(indiceV);

      while (!cola.empty())
      {
        w = cola.front();
        cola.pop();

        cout << " Nodo visitado: " << vertices[w] << endl;
        cout << " d(" << v << "," << vertices[w] << ") = " << marcados[w] << endl;

        //Se encolan y marcan todos sus adyacentes no marcados
        for (int i = 0; i < m; i++)
        {
          if (mtz[w][i] && marcados[i] < 0)
          {
            marcados[i] = marcados[w] + mtz[w][i];
            cola.push(i);
          }
        }
      }

      for(int i = 0; i < m; i++)
      {
        if(marcados[i] < 0)
        {
          cout << " No existe una " << v << "-" << vertices[i] << " trayectoria." << endl;
        }
      }
    }

    void recorerProfundidad(T v) //DFS
    {
      int marcados[m], indiceV = buscar(v), w;
      stack<int> pila;

        
      for(int i = 0; i < m; i++)
      {
        marcados[i] = -1;
      }
      
      if(indiceV < 0)
      {
        cout << " El vertice no existe" << endl;
        return;
      }

      marcados[indiceV] = 0;
      pila.push(indiceV);

      while(!pila.empty())
      {
        w = pila.top();
        pila.pop();
        cout << " Nodo visitado: " << vertices[w] << endl;
        
        for(int i = 0; i < m; i++)
        {
          if(mtz[w][i] && marcados[i] < 0)
          {
            marcados[i] = mtz[w][i];
            pila.push(i);
          }
        }
      }

      for(int i = 0; i < m; i++)
      {
        if(marcados[i] < 0)
        {
          cout << " No existe una " << v << "-" << vertices[i] << " trayectoria." << endl;
        }
      }
    }

    void cargarDeArchivoInt(string nombre)
    {
        ifstream archivo; //objeto archivo
        archivo.open(nombre);

        for (int i = 0; i < m; i++)
        {
            nuevoVertice(i);
            for (int j = 0; j < m; j++)
            {
              archivo >> mtz[i][j];
            }
        }
    }

    int minimo(int F[], int D[], double max)
    {
        int u;
        int min = max;

        for (int j = 0; j < m; j++)
        {
            if (F[j] == 0 && D[j] < min)
            {
                min = D[j];
                u = j;
            }
        }
        return u;
    }

    void dijkstra(T vs, double max)
    {
        int F[m]; //seleccionados(1) y no seleccionados(0)
        int D[m]; //distancia al origen
        int U[m]; //predecesor en el camino
        int u;    //vertice arbitrario u

        for (int i = 0; i < m; i++)
        {
            if (i == vs)
            {
                F[i] = 1; //el origen es seleccionado
            }
            else
            {
                F[i] = 0;
            }

            D[i] = mtz[vs][i]; //Se establecen las distancias

            if (D[i] < max)
            {
                U[i] = vs; //Peso de flecha desde el origen
            }
            else
            {
                U[i] = -1; //No es exvecino del origen
            }
        }

        for (int i = 1; i < m; i++)
        {
            u = minimo(F, D, max); //Se identifica u con la menor distancia a vs
            F[u] = 1; //Se selecciona

            for (int j = 0; j < m; j++)
            { //Se actualiza D y U para los elementos en V-F
                if (F[j] == 0 && D[u] + mtz[u][j] < D[j])
                {
                    D[j] = D[u] + mtz[u][j];
                    U[j] = u;
                }
            }
        }

        cout << endl << "Distancias minimas desde v = " << vs << ":" << endl << "\t[\t";

      
        for (int j = 0; j < m; j++)
        {
            if (D[j] == max)
            {
              cout << "inf" << "\t";
            }
            else
            {
              cout << D[j] << "\t";
            }
        }
        cout << "\t]" << endl << endl << "Predecesores:" << endl << "\t[\t";

        for (int j = 0; j < m; j++)
        {
            cout << U[j] << "\t";
        }

        cout << "\t]" << endl;
    }

    double Prim(double inf)
    {
        double costoMinimo, menor, costo[m];
        int z, masCerca[m], W[m];

        //actualiza el valor infinito en la matriz de adyacencia
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mtz[i][j] == 0)
                {
                    mtz[i][j] = inf;
                }
            }
        }

        //Inicializa 

        for (int i = 0; i < m; i++)
        {
            W[i] = 0;
        }

        costoMinimo = 0;

        for (int i = 0; i < m; i++)
        {
            masCerca[i] = -1;
            costo[i] = inf;
        }

        //Selecciona el vértice 0 como raíz
        W[0] = 1;

        for (int i = 1; i < m; i++)
        {
            //El más cercanoae W, a i de V-W, es 0 (el único en W por el momento)
            masCerca[i] = 0;
            costo[i] = mtz[i][0];
        }

        for (int i = 1; i < m; i++)
        {
            //busca z en V-W con la arista de menor costo a W
            menor = costo[1];
            z = 1;

            for (int j = 2; j < m; j++)
            {
                if (costo[j] < menor)
                {
                    menor = costo[j];
                    z = j;
                }
            }

            //Cambia vz de V-W a W y actualiza costoMínimo
            W[z] = 1;
            costoMinimo += costo[z];
            costo[z] = inf; 

            //Imprime el vértice en el árbol, el vértice recientemente seleccionado y el costo
            cout << vertices[masCerca[z]] + 1 << " -> " << vertices[z] + 1 << ", \tc = " << mtz[masCerca[z]][z] << endl;

            //Actualiza costo[] y masCerca[] de los no seleccionados, considerando que ahora z está en el árbol.
            for (int j = 1; j < m; j++)
            {
                if (W[j] == 0 && costo[j] > mtz[z][j])
                {
                    masCerca[j] = z;
                    costo[j] = mtz[z][j];
                }
            }
        }

        cout << endl << "C = " << costoMinimo << endl;

        return costoMinimo;
    }
};
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

