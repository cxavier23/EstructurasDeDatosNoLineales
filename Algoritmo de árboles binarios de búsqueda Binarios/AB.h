#include <iostream>
#include "NodoBin.h"
 //author: Christopher Xavier Sanchez Duran
//UAMC

using namespace std;

template <typename T>
class AB
{
	private:
		typedef NodoBin<T> * ptrNodo;
		ptrNodo raiz; 
		void insertarRec(const T & x, ptrNodo cursor, ptrNodo padre);
		
		void preordenRec(ostream & arb, ptrNodo subraiz) const;
		void inordenRec(ostream & arb, ptrNodo subraiz) const;
		void posordenRec(ostream & arb, ptrNodo subraiz) const;
	
	public:
		AB();
		void insertar(const T & x);
		
		void preorden(ostream & arb) const;
		void inorden(ostream & arb) const;
		void posorden(ostream & arb) const;
};



template <typename T>
inline AB<T>::AB() : raiz(0) {}



template <typename T>
inline void AB<T>::insertar(const T & elem)
{
	insertarRec(elem, raiz, nullptr);
}

template <typename T>
inline void AB<T>::insertarRec(const T & elem, ptrNodo cursor, ptrNodo padre)
{
		if(cursor == nullptr)
		{
			cursor = new NodoBin<T>(elem);
			
			if(padre == nullptr)
			{
				raiz = cursor;
			}
			else if(elem < padre->getElem())
			{
				padre->setIzq(cursor);
			}
			else if(elem > padre->getElem())
			{
				padre->setDer(cursor);
			}
			
		}
		else if(elem == cursor->getElem())
		{
			return;
		}
		else if(elem < cursor->getElem() && cursor != nullptr)
		{
			insertarRec(elem, cursor->getIzq(), cursor);
		}
		else if(elem > cursor->getElem() && cursor != nullptr)
		{
			insertarRec(elem, cursor->getDer(), cursor);
		}
}



template <typename T>
inline void AB<T>::preorden(ostream & arb) const
{
	arb << "< ";
	preordenRec(arb, raiz);
	arb << ">";
}

template <typename T>
inline void AB<T>::preordenRec(ostream & arb, ptrNodo subraiz) const
{
	if(subraiz != nullptr)
	{
		arb << subraiz->getElem() << " ";
		preordenRec(arb, subraiz->getIzq());
		preordenRec(arb, subraiz->getDer());
	}
}



template <typename T>
inline void AB<T>::inorden(ostream & arb) const
{
	arb << "< ";
	inordenRec(arb, raiz);
	arb << ">";
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/
template <typename T>
inline void AB<T>::inordenRec(ostream & arb, ptrNodo subraiz) const
{
	if(subraiz != nullptr)
	{
		inordenRec(arb, subraiz->getIzq());
		arb << subraiz->getElem() << " ";
		inordenRec(arb, subraiz->getDer());
	}
}



template <typename T>
inline void AB<T>::posorden(ostream & arb) const
{
	arb << "< ";
	posordenRec(arb, raiz);
	arb << ">";
}

template <typename T>
inline void AB<T>::posordenRec(ostream & arb, ptrNodo subraiz) const
{
	if(subraiz != nullptr)
	{
		posordenRec(arb, subraiz->getIzq());
		posordenRec(arb, subraiz->getDer());
		arb << subraiz->getElem() << " ";
	}
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/
