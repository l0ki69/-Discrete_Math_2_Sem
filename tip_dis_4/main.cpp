#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct gr
{
	vector <int> ver;
};

vector <gr> grf;

int k = 1;

void poisk(int x,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (grf[x].ver[i] == 1) 
		{

		//	for (int j = 0; j < n; j++)
			//{
			//  grf[j].ver[x] = 0;

			//	grf[x].ver[j] = 0;
		//	}
			  grf[i].ver[x] = 0;

			  grf[x].ver[i] = 0;


			poisk(i, n);
			k++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	string c[6]{ "1","2","3", "4", "5", "6"};
	string in, out;
	int m, n, v, res, res1 = 0;
	int x, y;
	for (int ii = 1; ii <= 2; ii++)
	{
		in = "C:\\Users\\l0ki\\Desktop\\component_size\\test" + c[ii - 1];
		in = in + ".in";
		out = "C:\\Users\\l0ki\\Desktop\\component_size\\test" + c[ii - 1];
		out = out + ".out";
		cout << "фаил # " << ii << endl;

		ifstream fin(in);
		ifstream fout(out);


		fin >> n;
		fin >> m;
		fin >> v;
		fout >> res;

		
		gr a;

		for (int i = 0; i < n; i++) a.ver.push_back(0);
		for (int i = 0; i < n; i++)	grf.push_back(a);

		for (int i = 0; i < m; i++)
		{
			fin >> x;
			fin >> y;

			grf[y].ver[x] = 1;

			grf[x].ver[y] = 1;


		}
	/*	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << grf[i].ver[j] << " ";
			}
			cout << endl;
		} */

		poisk(v, n);



		cout << "получившийся ответ - " << k << endl;
		cout << "правильный ответ - " << res << endl;
		grf.clear();
		a.ver.clear();
		k = 1;
	}

	system("pause>NULL");
	return 0;
}