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

	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	vector<int> p(n + 1, 0);
	rep(i, 0, n) {
		p[i + 1] = p[i] + a[i];
	}

	vector<vector<int>> dp(n, vector<int>(n, 1e18));
	rep(i, 0, n) {
		dp[i][i] = 0;
	}
	rep(l, 2, n + 1) {
		rep(i, 0, n - l + 1) {
			int j = i + l - 1;
			rep(k, i, j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[j + 1] - p[i]);
			}
		}
	}
	print(dp[0][n - 1]);
}
