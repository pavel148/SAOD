// BM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include "BadCharTbl.h"
#include "GoodSufTbl.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

using namespace std;
/// <summary>
/// Возвращает большее значение среди двух параметров
/// </summary>
/// <param name="left">первый параметр</param>
/// <param name="right">второй параметр</param>
/// <returns></returns>
int max(int left, int right) {
    if (left > right) return left;
    else return right;
}
int main()
{
    {
        bool success = false;
        BadCharTbl ctbl;
        GoodSufTbl stbl;
        srand(time(0)); //обеспечивает случайность чисел
        /*const int N = 32;
        char s[N]{ 0 };
        for (int i = 0; i < N - 1; i++)
            s[i] = rand() % ('z' - 'a' + 1) + 'a';
        stbl.Init(s);

        const int N1 = 128;
        char s1[N1]{ 0 };
        for (int i = 0; i < N1 - 1; i++)
            s1[i] = rand() % ('z' - 'a' + 1) + 'a';
        stbl.Init(s1);

        const int N2 = 512;
        char s2[N2]{ 0 };
        for (int i = 0; i < N2 - 1; i++)
            s2[i] = rand() % ('z' - 'a' + 1) + 'a';
        stbl.Init(s2);

        const int N3 = 2048;
        char s3[N3]{ 0 };
        for (int i = 0; i < N3 - 1; i++)
            s3[i] = rand() % ('z' - 'a' + 1) + 'a';
        stbl.Init(s3);*/
        
        //теперь оценим эффективность самого алгоритма BM.

        char t[8]{};// 19.	Заполняйте t случайным образом с алфавитом от 3 до 6 символов. Длину t выбирайте 6-10
        for (int i = 0; i < sizeof(t); i++)
        {
            t[i] = rand() % ('c' - 'a' + 1) + 'a';
        }
        ctbl.Init(t);
        stbl.Init(t);
        const int N = 1024*256;
        char T[N]{ 0 }; // 20.	Заполняйте T случайным образом с тем же алфавитом. Выбирайте длину от 1024 до 256*1024.
        for (int i = 0; i < N; i++)
        {
            T[i] = rand() % ('c' - 'a' + 1) + 'a';
        }

        int cp = 0;//current position

    Punkt1:
        while (cp < N || T[cp] == t[0])//Пока не закончился T или не дошли до начала образца t
        {
            int i = abs((int)sizeof(t)) - 2;//Цикл сравнений с конца шаблона, добавил еще -1
            while (i >= 0) 
            {
                if (T[cp + i] == t[i]) i--;
                else
                {
                    cp += max(stbl[abs((int)sizeof(t) - i - 1)], ctbl[T[cp + i]]);
                    goto Punkt1;
                }
            }
            if (i == -1)
            {
                cout << "Success" << endl;
                success = true;
                cout << "Iskomaya podstroka: " << cp << endl;
                break;
            }
            
        }
        if (!success) cout << "Ne naidena podstroka" << endl;
    }
    _CrtDumpMemoryLeaks();
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
