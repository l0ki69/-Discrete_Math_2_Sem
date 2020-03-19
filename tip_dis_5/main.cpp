#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int fild[31][31];

void fild_clear(int m, int n) //заполнение поля
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fild[i][j] = 0;
		}
	}
	fild[m - 1][n - 1] = 3;
	fild[0][0] = 2;

}

void fld(int m,int n)
{
	for (int i = m; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			fild[i][j] = 1;
			fild[j][i] = 1;
		}
	}
}

void fild_out(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << fild[i][j] << " ";
		}
		cout << endl;
	}
}

bool isFree(int x, int y)
{
	if (fild[x][y] == 1) return 0;
	else return 1;
}

int k;

bool getPath(int x, int y,int n,int m) {

	cout << "x = " << x << " y = " << y << endl;

	if ((x == n-1) && (y == m-1)) {
		return true;                  // найти путь
	}

	bool success = false;

	if (( x < n ) && isFree(x+1, y)) {    // Пытаемся идти вправо
		success = getPath(x+1, y,n,m);  // Свободно! Можно идти вправо
	}
	if (!success && (y < m) && isFree(x, y + 1)) {   // Пытаемся идти вверх
		success = getPath(x, y+1,n,m);    // Свободно! Можно идти вверх
	}
	if (success) k++;
	if (!success) {
		//path.remove(p);  // Неверный путь! Прекратить движение этим маршрутом
		//k++;
	}
	return success;
}



int main()
{
	setlocale(LC_ALL, "Rus");

	string c[5]{ "1","2","3", "4", "5" };
	string in, out;
	int m, n, k,res,res1 = 0;
	for (int ii = 1; ii <= 1; ii++)
	{
		in = "C:\\Users\\l0ki\\Desktop\\count_paths\\test" + c[ii - 1];
		in = in + ".in";
		out = "C:\\Users\\l0ki\\Desktop\\count_paths\\test" + c[ii - 1];
		out = out + ".out";
		cout << "фаил # " << ii << endl;

		ifstream fin(in);
		ifstream fout(out);
		fin >> m;
		fin >> n;
		fin >> k;
		fout >> res;
		int x, y;

		fld(3, 3); // создаем стены
		fild_clear(n, m); //заполняем поле
	
		for (int i = 0; i < k; i++)
		{
			fin >> x;
			fin >> y;
			fild[x][y] = 1;
		}

		//getPath(0, 0, n, m);




		cout << "k = " << k << endl;

		fild_out(3, 3);

		cout << "получившийся ответ - " << res1 << endl;
		cout << "правильный ответ - " << res << endl;
	}


	system("pause>NULL");
	return 0;
}