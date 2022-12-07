#pragma once
class GoodSufTbl
{
	int* pss;
	int N;
	int counter;
public:
	GoodSufTbl()
	{
		pss = nullptr;
	}
	/// <summary>
	/// Поместит в z-функцию
	/// </summary>
	/// <param name="s">Строка, по которой строим</param>
	/// <param name="n">Длина строки</param>
	/// <param name="z">Куда поместить</param>
	void zInv(const char* s, int n, int z[]) {
		for (int* p = z; p - z < n; *p++ = 0)
		{
			counter++;
		}; // Начальное значение z - 0
		for (int j = 1, left = 0, right = 0; j < n; ++j) {
			counter++;
			if (j <= right)
			{
				z[j] = min(right - j + 1, z[j - left]);
				counter++;
			}
			while (j + z[j] < n && s[n - 1 - z[j]] == s[n - 1 - (j + z[j])])
			{
				z[j]++;
				counter++;
			}
			if (j + z[j] - 1 > right) {
				left = j;
				right = j + z[j] - 1;
				counter++;
			}
		}
	}
	/// <summary>
	/// Строит таблицу суффиксов на основе z-функции инвертированной строки (zinv). |t|==n
	/// </summary>
	/// <param name="zinv">z-функция инвертированной строки-шаблона</param>
	/// <param name="n">длина шаблона</param>
	/// <param name="ss">массив длины n+1 для размещения таблицы суффиксов для строки-шаблона s.</param>
	void suffShift(int zinv[], int n, int ss[]) {
		for (int i = 0; i <= n; ss[i++] = n)
		{
			counter++;
		}; // Сначала максимальный сдвиг.
		for (int j = n - 1; j > 0; j--)
		{
			ss[n - zinv[j]] = j;
			counter++;
		}
		for (int j = 1, r = 0; j < n; j++)
		{
			counter++;
			if (j + zinv[j] == n)
			{
				counter++;
				for (; r <= j; r++)
				{
					counter++;
					if (ss[r] == n) 
					{
						ss[r] = j;
						counter++;
					}
				}
			}
		}
	}
	
	void Init(const char* init) {
		delete pss; //устранение утечки памяти при множественной инициализации
		N = (int)strlen(init) + 1;	//a.	Вычислять размер таблицы суффиксов (нa 1 больше длины строки) и заполнить значение поля N.
		int *z = new int[N]; //b.	Выделить место под вспомогательную z-функцию – массив целых, по длине равный длине строки.
		zInv(init, N-1, z); //c.	Заполнить его, вызвав zInv с соответствующими параметрами
		pss = new int[N]; //d.	Выделить память под таблицу суффиксов и запомнить указатель в поле pss
		suffShift(z, N-1, pss); //e.	Заполнить таблицу суффиксов, вызвав метод suffShift
		
		
		
		//инвертирование
		int j0 = sizeof(pss);
		for (int i = 0, j = j0; i < j;i++, j--) {
			char c = pss[i];
			pss[i] = pss[j];
			pss[j] = c;
		}
		cout << "CmpCount: " << CmpCount() << endl;
		delete[] z;	//f.Освободить память, выделенную под z - функцию.
	}

	int CmpCount() {
		return counter;
	}

	int operator [] (int i) const
	{
		return pss[i];
	}

	(operator int() const)
	{
		return N;
	}

	~GoodSufTbl()
	{
		delete [] pss;
	}
};

