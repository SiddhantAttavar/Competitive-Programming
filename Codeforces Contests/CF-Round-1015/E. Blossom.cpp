#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return a * mod_pow(b, MOD - 2) % MOD;
}

int32_t main() {
	int N = 1e5;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		int c = 0;
		for (int i : a) {
			c += i == -1;
		}

		vector<int> p(n + 1, 0);
		rep(i, 0, n) {
			p[i + 1] = p[i] + (a[i] == -1);
		}

		vector<bool> b(n, false);
		rep(i, 0, n) {
			if (a[i] != -1) {
				b[a[i]] = true;
			}
		}

		vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));
		int x = n;
		rep(i, 0, n) {
			int y = x;
			for (int j = n - 1; j >= i; j--) {
				int z = p[j + 1] - p[i];
				if (y == 0) {
					break;
				}
				d[z][y - 1]++;
				if (a[j] != -1) {
					y = min(y, a[j]);
				}
			}
			if (a[i] != -1) {
				x = min(x, a[i]);
			}
		}

		rep(i, 0, n + 1) {
			for (int j = n - 1; j >= 0; j--) {
				d[i][j] += d[i][j + 1];
			}
		}

		int res = 0, k = 0;
		rep(i, 0, n) {
			k += !b[i];
			rep(j, k, c + 1) {
				res = (res + d[j][i] * mod_div(fact[j] * fact[c - k] % MOD, fact[j - k])) % MOD;
			}
		}
		print(res);
	}
}
