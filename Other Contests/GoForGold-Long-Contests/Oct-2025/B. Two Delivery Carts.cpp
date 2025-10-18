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
	setup(); int tc; input(tc); while (tc--) {
		int n, m, q;
		input(n, m, q);

		vector<vector<int>> a(m, vector<int>(n, 0));
		rep(i, 0, q) {
			int x, t, z;
			input(x, t, z);
			a[t][x - 1] += z;
		}

		vector<vector<int>> dp(n, vector<int>(n, -1e18));
		dp[0][n - 1] = a[0][0] + a[0][n - 1];
		rep(t, 1, m) {
			vector<vector<int>> ndp = dp;
			rep(i, 0, n) {
				rep(j, i + 1, n) {
					rep(k, i - 1, i + 2) {
						rep(l, j - 1, j + 2) {
							if (l > k and k >= 0 and l < n) {
								ndp[i][j] = max(ndp[i][j], dp[k][l]);
							}
						}
					}
					ndp[i][j] += a[t][i] + a[t][j];
				}
			}
			dp = ndp;
		}
		int res = 0;
		rep(i, 0, n) {
			res = max(res, *max_element(dp[i].begin(), dp[i].end()));
		}
		print(res);
	}
}
