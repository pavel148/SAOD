#pragma once
#include <iostream>
using namespace std;
class BadCharTbl
{
	int badChar[256];
	//8,10,11 ������� ������� 
	// sizeof(badChar)- ���� ������ ��������������� �����, � ���� �������, �� ������, ������ ��� �������� ����� ������� ��������
public:
	void Init(const char* s)
	{
		int len = strlen(s);//����� ������
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
	{//char �� ����� ���� ������ 127, ������� Unsigned ������ char � "�� -127 �� 127" � "�� 0 �� 256"
		return (int)badChar[c];
	}
};

