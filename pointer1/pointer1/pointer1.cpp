#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	int a = 3, b = 5;
	cout << "a\t" << a << endl;
	cout << "b\t" << b << endl;
	cout << "Swap" << endl;

	Swap(&a, &b);
	cout << "a\t" << a << endl;
	cout << "b\t" << b << endl;

	//int x = 3;
	//int* p = &x;
	////cout << x << ' ' << *p << ' ' << p << endl;
	//p++; 
	////cout << p << endl;
	////cout << p - &x << endl;
	//typedef unsigned char byte; 	// Нет встроенного byte
	//byte* pb = (byte*)--p;		// вернули указатель на x и преобразовали
	//for (byte* pt = pb; pt - pb < sizeof(int); pt++)
	//	cout << (int)*pt << ' ';	// выводим как int
	//cout << endl;
}
