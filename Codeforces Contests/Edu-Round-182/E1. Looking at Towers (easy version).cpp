#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

int mod_pow(int a, int b) {
	int res = 1;
	while (b & 1) {
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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<int> l, r;
		rep(i, 0, n) {
			if (l.empty() or l.back() < a[i]) {
				l.push_back(a[i]);
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (r.empty() or r.back() < a[i]) {
				r.push_back(a[i]);
			}
		}

		map<int, int> x, y;
		rep(i, 0, l.size()) {
			x[l[i]] = i;
		}
		rep(i, 0, r.size()) {
			y[r[i]] = i;
		}

		vector<int> f(n, 0);
		vector<int> p(l.size(), 0);
		int k = 1;
		rep(i, 0, n) {
			k = k * 2 % MOD;
			if (!x.count(a[i])) {
				continue;
			}
			int j = x[a[i]];
			if (j == 0) {
				p[j] = (p[j] + mod_div(1, k)) % MOD;
				f[i] = 1;
				continue;
			}
			int z = l[j - 1];
			int c = 1;
			p[j] = (p[j] + mod_div(f[i], k)) % MOD;
			for (int j = i - 1; j >= 0; j--) {
				if (a[j] == z) {
					f[i] = (f[i] + c * f[j]) % MOD;
				}
				if (a[j] <= z) {
					c = c * 2 % MOD;
				}
			}
		}

		vector<int> g(n, 0);
		for (int i = n - 1; i >= 0; i--) {
			if (!y.count(a[i])) {
				continue;
			}
			if (y[a[i]] == 0) {
				g[i] = 1;
				continue;
			}
			int z = r[y[a[i]] - 1];
			int c = 1;
			rep(j, i + 1, n) {
				if (a[j] == z) {
					g[i] = (g[i] + c * g[j]) % MOD;
				}
				if (a[j] <= z) {
					c = c * 2 % MOD;
				}
			}
		}

		int res = 0;
		int k = *max_element(a.begin(), a.end());
		rep(i, 0, n) {
			if (a[i] != k) {
				continue;
			}
			res = (res + f[i] * g[i]) % MOD;
			int c = 1;
			rep(j, i + 1, n) {
				if (a[j] == k) {
					res = (res + f[i] * c % MOD * g[j]) % MOD;
				}
				if (a[j] <= k) {
					c = c * 2 % MOD;
				}
			}
		}
		print(res);
	}
}
