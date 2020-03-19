#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

vector <long> simpl;
vector <int> simple;

long pow(long a,int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		a *= a;
	}
	return a;
}

bool smp(string str)
{
	if (str[0] == '1')
	{
		if ((str[1] == '1') || (str[1] == '3') || (str[1] == '7') || (str[1] == '9')) return 1;
		else return 0;
	} else
	if (str[0] == '2')
	{
		if ((str[1] == '3') || (str[1] == '9')) return 1;
		else return 0;
	} else 
	if (str[0] == '3')
	{
		if ((str[1] == '1') || (str[1] == '7')) return 1;
		else return 0;
	}
	else
	if (str[0] == '4')
	{
		if ((str[1] == '1') || (str[1] == '3') || (str[1] == '7')) return 1;
		else return 0;
	}
	else
	if (str[0] == '5')
	{
		if ((str[1] == '3') || (str[1] == '9')) return 1;
		else  return 0;
	}
	else
	if (str[0] == '6')
	{
		if ((str[1] == '1') || (str[1] == '7')) return 1;
		else return 0;
	}
	else
	if (str[0] == '7')
	{
		if ((str[1] == '1') || (str[1] == '3') || (str[1] == '9')) return 1;
		else return 0;
	}
	else
    if (str[0] == '8')
	{
		if ((str[1] == '3') || (str[1] == '9')) return 1;
		else return 0;
	}
	else
	if (str[0] == '9')
	{
		if (str[1] == '7') return 1;
		else return 0;
	}
}

bool check(long x)
{
	string str = to_string(x);
	string st;
	bool q = true;
	for (int i = 0; i < str.length() - 1; i++)
	{
		st = str[i];
		st +=str[i + 1];
		if (!smp(st)) q = false;
		if (!q) break;
	}
	return q;
}



int main()
{
	int n = 0;
	cout << "vvedite n = ";
	cin >> n;
	long max = pow(10, n);
	long min = pow(10, n - 1);
	long k = 0;
	for (int i = min; i < max; i++)
	{
		if (i % 100000 == 0) cout << i << endl;
		if (i % 10 == 0) continue;
		if (i % 2 == 0) continue;
		if ((i % max / 10 == 2) || (i % max / 10 == 4) || (i % max / 10 == 5) || (i % max / 10 == 6) || (i % max / 10 == 8)) continue;
		if (check(i))
		{
			k++;
		}
	}
	cout << "kol-vo n-znach = " << k << endl;

	system("pause>NULL");
	return 0;
}