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
	int N = 250;
	vector<vector<int>> c(N + 1, vector<int>(N + 1));
	rep(n, 0, N + 1) {
		c[n][0] = 1;
		rep(r, 1, n + 1) {
			c[n][r] = (c[n - 1][r] + c[n - 1][r - 1]) % MOD;
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> dp(n, vector<int>(n, 0));
		rep(i, 0, n - 1) {
			dp[i][i + 1] = a[i] > a[i + 1];
		}
		for (int l = 4; l <= n; l += 2) {
			rep(i, 0, n - l + 1) {
				int j = i + l - 1;
				if (a[j - 1] > a[j]) {
					dp[i][j] = dp[i][j - 2] * (l / 2) % MOD;
				}
				if (a[i] > a[j]) {
					dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % MOD;
				}
				for (int k = j - 3; k > i; k -= 2) {
					if (a[k] > a[j]) {
						dp[i][j] = (dp[i][j] + dp[i][k - 1] * dp[k + 1][j - 1] % MOD * c[l / 2][(j - k + 1) / 2]) % MOD;
					}
				}
			}
		}
		print(dp[0][n - 1]);
	}
}
