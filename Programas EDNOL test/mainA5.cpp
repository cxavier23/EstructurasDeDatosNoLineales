//(i)Encontrar dos números que multiplicados den 2020
//(ii)Encontrar tres números que multiplicados den 2020
#include <iostream>
#include <fstream>
#include <list>
 //author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

int main(int argc, char const *argv[])
{
  string s;
  ifstream f( argv[1] );
  list<int> l;

  while ( getline(f, s) )
    l.push_back( stoi(s) );

  f.close();
  
  for(int num: l)
    cout<< num <<endl;

  list<int> ll(l);
  list<int> lll(l);

  int count;
  ll.sort();
  lll.sort();

  for(int aux: ll){
    for(int mow: lll){
      if((aux+mow)==2020){
        cout<< "la suma de "<<aux<<" + "<<mow<<" es igual a 2020";
        count++;
      }
    }
    lll.pop_front();
    
  }

    

  if(count==0){
    cout<<"no hay dos números en esta lísta que sumados den 2020 ";
  }

  //nombreLista.sort() para ordenar
  //nombreLista.reverse() para invertir

  //TODO
  //(i)Encontrar dos números que multiplicados den 2020
  //(ii)Encontrar tres números que multiplicados den 2020
  
  //compilación:    g++ mainA5.cpp
  //ejecución:    ./a.out input.txt
  


  return 0;
} 
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

