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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	const int N = 6e7;
	vi pow2(N + 1);
	pow2[0] = 1;
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vi> dp(n, vi(m));
		dp[0][0] = pow2[n + m];
		rep(i, 1, n) {
			dp[i][0] = dp[i - 1][0] * pow2[2 * m - 1] % MOD;
		}
		rep(j, 1, m) {
			dp[0][j] = dp[0][j - 1] * pow2[2 * n - 2] % MOD;
		}
		rep(i, 1, n) {
			rep(j, 1, m) {
				dp[i][j] = (
					dp[i - 1][j] * pow2[2 * (m - j) - 1] + 
					dp[i][j - 1] * pow2[2 * (n - i) - 2]
				) % MOD;
			}
		}

		int res = 0;
		rep(i, 0, n) {
			rep(j, 0, m) {
				res = (res + dp[i][j] * pow2[2 * (m - j - 1) + 2 * m * (n - i - 1)]) % MOD;
			}
		}
		print(res);
	}
}
