#include <iostream>
#include "FunctionsOverloading.h"

//for namespaces
using namespace std;

//new types
using BigInt = long long;
typedef long long BigInt2;

//function pointers
using MapFunc = int(*)(int);
typedef int(*intMap)(int);

//template function pointers
template <typename T>
using TempMapFunc = T(*)(const T&);

//not possible
//template <typename T>
//typedef T(*func)(T);

int MultiplyBy2(int num)
{
	return num * 2;
}

int main()
{
	//MapFunc f1 = MultiplyBy2;//[](int num) { return num * 2; };
	//TempMapFunc<double> f2 = [](const double &num) {return num * 2; };

	//cout << f2(2) << endl;

	Person p;
	p.SaySomething(10);

	Worker w;
	w.SaySomething("asdads");
	w.SaySomething(10);
	w.SaySomething({ 10, 15 });
    return 0;
}

