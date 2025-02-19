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

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % m;
		}
		a = a * a % m;
		b /= 2;
	}
	return res;
}

int mod_div(int a, int b) {
	return (a * mod_pow(b, m - 2)) % m;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string a, b;
		input(a, b);

		vector<int> x(n);
		x[0] = 1;
		range(i, 1, n) {
			x[i] = mod_div((n + i * x[i - 1]) % m, n - i);
		}

		int c = 0;
		range(i, 0, n) {
			c += a[i] != b[i];
		}

		int res = 0;
		range(i, n - c, n) {
			res = (res + x[i]) % m;
		}
		print(res);
	}
}
