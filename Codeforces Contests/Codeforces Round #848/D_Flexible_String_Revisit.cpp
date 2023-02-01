#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int m = 998244353;

int modPow(int a, int b) {
	int x = a;
	while (b) {
		if (b & 1) {
			a = (a * x) % m;
		}
		x = (x * x) % m;
		b /= 2;
	}
	return a;
}

int modInv(int a) {
	return modPow(a, m - 2);
}

int modDiv(int a, int b) {
	return (a * modInv(b)) % m;
}

int solve(int c, int n) {
	return modDiv(solve(c - 1, n) * c + solve(c + 1, n) * (n - c) + n, n);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string a, b;
		input(a, b);

		int c = 0;
		range(i, 0, n) {
			c += a[i] != b[i];
		}

		print(solve(c, n));
	}
}
