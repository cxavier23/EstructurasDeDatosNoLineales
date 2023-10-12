#pragma once
//author: Christopher Xavier Sanchez Duran
//UAMC
template <typename T, int m>
class Pagina
{
  public:
    int cont;            //Número de elementos en el nodo
    T claves[m];         //claves[0] no se utiliza
    Pagina * ramas[m];   //Apuntadores a nodo

    Pagina()
    {
        cont = 0;

        for (int i = 0; i < m; i++)
        {
            claves[i] = T();
            ramas[i] = nullptr;
        }
    }

    bool NodoLLeno()
    {
        return (cont == m - 1);
    }

    bool nodoSemiVacio()
    {
        return (cont < int(m / 2));
    }
};
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

