#pragma once
#include <iostream>
#include "Test.h"
using namespace std;
class Aggregate
{
	Test m_objTest;
	//static int nCount;
public:
	Aggregate() {
		cout << "\t Constructor Aggregate has been called" << std::endl;
		//nCount += 1;
		//std::cout << "\t nCount= " << nCount << std::endl;
	};

	~Aggregate() {
		cout << "\t Delete anythig used by Aggregate class" << std::endl;
		//nCount -= 1;
		//std::cout << "\t nCount= " << nCount << std::endl;
	};
};

