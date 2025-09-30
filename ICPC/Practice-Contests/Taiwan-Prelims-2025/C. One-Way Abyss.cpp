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
		int n, m;
		input(n, m);

		vector<vector<int>> a(n);
		vector<int> v(m), c(2 * m);
		rep(i, 0, m) {
			int x, y;
			input(x, y, v[i]);

			x--;
			y--;

			a[x].push_back(2 * i);
			a[y].push_back(2 * i + 1);
			c[2 * i] = y;
			c[2 * i + 1] = x;
		}

		int res = 0;
		vector<int> dp(2 * m, 0);
		rep(i, 0, 2 * m) {
			res = max(res, dp[i] + v[i / 2]);
			int y = c[i];
			int j = upper_bound(a[y].begin(), a[y].end(), i + 1 - i % 2) - a[y].begin();
			if (j < a[y].size()) {
				dp[a[y][j]] = max(dp[a[y][j]], dp[i] + v[i / 2]);
			}
		}
		print(res);
	}
}
