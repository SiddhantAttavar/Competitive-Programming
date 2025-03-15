#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void get(int l, int r, vector<vector<int>> &dp, vector<int> &a, vector<pair<int, int>> &v) {
	int x = r - l + 1;
	if (x == 1 or dp[l][r] == x * x) {
		v.push_back({l, r});
		return;
	}

	rep(s, l, r) {
		if (dp[l][r] == dp[l][s] + dp[s + 1][r]) {
			get(l, s, dp, a, v);
			get(s + 1, r, dp, a, v);
			return;
		}
	}
}

void solve(int l, int r, int k, vector<pair<int, int>> &res) {
	if (k == 0) {
		return;
	}

	solve(l, r, k - 1, res);
	res.push_back({l, r});
	res.push_back({l, r - 1});
	solve(l, r - 1, k - 1, res);
}

int check(vector<int> &a, vector<pair<int, int>> &res) {
	// print("");
	for (pair<int, int> p : res) {
		int l, r;
		tie(l, r) = p;

		set<int> s(a.begin() + l, a.begin() + r + 1);
		int x = 0;
		while (s.count(x)) {
			x++;
		}
		// arrprint(s);
		// print(x, l, r);

		rep(i, l, r + 1) {
			a[i] = x;
		}
		// arrprint(a);
	}
	return accumulate(a.begin(), a.end(), 0ll);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	vector<vector<int>> dp(n, vector<int>(n));
	rep(i, 0, n) {
		dp[i][i] = max(1ll, a[i]);
	}
	rep(i, 0, n - 1) {
		dp[i][i + 1] = max(4ll, a[i] + a[i + 1]);
	}
	rep(l, 2, n + 1) {
		rep(i, 0, n - l + 1) {
			int j = i + l - 1;
			dp[i][j] = l * l;
			rep(k, i, j) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}

	// rep(i, 0, n) {
	// 	arrprint(dp[i]);
	// }
	// cout.flush();

	vector<pair<int, int>> v;
	get(0, n - 1, dp, a, v);

	vector<pair<int, int>> res;
	for (pair<int, int> p : v) {
		int l, r;
		tie(l, r) = p;

		int k = r - l + 1;
		if (accumulate(a.begin() + l, a.begin() + r + 1, 0ll) >= k * k) {
			continue;
		}

		res.push_back({l, r});
		if (*min_element(a.begin() + l, a.begin() + r + 1) == 0) {
			res.push_back({l, r});
		}

		solve(l, r, k - 1, res);
		res.push_back({l, r});
	}

	print(dp[0][n - 1], res.size());
	for (pair<int, int> p : res) {
		print(p.first + 1, p.second + 1);
	}

	// vector<int> b(a.begin(), a.end());
	// print(check(b, res), dp[0][n - 1]);
	// cout.flush();
	assert(check(a, res) == dp[0][n - 1]);
}
