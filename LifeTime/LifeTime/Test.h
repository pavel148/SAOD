#pragma once
#include <iostream>
using namespace std;
class Test
{
	Test* m_pszobj;
public:
	static int nCount;
	Test() {
		std::cout << "\t Constructor Test has been called" << std::endl;
		nCount += 1;
		std::cout <<"\t nCount= "<< nCount << std::endl;
	};

	Test(const Test & object)
	{
		std::cout << "\t Copy Test Constructor has been called" << std::endl;
		std::cout << "\t nCount= " << nCount << std::endl;
		nCount += 1;
	}



	~Test() {
		std::cout << "\t Delete anythig used by Test class" << std::endl;
		nCount -= 1;
		std::cout << "\t nCount= " << nCount << std::endl;
	};

	void foo(Test t)
	{
		cout << "foo is running";
	}

};

