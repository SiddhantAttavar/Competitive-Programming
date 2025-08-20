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

void solve(int l, int r, int x, int y, vector<int> &dp, vector<int> &ndp, vector<int> &p) {
	if (l > r) {
		return;
	}

	int m = (l + r) / 2;
	pair<int, int> z = {1e18, -1};
	for (int i = x; i < min(y + 1, m); i++) {
		z = min(z, {dp[i] + (p[m] - p[i]) * (p[m] - p[i]), i});
	}
	ndp[m] = z.first;

	solve(l, m - 1, x, z.second, dp, ndp, p);
	solve(m + 1, r, z.second, y, dp, ndp, p);
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<int> a(n);
	arrput(a);

	vector<int> p(n + 1, 0);
	rep(i, 0, n) {
		p[i + 1] = p[i] + a[i];
	}

	vector<int> dp(n + 1, 1e18);
	rep(i, 1, n + 1) {
		dp[i] = p[i] * p[i];
	}

	rep(j, 1, k) {
		vector<int> ndp(n + 1, 1e18);
		solve(1, n, 0, n - 1, dp, ndp, p);
		dp = ndp;
	}

	print(dp.back());
}
