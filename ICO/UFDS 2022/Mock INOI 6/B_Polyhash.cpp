#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int modPow(int a, int b, int m) {
	int res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

int modInv(int a, int m) {
	return modPow(a, m - 2, m);
}

bool checkModInv(int b, int m) {
	return __gcd(b, m) != -1;
}

int polyhash(string& s, int p, int m) {
	long long res = 0;
	long long place = 1;
	for (int i=0; i<s.size(); i++) {
		res += ((s[i] - 'a' + 1) * place) % m;
		res %= m;
		place *= p;
		place %= m;
	}
	return res;
}

int32_t main() {
	setup();

	int p, m, x;
	input(p, m, x);
	
	int o = x;
	string s;
	int i = modInv(p, m);

	while (x) {
		int finX = m - 1, finA;
		range(a, 1, 27) {
			int currX = (((x - a + m) % m) * i) % m;
			if (finX > currX) {
				finX = currX;
				finA = a;
			}
		}
		s += static_cast<int>('a' - 1 + finA);
		x = finX;
	}

	assert(polyhash(s, p, m) == o);
	print(s);
}
