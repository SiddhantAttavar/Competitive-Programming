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

#define P pair<int, pair<int, int>>
int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<string> v(n);
	arrput(v);

	vector<vector<vector<P>>> dp(n + 1, vector<vector<P>>(26, vector<P>(26, {0, {-1, -1}})));
	rep(i, 0, n) {
		vector<int> a(26, 0), b(26, 0);
		for (int j = 0; j < m; j += 2) {
			a[v[i][j] - 'a']++;
		}
		for (int j = 1; j < m; j += 2) {
			b[v[i][j] - 'a']++;
		}

		vector<vector<P>> w(26, vector<P>(26, {(int) 1e9, {-1, -1}}));
		vector<vector<P>> x(26, vector<P>(26, {(int) 1e9, {-1, -1}}));
		vector<vector<P>> y(26, vector<P>(26, {(int) 1e9, {-1, -1}}));
		vector<vector<P>> z(26, vector<P>(26, {(int) 1e9, {-1, -1}}));
		rep(j, 0, 26) {
			rep(k, 0, 26) {
				w[j][k] = {dp[i][j][k].first, {j, k}};
				x[j][k] = {dp[i][j][k].first, {j, k}};
				y[j][k] = {dp[i][j][k].first, {j, k}};
				z[j][k] = {dp[i][j][k].first, {j, k}};
			}
		}
		rep(j, 1, 26) {
			w[j][0] = min(w[j][0], w[j - 1][0]);
			x[j][0] = min(x[j][0], x[j - 1][0]);
		}
		for (int j = 24; j >= 0; j--) {
			y[j][0] = min(y[j][0], y[j + 1][0]);
			z[j][0] = min(z[j][0], z[j + 1][0]);
		}
		rep(k, 1, 26) {
			w[0][k] = min(w[0][k], w[0][k - 1]);
			y[0][k] = min(y[0][k], y[0][k - 1]);
		}
		for (int k = 24; k >= 0; k--) {
			x[0][k] = min(x[0][k], x[0][k + 1]);
			z[0][k] = min(z[0][k], z[0][k + 1]);
		}
		rep(j, 1, 26) {
			rep(k, 1, 26) {
				w[j][k] = min({w[j][k], w[j][k - 1], w[j - 1][k]});
			}
			for (int k = 24; k >= 0; k--) {
				x[j][k] = min({x[j][k], x[j][k + 1], x[j - 1][k]});
			}
		}
		for (int j = 24; j >= 0; j--) {
			rep(k, 1, 26) {
				y[j][k] = min({y[j][k], y[j][k - 1], y[j + 1][k]});
			}
			for (int k = 24; k >= 0; k--) {
				z[j][k] = min({z[j][k], z[j][k + 1], z[j + 1][k]});
			}
		}

		rep(j, 0, 26) {
			rep(k, 0, 26) {
				dp[i + 1][j][k] = {(int) 1e9, {-1, -1}};
				if (j == k) {
					continue;
				}
				if (j > 0) {
					if (k > 0) {
						dp[i + 1][j][k] = min(dp[i + 1][j][k], w[j - 1][k - 1]);
					}
					if (k < 25) {
						dp[i + 1][j][k] = min(dp[i + 1][j][k], x[j - 1][k + 1]);
					}
				}
				if (j < 25) {
					if (k > 0) {
						dp[i + 1][j][k] = min(dp[i + 1][j][k], y[j + 1][k - 1]);
					}
					if (k < 25) {
						dp[i + 1][j][k] = min(dp[i + 1][j][k], z[j + 1][k + 1]);
					}
				}
				dp[i + 1][j][k].first += m - a[j] - b[k];
			}
		}

		// rep(j, 0, 26) {
		// 	rep(k, 0, 26) {
		// 		cout << dp[i + 1][j][k].first << ' ';
		// 	}
		// 	cout << endl;
		// }
		// print(dp[i + 1][25][24].second.first, dp[i + 1][25][24].second.second);
		// cout << endl;
	}

	P res = {(int) 1e9, {-1, -1}};
	rep(i, 0, 26) {
		rep(j, 0, 26) {
			res = min(res, {dp[n][i][j].first, {i, j}});
		}
	}
	print(res.first);

	vector<pair<int, int>> s(n);
	s[n - 1] = res.second;
	for (int i = n - 2; i >= 0; i--) {
		s[i] = dp[i + 2][s[i + 1].first][s[i + 1].second].second;
	}

	vector<string> a(n, string(m, 'a'));
	rep(i, 0, n) {
		for (int j = 0; j < m; j += 2) {
			a[i][j] = s[i].first + 'a';
		}
		for (int j = 1; j < m; j += 2) {
			a[i][j] = s[i].second + 'a';
		}
	}
	for (string i : a) {
		print(i);
	}
}
