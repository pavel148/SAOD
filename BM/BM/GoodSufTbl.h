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
	/// �������� � z-�������
	/// </summary>
	/// <param name="s">������, �� ������� ������</param>
	/// <param name="n">����� ������</param>
	/// <param name="z">���� ���������</param>
	void zInv(const char* s, int n, int z[]) {
		for (int* p = z; p - z < n; *p++ = 0)
		{
			counter++;
		}; // ��������� �������� z - 0
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
	/// ������ ������� ��������� �� ������ z-������� ��������������� ������ (zinv). |t|==n
	/// </summary>
	/// <param name="zinv">z-������� ��������������� ������-�������</param>
	/// <param name="n">����� �������</param>
	/// <param name="ss">������ ����� n+1 ��� ���������� ������� ��������� ��� ������-������� s.</param>
	void suffShift(int zinv[], int n, int ss[]) {
		for (int i = 0; i <= n; ss[i++] = n)
		{
			counter++;
		}; // ������� ������������ �����.
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
		delete pss; //���������� ������ ������ ��� ������������� �������������
		N = (int)strlen(init) + 1;	//a.	��������� ������ ������� ��������� (�a 1 ������ ����� ������) � ��������� �������� ���� N.
		int *z = new int[N]; //b.	�������� ����� ��� ��������������� z-������� � ������ �����, �� ����� ������ ����� ������.
		zInv(init, N-1, z); //c.	��������� ���, ������ zInv � ���������������� �����������
		pss = new int[N]; //d.	�������� ������ ��� ������� ��������� � ��������� ��������� � ���� pss
		suffShift(z, N-1, pss); //e.	��������� ������� ���������, ������ ����� suffShift
		
		
		
		//��������������
		int j0 = sizeof(pss);
		for (int i = 0, j = j0; i < j;i++, j--) {
			char c = pss[i];
			pss[i] = pss[j];
			pss[j] = c;
		}
		cout << "CmpCount: " << CmpCount() << endl;
		delete[] z;	//f.���������� ������, ���������� ��� z - �������.
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

