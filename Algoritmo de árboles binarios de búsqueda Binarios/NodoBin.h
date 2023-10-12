#include <iostream>
//author: Christopher Xavier Sanchez Duran
//UAMC

template <typename T>
class NodoBin
{
	private:
		T x;
		NodoBin * izq;
		NodoBin * der;
		
	public:
		NodoBin() : izq(0), der(0) {}
		NodoBin(T elem) : x(elem), izq(0), der(0) {}
		
		void setIzq(NodoBin<T> * izquierdo);
		void setDer(NodoBin<T> * derecho);
		void setElem(T elem);
		
		NodoBin<T> * getIzq() const;
		NodoBin<T> * getDer() const;
		T getElem() const;
};



template <typename T>
void NodoBin<T>::setIzq(NodoBin<T> * izquierdo)
{
	this->izq = izquierdo;
}

template <typename T>
void NodoBin<T>::setDer(NodoBin<T> * derecho)
{
	this->der = derecho;
}

template <typename T>
void NodoBin<T>::setElem(T elem)
{
	this->x = elem;	
}



template <typename T>
NodoBin<T> * NodoBin<T>::getIzq() const
{
	return this->izq;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/
template <typename T>
NodoBin<T> * NodoBin<T>::getDer() const
{
	return this->der;
}

template <typename T>
T NodoBin<T>::getElem() const
{
	return this->x;
}


// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/



