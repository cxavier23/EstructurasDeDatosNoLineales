#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <string>
 //author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;
using std::stack;
using std::queue;

template <typename TipoDato>
class ListaAdyacencia
{
  private:
    class NodoAdyacente
    {
      public:
        TipoDato dato;
        float peso;
        NodoAdyacente * sig;
        
        NodoAdyacente(TipoDato d, float p) : dato(d), peso(p), sig(nullptr) {};
    };
    typedef NodoAdyacente * PuntNodoAdyacente;

    class NodoDirectorio
    {
      public:
        TipoDato dato;
        NodoAdyacente * listaAd;
        NodoDirectorio * sig;
        
        NodoDirectorio(TipoDato d) : dato(d), listaAd(nullptr), sig(nullptr) {};
    };
    typedef NodoDirectorio * PuntNodoDirectorio;

    PuntNodoDirectorio grafo; //Apuntador al primer nodo de la lista principal
    int m; 
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

  public:
    ListaAdyacencia() : grafo(nullptr), m(0) {};

    void nuevoVertice(TipoDato d)
    {
        PuntNodoDirectorio nuevo = new NodoDirectorio(d);
        m++;
        nuevo->sig = grafo;
        grafo = nuevo;
    }

    PuntNodoDirectorio direccion(TipoDato v)
    {
        PuntNodoDirectorio aux = grafo;

        while (aux != nullptr)
        {
            if (aux->dato == v)
            {
                return aux;
            }

            aux = aux->sig;
        }
        return nullptr;
    }

    void nuevaArista(TipoDato origen, TipoDato destino, float peso)
    {
        PuntNodoDirectorio v1 = direccion(origen), v2 = direccion(destino);

        if (v1 && v2)
        {
            PuntNodoAdyacente ady = new NodoAdyacente(destino, peso);
            ady->sig = v1->listaAd;
            v1->listaAd = ady;
        }
    }

    void nuevaArista(TipoDato origen, TipoDato destino)
    {
      nuevaArista(origen, destino, 1);
    }

    void imprimeLista() //int, char, string
    {
        PuntNodoDirectorio y;
        PuntNodoAdyacente x;

        y = grafo;

        while (y != nullptr)
        {
            cout << " " << y->dato << ": ";
            x = y->listaAd;

            while (x != nullptr)
            {
                cout << "(" << x->dato << ", " << x->peso << ")  ";
                x = x->sig;
            }

            cout << endl;
            y = y->sig;
        }
    }

    int indice(TipoDato v)
    {
        PuntNodoDirectorio aux = grafo;
        int i = 0;

        while (aux != nullptr)
        {
            if (aux->dato == v)
            {
                return i;
            }

            aux = aux->sig;
            i++;
        }

        return -1;
    }

    void recorridoProfundidad(TipoDato v)
    {
        int marcados[m], indiceV, indiceW, indiceAdy;
        stack<TipoDato> pila;
        TipoDato w;
        PuntNodoDirectorio v1;
        PuntNodoAdyacente ady;
        
        //inicializa a todos como no visitados
        for (int i = 0; i < m; i++)
        {
          marcados[i] = -1;
        }

        //El vertice de inicio se marca como visitado
        indiceV = indice(v);
        if (indiceV < 0)
        {
            cout << endl << endl << " El vértice no existe" << endl << endl;
            return;
        }

        marcados[indiceV] = 0;
        pila.push(v); //El vértice de inicio se inserta en la pila

        while (!pila.empty())
        {
            w = pila.top();
            pila.pop();
            indiceW = indice(w);

            cout << " Nodo visitado: " << w << endl;
            ady = direccion(w)->listaAd; //Se insertan y marcan todos sus adyacentes no marcados

            while(ady)
            {
                indiceAdy = indice(ady->dato);

                if (marcados[indiceAdy] < 0)
                {
                    marcados[indiceAdy] = ady->peso;
                    pila.push(ady->dato);
                }

                ady = ady->sig;
            }
        }

        v1 = grafo;

        for(int i = 0; i < m; i++)
        {
          if(marcados[i] < 0)
          {
            w = v1->dato;
            cout << " No existe una " << v << "-" << w << " trayectoria." << endl;
          }
          
          v1 = v1->sig; 
        }
    }
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

    int exGrado(TipoDato v)
    {
      PuntNodoDirectorio x = direccion(v);
      PuntNodoAdyacente y = x->listaAd;
      int k = 0;
    
      while(y)
      {
        k++;
        y = y->sig;
      }

      return k;
    }

    void recorridoAmplitud(TipoDato v)
    {
      int marcados[m], indiceV = indice(v), indiceW, indiceAdy;
      queue<TipoDato> cola;
      TipoDato w;
      PuntNodoDirectorio v1;
      PuntNodoAdyacente ady;
      
      for(int i = 0; i < m; i++)
      {
        marcados[i] = -1;
      }

      if(indiceV < 0)
      {
        cout << endl << endl << " El vertice no existe." << endl << endl;
        return;
      }

      marcados[indiceV] = 0;
      cola.push(v);

      while(!cola.empty())
      {
        w = cola.front();
        indiceW = indice(w);
        int deg = exGrado(w);
        cola.pop();

        cout << " Nodo visitado: " << w << endl;
        cout << " d(" << v << "," << w << ") = " << marcados[indiceW] << endl;
        ady = direccion(w)->listaAd;

        for(int j = 0; j < deg; j++)
        {
            indiceAdy = indice(ady->dato);

            if(ady && marcados[indiceAdy] == -1)
            {
                marcados[indiceAdy] = marcados[indiceW] + ady->peso;
                cola.push(ady->dato);
            }

            ady = ady->sig;
        }
      }

      v1 = grafo;

      for(int i = 0; i < m; i++)
      {
        if(marcados[i] < 0)
        {
          w = v1->dato;
          cout << " No existe una " << v << "-" << w << " trayectoria." << endl;
        }

        v1 = v1->sig;
      }
    }
};
