#pragma once
//author: Christopher Xavier Sanchez Duran
//UAMC
#include <iostream>
using namespace std;

template <typename TipoDato>
class ABB
{
private:
	class NodoBin
	{
	public:
		TipoDato dato;
		NodoBin *izq;
		NodoBin *der;

		NodoBin() : izq(nullptr), der(nullptr){};
		NodoBin(TipoDato elemento) : dato(elemento),izq(nullptr), der(nullptr){};
	};
	typedef NodoBin *PuntNodoBin;
	PuntNodoBin miRaiz;
	
	void insertarAux(const TipoDato &elemento, PuntNodoBin &subRaiz);
	void preordenAux(std::ostream &sal, PuntNodoBin subRaiz);
	bool buscarAux(const TipoDato &elemento, PuntNodoBin &subRaiz);
	void buscarparaEliminar(const TipoDato &elemento, bool &encontrado, PuntNodoBin &puntPost, PuntNodoBin &padre);

public:
	ABB() : miRaiz(nullptr){};
	void insertar(const TipoDato &elemento);
	void preorden(std::ostream &sal);
	bool buscar(const TipoDato &elemento);
	void eliminar(const TipoDato &elemento);
};

template <typename TipoDato>
void ABB<TipoDato>::buscarparaEliminar(const TipoDato &elemento, bool &encontrado, PuntNodoBin &puntPost, PuntNodoBin &padre)
{
	puntPost=miRaiz;
	padre=nullptr;
	encontrado=false;

	while(!encontrado && puntPost!=nullptr)
	{
		if(elemento < puntPost->dato)
		{
			padre=puntPost;
			puntPost=puntPost->izq;
		}
		else if(puntPost->dato < elemento)
		{
			padre=puntPost;
			puntPost=puntPost->der;
		}
		else
			encontrado=true;
	}
}

template <typename TipoDato>
void ABB<TipoDato>::eliminar(const TipoDato &elemento)
{
    bool encontrado;
	PuntNodoBin x, padre, sucx, subArbol;

	buscarparaEliminar(elemento, encontrado, x, padre);

	if(!encontrado)
	{
		cout<<""<<endl;
		return;
	}

	if(x->izq!=nullptr && x->der!=nullptr)//tiene dos hijos
	{
		sucx=x->der;
		padre=x;
		while(sucx->izq!=nullptr)
		{
			padre=sucx;
			sucx=sucx->izq;
		}
		x->dato=sucx->dato;
		x=sucx;
	}

	subArbol=x->izq;
	if(subArbol==nullptr)
	{
		subArbol=x->der;
	}

	if(padre==nullptr)
	{
		miRaiz=subArbol;
	}
	else if (padre->izq==x)
	{
		padre->izq=subArbol;
	}
	else 
	{
		padre->der=subArbol;
	}

	delete x;
}

template <typename TipoDato>
bool ABB<TipoDato>::buscarAux(const TipoDato &elemento, PuntNodoBin &subRaiz)
{
	if(subRaiz==nullptr)
		return false;
	else if(elemento < subRaiz->dato)
		return buscarAux(elemento, subRaiz->izq);
	else if(subRaiz->dato < elemento)
		return buscarAux(elemento, subRaiz->der);
	else
		return true;
}

template <typename TipoDato>
bool ABB<TipoDato>::buscar(const TipoDato &elemento)
{
	return buscarAux(elemento, miRaiz);
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

template <typename TipoDato>
void ABB<TipoDato>::preordenAux(std::ostream &sal, PuntNodoBin subRaiz)
{
	if(subRaiz!=nullptr)
	{
		sal << subRaiz->dato << " ";
		preordenAux(sal, subRaiz->izq);
		preordenAux(sal, subRaiz->der);
	}
}

template <typename TipoDato>
void ABB<TipoDato>::preorden(std::ostream &sal)
{
	preordenAux(sal, miRaiz);
}

template <typename TipoDato>
void ABB<TipoDato>::insertarAux(const TipoDato &elemento, PuntNodoBin &subRaiz)
{
	if(subRaiz == nullptr){
		subRaiz = new NodoBin(elemento);
	}else if(elemento < subRaiz->dato){
		insertarAux(elemento, subRaiz->izq);
	}else{
		insertarAux(elemento, subRaiz->der);
	}
}

template <typename TipoDato>
void ABB<TipoDato>::insertar(const TipoDato &elemento)
{
	insertarAux(elemento, miRaiz);
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

