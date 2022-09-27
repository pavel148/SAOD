// strings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "utils.h"
using namespace std;
void string_copy(char* d, char* s);
int compare_(const char* s, const char* t);

int main()
{
	char str[] = "Hello!";
	char s1[20];
	cout << str << endl;
	cout << "//////" << endl;
	cout << strlen(str) << ' ' << sizeof(str) << endl;
	cout << "//////" << endl;
	string_copy(str, s1);
	cout << "/////" << endl;
	cout << str[3] << endl;
	cout << "length: " << len_("hello0000") << endl;
	cout << compare_("Hi", "hello") << endl;
}


