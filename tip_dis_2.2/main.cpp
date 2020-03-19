#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;
 
vector <long long> ax;
vector <long long> ay;

long long abc(long long x, long long p) {
		if ((x <= 0) && (x >= ((-1)*p))) {
			x += p;
		}
		else
			if ((x < 0) && (x < ((-1)*p))) {
				x %= p;
				x += p;
			}
		x %= p;
		return x;
}

long long rev(long long a, long long p) {
	a %= p;
	for (int i = 1; i < p; i++) {
		if ((a*i) % p == 1) { 
		return i; 
		}
	}
	return 0;
}

long long binpow(long long x, long long n, long long p) {
	long long res = 1;
	while (n) {
		if (n & 1) {
			res *= x;
			res %= p;
			n--;
		}
		else {
			x *= x;
			x %= p;
			n >>= 1;
		}
	}
	return res;
}

long long gcd(long long  a, long long  b, long long& x, long long& y) { //вычисление обратного через алгоритм евклида evklid
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long  x1, y1;
	long long  d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}


long long rev2(long long a, long long p) {
	long long x1, y1;
	int g = gcd(a, p, x1, y1);
	if (g != 1)
		cout << "no solution";
	else {
		x1 = (x1 % p + p) % p;

		return x1;
	}
}

long long rev1(long long a, long long p) {
	return binpow(a, p - 2, p);
}

long long top(int i, long long  tp, long long p,long long x) {
	tp = tp * rev1(abc(x - ax[i],p), p);
	tp %= p;
	return tp;
}

int main() {
	setlocale(LC_ALL, "Rus");
	long long s = 0;
	long long p,x;
	int n;
	long long a = 0, b = 0;
	long long s1;
	string c[9]{"0","1","2","3", "4", "5", "6", "7","8"};
	string in, out;
	long long tp = 1;

	long long temp, temp1;

	for (int ii = 0; ii < 9; ii++) {
		unsigned int start_time2 = clock();
		in = "C:\\Users\\l0ki\\Desktop\\lagrange_test\\test" + c[ii];
		in = in + ".in";
		out = "C:\\Users\\l0ki\\Desktop\\lagrange_test\\test" + c[ii];
		out = out + ".out";
		cout << "фаил № " << ii << endl;

		ifstream fin(in);
		ifstream fout(out);
		fout >> s1;
		fin >> p;
		fin >> x;
		fin >> n;

		//cout << "p = " << p << endl << "x = " << x << endl << "n = " << n << endl;

		for (int i = 0; i < n; i++) {
			fin >> a;
			fin >> b;
			//cout << "x = " << a;
			//cout << "    y = " << b << endl;
			ax.push_back(a);
			ay.push_back((b));
		}

		tp = 1;

		for (int i = 0; i < ax.size(); i++) {
			tp *= abc((x - ax[i]), p);
			if (tp > p) tp %= p;
		}
		if (tp < 0) tp = abc(tp,p);

		for (int i = 0; i < ax.size(); i++) {
			if ((ay[i] != 0) && (ay[i] != p)) {
				temp1 = 1;
				for (int j = 0; j < ax.size(); j++) {
					if (i != j) {
						temp1 *= abc((ax[i] - ax[j]),p);
						if (temp1 > p ) temp1 %= p;
					}
				}
				if (temp1 < 0) temp1 = abc(temp1, p);

				temp = abc(top(i,tp, p,x),p);
				temp *= rev1(temp1, p);
				temp %= p;
				temp *= ay[i];
				temp %= p;
				s += temp;
				s %= p;
				//system("pause");
			//	if ((i % 1000 == 0) && (ii >= 4)) {
				//	cout << "s  = " << s << "  i = " << i << endl;
				//}
			}
		}
		s %= p;
		cout << endl;
		cout << "правильный ответ - " << s1 << endl;
		cout << "получившийся ответ " << s << endl;
		//system("pause");

		s = 0;
		temp = 0;
		temp1 = 0;

		ax.clear();
		ay.clear();
		fin.close();
		fout.close();

		cout << endl;
		unsigned int end_time2 = clock();
		cout << "время работы - " << (double)(end_time2 - start_time2)/1000 << "  секунд" << endl;
	} 
	system("pause>NUll");
}
