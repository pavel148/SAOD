#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <cstring>
class Str {
	char* m_pszText;
public:
	Str() 	//Конструктор “по умолчанию” (default)*
	{
		m_pszText = new char[1]{ 0 };
	}
	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy(m_pszText, p);
		}
		else
			m_pszText = new char[1]{ 0 };
	}


	Str(const Str& s) //Константная ссылка на объект
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy(m_pszText,
			
			s.m_pszText);
	}

	const Str& operator = (const Str& s) //Константная ссылка на объект
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 //Освобождаем текущие данные					//Дальше просто копирование
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy(m_pszText,s.m_pszText);
		return *this;
	}

	~Str() { delete[]m_pszText; }

	operator const char* ()const { return m_pszText; }

	Str& operator +=(const char* sz) {
		//delete[] m_pszText;
		if (strlen(sz) == 0) return *this;
		int n = strlen(this->m_pszText) + 1 + strlen(sz);
		char* temp = new char[n];
		strcpy(temp, this->m_pszText);
		delete [] this->m_pszText;
		strcat(temp, sz);
		
		m_pszText = temp;
		m_pszText[n - 1] = 0;
		return *this;
	}
	Str operator +(const char* sz) const {

		Str ts = *this;
		return ts += sz;
		return ts;
	}
	
};
