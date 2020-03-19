#include <iostream>
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<cstring>
#include <Windows.h>
#include<math.h>
#include <fstream>

using namespace std;

int arr[30][30]; //матрица 30 на 30 во избежание ошибок и выхода за пределы поля

int Leter_to_Number(char L)// координата из буквы
{
	int N;
	N = (int)L;
	N -= 97;
	return(N);

}

void Bild_graf(int BL, int BN, int FL, int FN)// построение графа
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (i == BL && j == BN)
			{
				arr[i][j] = -1;
				arr[i + 2][j + 1] = 1;
				arr[i + 2][j - 1] = 1;
				arr[i - 2][j + 1] = 1;
				arr[i - 2][j - 1] = 1;
				arr[i + 1][j + 2] = 1;
				arr[i + 1][j - 2] = 1;
				arr[i - 1][j + 2] = 1;
				arr[i - 1][j - 2] = 1;
			}

		}
	}

	/*for (int i = 0; i < 26; i++)
	{
	for (int j = 0; j < 26; j++)
	{
	printf("%d ", arr[i][j]);
	printf("\t");
	}

	printf("\n");
	}
	printf("\n\n");
	*///Печать графа на старте

	for (int f = 0; f<500; f++)//500 пробегов оно нормально по времени, это для подстраховки
	{
		for (int i = 2; i < 28; i++)
		{
			for (int j = 2; j < 28; j++)
			{
				if ((arr[i][j] != 0) && (arr[i][j] != -1))// ходим не из старта(-1) и не из 0-х вершин
				{
					if ((arr[i + 2][j + 1] > arr[i][j]) || (arr[i + 2][j + 1] == 0))//изменяем значение точки прибытия
					{
						arr[i + 2][j + 1] = arr[i][j] + 1;// только если мы уменьшим путь или мы там еще не были
					}
					if ((arr[i + 2][j - 1] > arr[i][j]) || (arr[i + 2][j - 1] == 0))
					{
						arr[i + 2][j - 1] = arr[i][j] + 1;
					}
					if ((arr[i - 2][j + 1] > arr[i][j]) || (arr[i - 2][j + 1] == 0))
					{
						arr[i - 2][j + 1] = arr[i][j] + 1;
					}
					if ((arr[i - 2][j - 1] > arr[i][j]) || (arr[i - 2][j - 1] == 0))
					{
						arr[i - 2][j - 1] = arr[i][j] + 1;
					}
					if ((arr[i + 1][j + 2] > arr[i][j]) || (arr[i + 1][j + 2] == 0))
					{
						arr[i + 1][j + 2] = arr[i][j] + 1;
					}
					if ((arr[i + 1][j - 2] > arr[i][j]) || (arr[i + 1][j - 2] == 0))
					{
						arr[i + 1][j - 2] = arr[i][j] + 1;
					}
					if ((arr[i - 1][j + 2] > arr[i][j]) || (arr[i - 1][j + 2] == 0))
					{
						arr[i - 1][j + 2] = arr[i][j] + 1;
					}
					if ((arr[i - 1][j - 2] > arr[i][j]) || (arr[i - 1][j - 2] == 0))
					{
						arr[i - 1][j - 2] = arr[i][j] + 1;
					}
				}
			}
		}

		/*for (int i = 2; i < 28; i++)
		{
		for (int j = 2; j < 28; j++)
		{
		printf("%d ", arr[i][j]);
		printf("\t");
		}

		printf("\n");
		}
		printf("\n\n");*///Печать каждого нового графа но это долго
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int coord_base, base_number, LSTN, LRTN, res_number; char base_Leter, res_leter;

	string c[5]{"1","2","3", "4", "5"};
	string in, out;
	int res;
	for (int i = 1; i <= 5; i++)
	{
		in = "C:\\Users\\l0ki\\Desktop\\horse\\test" + c[i-1];
		in = in + ".in";
		out = "C:\\Users\\l0ki\\Desktop\\horse\\test" + c[i-1];
		out = out + ".out";
		cout << "фаил # " << i << endl;

		ifstream fin(in);
		ifstream fout(out);

		fin >> base_Leter;
		fin >> base_number;
		fin >> res_leter;
		fin >> res_number;;
		fout >> res;

		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				arr[i][j] = 0;
			}
		}
		base_number++;
		res_number++;

		LSTN = Leter_to_Number(base_Leter);
		LRTN = Leter_to_Number(res_leter);
		Bild_graf(LSTN, base_number, LRTN, res_number);

		cout << "получившийся ответ:" << endl;
		cout << arr[LRTN][res_number] << endl;
		cout << "правильный ответ:" << endl;
		cout << res << endl;
		system("pause>NULL");
	}
	return(0);
}