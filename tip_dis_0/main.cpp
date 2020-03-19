#include <iostream>
#include <string>


using namespace std;

#define Maxpor 324

int main()
{
	string s = "Титаренко";
	string t = "Алексей";
	string r = "Андреевич";
	cout << "name = " << t.length() << endl;
	cout << "fam = " << s.length() << endl;
	cout << "otch = " << r.length() << endl;
	int n = s.length()*t.length()*r.length();
	cout << " a*b*c = " << n << endl;
	long long x;
	long long k = 0;
	for (int i = 0; i < n; i++)
	{
		x = 1;
		for (int j = 0; j < Maxpor; j++)
		{
			x *= i;
			x %= n;
			if ((x == 0) && (j == Maxpor - 1)) k = i;
			if (x == 0) break;
		}
		if (k != 0) cout << " k = " << k << endl;
		k = 0;
	}


	long long l = 21;
	int h = 21;
	for (int i = 0; i < Maxpor; i++)
	{
		l *= h;
		l %= n;
	//	cout << " i = " << i;
	//	cout << " l%n = " << l << endl;
	}
	//cout << " l = " << l << endl;
	//cout << "l%n = " << l%n << endl;
	system("pause>NULL");
	return 0;
}