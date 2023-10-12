#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <stack>
 //author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;
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

    int buscar(T v) // Busca un vértice en el grafo y devuelve su índice. Si no se encuentra, devuelve -1.
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
    // Agrega una nueva arista entre los vértices u y v con un peso w.
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
    
    // author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

 // Agrega una nueva arista entre los vértices u y v con un peso predeterminado de 1.
    void nuevaArista(T u, T v)
    {
      nuevaArista(u, v, 1);
    }

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
// Realiza un recorrido en anchura (BFS) a partir del vértice v y muestra el resultado.
    void recorerAnchura(T v)/ Implementación de BFS
    {
      int marcados[m], indiceV = buscar(v), w, procesados = 0;
      queue<int> cola;

        
      for (int i = 0; i < m; i++) //iniciar los vÃ©rtices como no marcados
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
        procesados++;

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

    void recorerProfundidad(T v) // Realiza un recorrido en profundidad (DFS) a partir del vértice v y muestra el resultado.
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
};
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

