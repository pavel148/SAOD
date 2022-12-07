#pragma once
#include <iostream>
using namespace std;
class BadCharTbl
{
	int badChar[256];
	//8,10,11 задания сложные 
	// sizeof(badChar)- если массив инициализирован здесь, а если передан, то нельзя, потому что передает адрес первого элемента
public:
	void Init(const char* s)
	{
		int len = strlen(s);//длина строки
		for (int i = 0;i < sizeof(badChar) / sizeof(badChar[0]);i++)
		{
			badChar[i] = -1;
		}

		for (int i = 0;i < len-1;i++)
		{
			badChar[(int)(s[i])] = i;
		}
	};
	int operator[] (unsigned char c) const
	{//char не может быть больше 127, поэтому Unsigned делает char с "от -127 до 127" в "от 0 до 256"
		return (int)badChar[c];
	}
};

