#pragma once
#include <iostream>
using namespace std;
#include "Test.h"
class Child : public Test
{
public:
	//static int nCount;
	Child() {
		cout << "\t Constructor Child has been called" << std::endl;
		//nCount += 1;
		//std::cout << "\t nCount= " << nCount << std::endl;
	};

	~Child() {
		cout << "\t Delete anythig used by Child class" << std::endl;
		//nCount -= 1;
		//std::cout << "\t nCount= " << nCount << std::endl;
	};
};

