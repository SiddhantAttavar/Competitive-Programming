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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi c(n);
		arrput(c);

		if (n == 1) {
			print(c[0]);
			continue;
		}

		if (n == 2) {
			print(min(c[0], c[1]));
			continue;
		}

		vector<vector<int>> dp(n, vector<int>(8, 0));
		rep(i, 0, 3) {
			rep(j, 0, 8) {
				rep(k, 0, 3) {
					if (i == k or j >> k & 1) {
						dp[i][j] += c[k];
					}
				}
			}
		}

		rep(i, 3, n) {
			rep(j, 0, 8) {
				dp[i][j] = min({dp[i - 1][j], dp[i - 2][j], dp[i - 3][j]}) + c[i];
			}
		}

		int res = 1e18;
		rep(i, n - 3, n) {
			rep(j, 0, 8) {
				if (j & ((1 << (i - n + 4)) - 1)) {
					res = min(res, dp[i][j]);
				}
			}
		}
		print(res);
	}
}
