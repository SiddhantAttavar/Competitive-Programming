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

	int n, m, k;
	input(n, m, k);

	vector<vector<int>> a(n, vector<int>(m));
	rep(i, 0, n) {
		arrput(a[i]);
	}

	vector<vector<int>> v(m, vector<int>(n + 1));
	rep(i, 0, m) {
		vector<int> l(n);
		rep(j, 0, n) {
			l[j] = a[j][i];
		}
		sort(l.begin(), l.end());
		reverse(l.begin(), l.end());
		v[i][0] = 0;
		rep(j, 1, n + 1) {
			v[i][j] = v[i][j - 1] + l[j - 1];
		}
	}

	vector<int> dp(m + 1, -1e18);
	vector<int> ndp(m + 1, -1e18);
	dp[0] = 0;
	rep(i, 1, m + 1) {
		vector<pair<int, int>> t;
		rep(j, 1, n + 1) {
			int l = max(1ll, i - k + 1), r = min(m - k + 1, (int) i - j + 1);
			rep(u, l, r + 1) {
				t.push_back({u + j - 1, dp[u - 1] + v[i - 1][j]});
			}
		}
		for (auto [i, x] : t) {
			dp[i] = max(dp[i], x);
		}
	}
	print(dp[m - k + 1]);
}
