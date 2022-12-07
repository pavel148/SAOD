#pragma once
using namespace std;
#include <iostream>

class Test
{
public:
	Test() {
		cout << "Constructor used" << endl;
	}

	~Test() {
		cout << "Destructor used" << endl;
	}
};

