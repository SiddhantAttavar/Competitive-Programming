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

const int MOD = (int) 1e9 + 7;

int mod_inv(int a) {
	int res = 1;
	int b = MOD - 2;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}

	return res;
}

int32_t main() {
	int N = 1e6;
	vector<int> fact(N + 1, 1), fact_inv(N + 1);
	range(i, 2, N + 1) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	range(i, 0, N + 1) {
		fact_inv[i] = mod_inv(fact[i]);
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<string> v(n);
		arrPut(v);

		if (n == 1) {
			print(1);
			continue;
		}

		vector<vector<bool>> a(n, vector<bool>(m));
		range(i, 0, n) {
			range(j, 0, m) {
				a[i][j] = v[i][j] == '1';
			}
		}

		for (int i = n - 1; i >= 2; i--) {
			int x = 0;
			for (bool j : a[i - 1]) {
				x += j;
			}

			if (x < 2) {
				continue;
			}

			bool flag = false;
			range(j, 0, m) {
				if (a[i][j] and a[i - 1][j]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				continue;
			}

			range(j, 0, m) {
				if (a[i][j]) {
					a[i - 1][j] = true;
				}
			}
		}

		// range(i, 0, n) {
		// 	arrPrint(a[i]);
		// }

		int x = 0, y = 0;
		range(j, 0, m) {
			x += a[1][j] and a[0][j];
			y += a[1][j] and !a[0][j];
		}

		print((fact[x + y] * ((fact_inv[x] * fact_inv[y]) % MOD)) % MOD);
	}
}
