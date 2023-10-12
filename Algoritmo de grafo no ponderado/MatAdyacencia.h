#pragma once

#include <iostream>
#include <string>
//author: Christopher Xavier Sanchez Duran
//UAMC
template <typename TipoDato, int m>
class MatAdyacencia
{
private:
    int numVertices;      //número de vertices actuales
    TipoDato vertices[m]; //Conjunto de vértices
    double mtz[m][m];     //Matriz deAdyacencia/dePesos

public:
    MatAdyacencia()
    { //Constructor
		numVertices = 0;
		for (int i = 0; i < m; i++)
		{
			vertices[i] = TipoDato();
			for (int j = 0; j < m; j++)
			{
				mtz[i][j] = 0;
			}
		}
    }

    //Otras Funciones
    
    void nuevoVertice(TipoDato dto)
    {
		vertices[numVertices] = dto;
		numVertices++;
    }

    int buscar(TipoDato v)
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
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

    void nuevaArista(TipoDato u, TipoDato v, double w)
    {
		int indiceU = buscar(u), indiceV = buscar(v);

		if (indiceU >= 0 && indiceV >= 0)
		{
			mtz[indiceU][indiceV] = w;
		}
		else
		{
			std::cout << "Error al agregar arista" << std::endl;
		}
    }

    void nuevaArista(TipoDato u, TipoDato v)
    {
		int indiceU = buscar(u), indiceV = buscar(v);

		if (indiceU >= 0 && indiceV >= 0)
		{
			mtz[indiceU][indiceV] = 1;
		}
		else
		{
			std::cout << "Error al agregar arista" << std::endl;
		}
    }

    void imprimeMtz()
    {
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << mtz[i][j] << " ";
			}
			std::cout << std::endl;
		}
    }
};
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

