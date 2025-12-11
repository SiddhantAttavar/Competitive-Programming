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

int mpow(int a, int b) {
	a %= MOD;
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

int32_t main() {
	int N = 2.5e5;
	vector<int> spf(N + 1), z(N + 1, 1), w(N + 1, 0);
	vector<bool> b(N + 1, false);
	iota(spf.begin(), spf.end(), 0);
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			z[j] *= i;
			w[j]++;
			b[j] = !b[j];
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}
	vector<vector<int>> p(N + 1);
	rep(i, 1, N + 1) {
		for (int j = 2 * i; j <= N; j += i) {
			p[j].push_back(i);
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> f(n + 1);
		rep(i, 0, n) {
			int x;
			input(x);
			f[z[x]]++;
		}

		vector<vector<int>> x(n + 1, vector<int>(10, 0));
		rep(i, 1, n + 1) {
			if (!f[i]) {
				continue;
			}
			for (int j : p[i]) {
				x[j][w[i]] += f[i];
			}
			x[i][w[i]] += f[i];
		}

		vector<vector<int>> dp(n + 1, vector<int>(20, 0));
		rep(i, 1, n + 1) {
			if (i != z[i]) {
				continue;
			}

			rep(a, 0, 10) {
				dp[i][2 * a] += x[i][a] * (x[i][a] - 1) / 2;
				rep(b, a + 1, 10) {
					dp[i][a + b] += x[i][a] * x[i][b];
				}
			}

			for (int j : p[i]) {
				rep(c, 0, 20) {
					if (b[i] == b[j]) {
						dp[j][c] += dp[i][c];
					}
					else {
						dp[j][c] -= dp[i][c];
					}
				}
			}
		}

		int ans = 0;
		rep(i, 1, n + 1) {
			rep(c, 0, 20) {
				ans = (ans + dp[i][c] % MOD * mpow(c - w[i], k)) % MOD;
			}
		}
		print(ans);
	}
}
