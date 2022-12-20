// SAOD_Dop_LinkList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//проверим утечки

//#define __CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW


#include <iostream>
#include <numeric>
#include "MyLinkedList.h"
#include "LinkedListNode.h"
#include "ListIterator.h"
using namespace std;
int main()
{
    MyLinkedList<char> lst;
    cout << boolalpha << lst.empty() << endl;

    for (int i = 0; i < 5; i++) {
        lst.push_back(char('a' + i));
    }

    lst.PrintList();

    for (int i = 0; i < 5; i++) {
        lst.insert(0,char('z' - i));
    }
    lst.PrintList();

    for (size_t i = 0; i != lst.size(); i++) {
        lst[i]= (char('a' + i));
    }
    lst.PrintList();

    lst.pop_back();
    lst.pop_front();

    lst.PrintList();

    lst.remove_at(5);
    lst.insert(3, '0');

    lst.PrintList();

    lst.clear();

    lst.push_back('q');
    lst.push_back('w');



    cout << lst.size() << ' ' << boolalpha << lst.empty() << endl;

    //реализация итератора тест
    cout << "Iterator test" << endl;

    for (const auto obj : lst) {
        cout << obj << "\n";
    }
    cout << endl;
    MyLinkedList <int > l;
    l.push_back(3);
    l.push_back(5);
    l.push_back(2);
    l.push_back(7);
    for (auto& i : l) i += 2;
    auto lambda = [&l](int a, int b) { return a + b * 10; };
    cout << accumulate(l.begin(), l.end(), 0, lambda) << "\n";// 250

    //list.push_front('b');
    //list.push_back('c');
    //list.push_front('d');
    //list.insert(2, 'a');
    //list[1] = 'r';
    //list.pop_front();
    //list.remove_at(2);
    //list.clear();
    //cout << list[1];
    //list.PrintList();
    //std::cout << "Hello World!\n";
    //_CrtDumpMemoryLeaks();
    return 0;
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
