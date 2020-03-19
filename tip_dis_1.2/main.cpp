#include <iostream>
#include <cmath>

using namespace std;

long long binpow(long long x,long long n,long long p) {
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

int main(){
	long long  p = 69031;
	long long  x = 50013;
	long long  a = 3898;
	long long  b = 2891;
	long long c = 71309;
	long long d = 110;
	//5 3 2 3 1 8                            1
	//23 17 8 22 50 1                        14
	//69031 50013 3898 2891 71309 110        23938
	cout << ((a*binpow(x, d, p) + b*binpow(x, c, p) + c*binpow(x, b, p) + d) % p) << endl;
	cout << binpow(2, 5, 100) << endl;
	system("pause");
	return 0;
}