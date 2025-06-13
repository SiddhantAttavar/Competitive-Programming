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

	vector<vector<int>> a(n, vector<int>(n));
	rep(i, 0, n) {
		arrput(a[i]);
	}

	vector<int> p(1 << n);
	rep(i, 1, 1 << n) {
		int x = 63 - __builtin_clzll(i);
		p[i] = p[i ^ (1 << x)];
		rep(j, 0, x) {
			if (i & (1 << j)) {
				p[i] += a[x][j];
			}
		}
	}

	vector<int> dp(1 << n);
	dp[0] = 0;
	rep(i, 1, 1 << n) {
		for (int j = i; j; ) {
			--j &= i;
			dp[i] = max(dp[i], dp[j] + p[i ^ j]);
		}
	}
	print(dp.back());
}
