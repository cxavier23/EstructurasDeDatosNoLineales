#include <iostream>
#include <queue>
//author: Christopher Xavier Sanchez Duran
//UAMC
using namespace std;

int main(int argc, char const *argv[])
{
	priority_queue<int> cp1;

	cp1.push(10);
	cp1.push(2);
	cp1.push(16);
	cp1.push(5);
	cp1.push(20);

	cout << endl;

	cout << "Tam: " << cp1.size() << endl;
	cout << "Max prioridad: " <<  cp1.top() << endl;
	cout << "Eliminamos " << cp1.top() << " de cp1" << endl;
	cp1.pop();
	cout << "Max prioridad cp1: " <<  cp1.top() << endl;

	cout << endl;

	return 0;
}
// author: Christopher Xavier Sanchez Duran
// Github: https://github.com/cxavier23
// Portafolio: https://cxavier23.github.io/

