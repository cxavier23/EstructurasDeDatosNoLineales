#pragma once

#include <iostream>
#include "Pagina.h"
//author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;



template <typename T, int m>
class ArbolB
{
  private:
    typedef Pagina<T, m> * PuntPagina;
    PuntPagina root; //apuntador a la raíz del árbol

  public:
    ArbolB() : root(nullptr) {}

    void insertar(T cl);
    void empujar(PuntPagina actual, T cl, bool & sube, T & mediana, PuntPagina & nuevo);
    bool buscarNodo(PuntPagina actual, T cl, int & indice);
    void meterHoja(PuntPagina actual, T cl, PuntPagina rd, int indice);
    void dividirNodo(PuntPagina actual, T cl, PuntPagina rd, int indice, T & mediana, PuntPagina & nuevo);

    void listaCreciente(ostream & arb);
    void listaCrecienteAux(PuntPagina actual, ostream & arb);

    Pagina<T, m> * buscar(T cl);
    Pagina<T, m> * buscarAux(PuntPagina actual, T cl, int & indice);
};



template <typename T, int m>
Pagina<T, m> * ArbolB<T, m>::buscarAux(PuntPagina actual, T cl, int & indice)
{
  if(actual != nullptr)
  {
    int i = 1;

    while(i <= actual->cont && actual->claves[i] < cl) { i++; }

    if(actual->claves[i] == cl)
    {
      indice = i;
      return actual;
    }
    
    return buscarAux(actual->ramas[i-1], cl, indice);
  }
  else 
  {
    return nullptr;
  }
}

template <typename T, int m>
Pagina<T, m> * ArbolB<T, m>::buscar(T cl)
{
    int indice;
    PuntPagina p = buscarAux(root, cl, indice);

    if(p == nullptr)
    {
        cout << "Clave " << cl << " no encontrada." << endl;
    }
    else
    {
        cout << "Indice: " << indice << endl;
    }

  return p;
}


// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

template <typename T, int m>
void ArbolB<T, m>::listaCrecienteAux(PuntPagina actual, ostream & arb)
{
  if(actual != nullptr)
  {
    for(int i = 1; i <= actual->cont; i++)
    {
      listaCrecienteAux(actual->ramas[i-1], arb);
      arb << actual->claves[i] << " ";
      listaCrecienteAux(actual->ramas[i], arb);
    }
  }
}

template <typename T, int m>
void ArbolB<T, m>::listaCreciente(ostream & arb)
{
  arb << "< ";
  listaCrecienteAux(root, arb);
  arb << ">";
}



template <typename T, int m>
void ArbolB<T, m>::dividirNodo(PuntPagina actual, T cl, PuntPagina rd, int indice, T & mediana, PuntPagina & nuevo)
{
    int i, posMdna;

    //Encuentra la posición de la mediana
    posMdna = (indice <= m / 2) ? (m / 2) : m / 2 + 1;

    //copia la mitad derecha del nodo en el nodo nuevo (sin mediana)
    nuevo = new Pagina<T, m> ();

    for(i = posMdna + 1; i < m; i++)
    {
        nuevo->claves[i - posMdna] = actual->claves[i];
        nuevo->ramas[i - posMdna] = actual->ramas[i];
    }

    nuevo->cont = (m - 1) - posMdna;
    actual->cont = posMdna;

    //inserta la clave nueva en actual o en nuevo
    if(indice <= m / 2)
    {
        meterHoja(actual, cl, rd, indice);
    }
    else
    {
        meterHoja(nuevo, cl, rd, indice - posMdna);
    }

    //gurada la mediana para insertarla en el nodo superior
    mediana = actual->claves[actual->cont];
    
    nuevo->ramas[0] = actual->ramas[actual->cont];
    actual->cont--;
}

template <typename T, int m>
void ArbolB<T, m>::meterHoja(PuntPagina actual, T cl, PuntPagina rd, int indice)
{ 
  //recorre a la derecha todas las claves y ramas para insertar la clave
    int i;

    for(i = actual->cont; i >= indice + 1; i--)
    {
        actual->claves[i + 1] = actual->claves[i];
        actual->ramas[i + 1] = actual->ramas[i];
    }

    actual->claves[indice + 1] = cl;
    actual->ramas[i + 1] = rd;
    actual->cont++;
}

template <typename T, int m>
bool ArbolB<T, m>::buscarNodo(PuntPagina actual, T cl, int & indice)
{ 
  //busca la clave en el nodo actual
    bool encontrado;

    if(cl < actual->claves[1])
    {
        indice = 0; //se debe buscar en la rama en ramas[0]
        return false;
    }

    indice = actual->cont;

    while(cl < actual->claves[indice] && indice > 1)
    {
        indice--; //se detiene si la clave es mayor o igual
                  //la clave está en indice o hay que buscarla en esta rama
    }

    return cl == actual->claves[indice];
}

template <typename T, int m>
void ArbolB<T, m>::empujar(PuntPagina actual, T cl, bool & sube, T & mediana, PuntPagina & nder)
{
    int indice;

    if(actual == nullptr) //llegó al final del árbol
    {                      //si actual es root y está vacío
        sube = true;       //sube=true para que cree un nodo con mediana y nder
        mediana = cl;
        nder = nullptr;
    }
    else
    { 
      //si actual!=null, está en un nodo con claves, puede ser el raíz del árbol
        bool esta = buscarNodo(actual, cl, indice); //busca cl en el nodo actual

        if(esta) //no la inserta
        {
            cout << "Clave " <<cl << " duplicada." << endl;
            sube = false;
            return;
        }
        //si la clave no está, intenta insertarla en la rama dada por indice
        empujar(actual->ramas[indice], cl, sube, mediana, nder);

        if(sube) //si sube==true y el nodo está lleno, hay que dividir el nodo
        {         //agregar un nivel (sube=true)
            if(actual->NodoLLeno())
            {
                dividirNodo(actual, mediana, nder, indice, mediana, nder);
            }
            else
            { 
              //si el nodo no está lleno la clave se inserta en este nodo
                sube = false;
                meterHoja(actual, mediana, nder, indice);
            }
        }
    }
}

template <typename T, int m>
void ArbolB<T, m>::insertar(T cl)
{
    bool sube;            //verdadero si hay que agregar un nivel
    T mediana;     //clave que quedará en la raíz
    PuntPagina nder, aux; //apuntador al nodo derecho y apuntador auxiliar

    empujar(root, cl, sube, mediana, nder);
    //si sube es falso es que cl se inserto en algún nodo existente
    //si sube es verdadero hay que agregar un nivel sobre root

    if(sube)
    {
        aux = new Pagina<T, m>();
        aux->cont = 1;
        aux->claves[1] = mediana;
        aux->ramas[0] = root; //la raíz actual se hace hijoIzq de la clave
        aux->ramas[1] = nder; //nder es el hijoDer de la clave (empuja dividó el nodo)
        root = aux;           //la nueva raíz del árbol es el nodo que se acaba de crear
    }
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

