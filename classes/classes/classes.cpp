﻿// classes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include "Complex.h";
using namespace std;
int main()
{
	const int  n = 4;
	int m;
	//setlocale(LC_ALL, "Russian");
	Complex v[4]{ Complex(20,10),2, Complex(2,3),6 };
	for (int i = 0; i < 4; i++) {
		cout << v[i] << "!";
	}

	Complex* pc= &v[0];
	Complex *cmplx = new Complex(40,500);
	cout << *cmplx << "=)" << endl;
	cout << *pc<<endl;
	cout << pc->Im<<"imaginary"<<endl;
	cout << pc->Re << "valid" << endl;
	cout << endl;
	Complex a( 4,10), b(30,20);

	Complex* mstr = new Complex[4]{20,Complex(1914,1917),1923,1961};
	cout << mstr[2].Im << endl;
	cout << pc[1].Re <<" done"<< endl;
	cout <<a.Mod(b) << endl;
	cout << a + b << endl;
	cout << a.Conjugate(b) << endl;
	cin >> m;
	delete cmplx;
	delete[]mstr;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
