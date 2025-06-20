#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
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

	vector<int> a(n), b(m);
	arrput(a);
	arrput(b);

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	rep(i, 0, n) {
		rep(j, 0, m) {
			dp[i + 1][j + 1] = max({
				dp[i + 1][j],
				dp[i][j + 1],
				dp[i][j] + (a[i] == b[j])
			});
		}
	}
	print(dp[n][m]);

	vector<int> res;
	int u = n - 1, v = m - 1;
	while (u >= 0 and v >= 0) {
		if (dp[u + 1][v + 1] == dp[u][v] + 1 and a[u] == b[v]) {
			res.push_back(a[u]);
			u--;
			v--;
		}
		else if (dp[u + 1][v + 1] == dp[u + 1][v]) {
			v--;
		}
		else {
			u--;
		}
	}
	reverse(res.begin(), res.end());
	arrprint(res);
}
