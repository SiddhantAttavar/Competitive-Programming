#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (int16_t i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int int16_t
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
// const int MOD = (int) 1e9 + 7; //998244353;

int n, m;
int dp[40][40][400][10];
string a[40];

void dfs(tuple<int, int, int, int> u) {
	int l, r, k, x;
	tie(l, r, k, x) = u;

	if (x and dp[l][r][k][x] == dp[l][r][k][x - 1]) {
		dfs({l, r, k, x - 1});
		return;
	}

	int c = 0;
	for (int j = r; j > l; j--) {
		c += a[j][k] != ('0' + x);
		a[j][k] = '0' + x;
		if (k < m - 1 and x and dp[l][r][k][x] == dp[j][r][k + 1][9] + dp[l][j - 1][k][x - 1] + c) {
			dfs({j, r, k + 1, 9});
			dfs({l, j - 1, k, x - 1});
			return;
		}
	}
	a[l][k] = '0' + x;
	if (k < m - 1) {
		dfs({l, r, k + 1, 9});
	}
}
int32_t main() {
	setup();

	input(n, m);
	arrput(a);

	for (int k = m - 1; k >= 0; k--) {
		rep(r, 0, n) {
			for (int l = r; l >= 0; l--) {
				rep(x, 0, 10) {
					dp[l][r][k][x] = 18000;
					if (x) {
						dp[l][r][k][x] = dp[l][r][k][x - 1];
					}

					int c = 0;
					for (int j = r; j > l; j--) {
						c += a[j][k] != ('0' + x);
						if (k < m - 1 and x) {
							dp[l][r][k][x] = min(dp[l][r][k][x], (int) (dp[j][r][k + 1][9] + dp[l][j - 1][k][x - 1] + c));
						}
					}
					c += a[l][k] != ('0' + x);
					if (k < m - 1) {
						dp[l][r][k][x] = min(dp[l][r][k][x], (int) (dp[l][r][k + 1][9] + c));
					}
					else {
						dp[l][r][k][x] = min(dp[l][r][k][x], c);
					}
				}
			}
		}
	}

	dfs({0, n - 1, 0, 9});
	for (string s : a) {
		print(s);
	}
}
