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

int modPow(int x, int y, int m) {
	int res = 1;
	int a = x;
	while (y) {
		if (y & 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		y >>= 1;
	}
	return res;
}

int solve(int k, int n, int m) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return (1 + k) % m;
	}

	if (n % 2 == 0) {
		return (solve(k, n - 1, m) + modPow(k, n, m)) % m;
	}
	
	return ((1 + k) * solve((k * k) % m, n / 2, m)) % m;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, m;
		input(n, k, m);

		int b = modPow(k, n, m);
		print(solve(k, n - 1, m), b);
	}
}
