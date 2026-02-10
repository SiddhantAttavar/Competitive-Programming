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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vi> a(n, vi(m));
		rep(i, 0, n) {
			arrput(a[i]);
		}

		vector<vi> dp(n + 1, vi(m + 1, -1e18)), rdp(n + 1, vi(m + 1, -1e18));
		dp[0][1] = 0;
		rep(i, 0, n) {
			rep(j, 0, m) {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]) + a[i][j];
			}
		}
		rdp[n][m - 1] = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				rdp[i][j] = max(rdp[i + 1][j], rdp[i][j + 1]) + a[i][j];
			}
		}

		vector<vi> p(n, vi(m + 1, -1e18)), q(n + 1, vi(m, -1e18));
		rep(i, 0, n) {
			for (int j = m - 1; j >= 0; j--) {
				p[i][j] = max(p[i][j + 1], dp[i + 1][j + 1] + (rdp[i][j] - a[i][j]));
			}
		}
		rep(j, 0, m) {
			for (int i = n - 1; i >= 0; i--) {
				q[i][j] = max(q[i + 1][j], dp[i + 1][j + 1] + (rdp[i][j] - a[i][j]));
			}
		}

		int res = 1e18;
		rep(i, 0, n) {
			rep(j, 0, m) {
				int x = (dp[i + 1][j + 1] - a[i][j]) + (rdp[i][j] - a[i][j]) - a[i][j];
				if (i and j < m) {
					x = max(x, p[i - 1][j + 1]);
				}
				if (j and i < n) {
					x = max(x, q[i + 1][j - 1]);
				}
				res = min(res, x);
			}
		}
		print(res);
	}
}
