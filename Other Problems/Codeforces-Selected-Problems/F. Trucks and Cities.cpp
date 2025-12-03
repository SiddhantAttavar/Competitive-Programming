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
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> a(n);
	arrput(a);

	vector<vector<tuple<int, int, int>>> q(n + 1);
	rep(i, 0, m) {
		int s, f, c, r;
		input(s, f, c, r);
		q[r].push_back({s - 1, f - 1, c});
	}

	int res = 0;
	vector<vector<int>> dp(n, vector<int>(n, 1e9));
	rep(i, 0, n) {
		rep(j, i, n) {
			dp[i][j] = a[j] - a[i];
		}
	}
	vector<vector<int>> v = dp;
	for (auto [i, j, c] : q[0]) {
		res = max(res, c * dp[i][j]);
	}
	rep(r, 1, n + 1) {
		vector<vector<int>> ndp(n, vector<int>(n, 1e9)), opt(n, vector<int>(n));
		rep(i, 0, n) {
			ndp[i][i] = 0;
			opt[i][i] = i;
		}
		rep(l, 2, n + 1) {
			rep(i, 0, n - l + 1) {
				int j = i + l - 1;
				rep(k, opt[i][j - 1], opt[i + 1][j] + 1) {
					if (max(dp[i][k], v[k][j]) < ndp[i][j]) {
						ndp[i][j] = max(dp[i][k], v[k][j]);
						opt[i][j] = k;
					}
				}
			}
		}
		dp = ndp;
		for (auto [i, j, c] : q[r]) {
			res = max(res, c * dp[i][j]);
		}
	}
	print(res);
}
