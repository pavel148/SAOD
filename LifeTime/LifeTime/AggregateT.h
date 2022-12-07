#pragma once
#include <iostream>
using namespace std;
template <class T>
class AggregateT
{
	T obj;
public:
	AggregateT() {
		cout << "\t Constructor AggregateT has been called" << std::endl;
		//nCount += 1;
		//std::cout << "\t nCount= " << nCount << std::endl;
	};

	~AggregateT() {
		cout << "\t Delete anythig used by AggregateT class" << std::endl;
		//nCount -= 1;
		//std::cout << "\t nCount= " << nCount << std::endl;
	};
};

