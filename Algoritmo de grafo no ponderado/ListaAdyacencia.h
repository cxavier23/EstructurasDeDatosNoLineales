#pragma once

#include <iostream>
//author: Christopher Xavier Sanchez Duran
//UAMC

template <typename TipoDato>
class ListaAdyacencia
{
private:
    class NodoAdyacente
    {
	public:
		TipoDato dato;
		float peso;
		NodoAdyacente *sig;
		//Constructor
		NodoAdyacente(TipoDato d, float p) : dato(d), peso(p), sig(nullptr){};
    };
    typedef NodoAdyacente *PuntNodoAdyacente;

    class NodoDirectorio
    {
		public:
			TipoDato dato;
			NodoAdyacente *listaAd;
			NodoDirectorio *sig;
			//Constructor
			NodoDirectorio(TipoDato d) : dato(d), listaAd(nullptr), sig(nullptr){};
    };
    typedef NodoDirectorio *PuntNodoDirectorio;

    //Apuntador al primer nodo de la lista principal
    PuntNodoDirectorio grafo;

public:
    //Constructor
    ListaAdyacencia() : grafo(nullptr){};

    //Funciones

    void nuevoVertice(TipoDato d)
    {
		PuntNodoDirectorio nuevo = new NodoDirectorio(d);
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
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

    void nuevaArista(TipoDato origen, TipoDato destino, float peso)
    {
		PuntNodoDirectorio v1, v2;
		v1 = direccion(origen);
		v2 = direccion(destino);

		if (v1 && v2)
		{
			PuntNodoAdyacente ady = new NodoAdyacente(destino, peso);
			ady->sig = v1->listaAd;
			v1->listaAd = ady;
		}
    }
    
    void nuevaArista(TipoDato origen, TipoDato destino)
    {
		PuntNodoDirectorio v1, v2;
		v1 = direccion(origen);
		v2 = direccion(destino);

		if (v1 && v2)
		{
			PuntNodoAdyacente ady = new NodoAdyacente(destino, 1);
			ady->sig = v1->listaAd;
			v1->listaAd = ady;
		}
    }

    void imprimeLista()
    { //Solo para int, char, string.
		PuntNodoDirectorio y;
		PuntNodoAdyacente x;

		y = grafo;

		while (y != nullptr)
		{
			std::cout <<  y->dato << ": ";
			x = y->listaAd;
			while (x != nullptr)
			{
				std::cout << "(" << x->peso << ", " << x->dato << ") ";
				x = x->sig;
			}
			std::cout << std::endl;
			y = y->sig;
		}
    }
};
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

