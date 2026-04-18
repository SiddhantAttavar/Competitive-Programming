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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int get(int x, vector<vi> &z, vector<vi> &v) {
	int n = sz(z);
	vi dp(n + 1, 0);
	rep(i, 0, n) {
		dp[i + 1] = dp[i] + 1;
		int c = 0;
		for (int j : v[i]) {
			if (c <= x) {
				dp[i + 1] = min(dp[i + 1], dp[z[i][j] + 1] + 1);
			}
			c |= 1ll << j;
		}
	}
	return dp[n];
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vi a(n);
		arrput(a);

		vector<vi> x(n, vi(20, -1)), y(n, vi(30, -1)), z(n, vi(30, -1)), v(n, vi(30));
		rep(i, 0, n) {
			if (i) {
				x[i] = x[i - 1];
				y[i] = y[i - 1];
			}
			rep(j, 0, 20) {
				if (a[i] >> j & 1) {
					x[i][j] = i;
				}
				else {
					y[i][j] = i;
				}
				z[i][j] = min(x[i][j], y[i][j]);
			}
			iota(all(v[i]), 0);
			sort(all(v[i]), [&](int a, int b) {
				return z[i][a] > z[i][b];
			});
		}

		int l = 0, r = 2e9, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (get(m, z, v) <= k) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		print(res);
	}
}
