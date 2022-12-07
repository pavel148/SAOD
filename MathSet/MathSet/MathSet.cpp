// MathSet.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
#include <unordered_set> 
using namespace std;

typedef set<int> SETINT;
typedef unordered_set<int> UNSETINT;

void ConsoleOutput(const SETINT& s) {
    cout << "<setint> ";
    for (auto i : s) cout << i << " ";
    cout << endl;
}

void ConsoleOutput(const UNSETINT& s) {
    cout << "<unsetint> ";
    for (auto i : s) cout << i << " ";
    cout << endl;
}

//почему после этого сетинта нет & // параметры можно и по ссылке и по значению, что выбрать?
//без ссылки будет огромная копия, по ссылке - только адрес

SETINT operator | (const SETINT& s1, const SETINT& s2) {
    SETINT s(s1);
    s.insert(s2.begin(), s2.end());
    return s;
}

SETINT operator & (const SETINT& s1, const SETINT& s2) {
    SETINT s;
    set <int> ::iterator sptr = s1.begin();
    for (int i = 0; i < s1.size(); i++) {
        if (s2.find(*sptr) != s2.end()) s.insert(*sptr);
        sptr++;
    }
    return s;
}

UNSETINT operator | (const UNSETINT& s1, const UNSETINT& s2) {
    UNSETINT s(s1);
    s.insert(s2.begin(), s2.end());
    return s;
}

const UNSETINT operator & (const UNSETINT& s1, const UNSETINT& s2) {
    UNSETINT s;
    unordered_set <int> ::iterator sptr = s1.begin();
    for (int i = 0; i < s1.size(); i++) {
        if (s2.find(*sptr) != s2.end()) s.insert(*sptr);
        sptr++;
    }
    return s;
}

int main()
{
    SETINT a;
    cout << "set a: ";
    for (int i = 0; i < 20; i++) {
        a.insert(rand()%100);
    }
    ConsoleOutput(a);

    SETINT b;
    cout << "set b: ";
    for (int i = 0; i < 20; i++) {
        b.insert(rand()%100);
    }
    ConsoleOutput(b);

    SETINT ab = a | b;
    cout << "UNION a AND b: ";
    ConsoleOutput(ab);

    /*SETINT abCopy = ab;
    cout << "COPY OF UNION a AND b: ";
    ConsoleOutput(abCopy);

    SETINT abReverse = b | a;
    cout << "REVERSED UNION b AND b: ";
    ConsoleOutput(abReverse);*/

    SETINT abCrossing = a & b;
    cout << "CROSSING a AND b: ";
    ConsoleOutput(abCrossing);
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
