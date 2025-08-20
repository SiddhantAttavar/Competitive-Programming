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

void solve(int l, int r, int x, int y, vector<int> &dp, vector<int> &ndp, vector<vector<int>> &a) {
	if (l > r) {
		return;
	}

	int m = (l + r) / 2;
	pair<int, int> z = {4e18, -1};
	rep(i, x, min(y + 1, m)) {
		z = min(z, {dp[i] + a[i][m - 1], i});
	}
	ndp[m] = z.first;

	solve(l, m - 1, x, z.second, dp, ndp, a);
	solve(m + 1, r, z.second, y, dp, ndp, a);
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);
	cin.ignore();

	vector<vector<int>> u(n, vector<int>(n));
	rep(i, 0, n) {
		string s;
		getline(cin, s);
		rep(j, 0, n) {
			u[i][j] = s[2 * j] - '0';
		}
	}

	vector<vector<int>> p(n + 1, vector<int>(n + 1, 0));
	rep(i, 0, n) {
		rep(j, 0, n) {
			p[i + 1][j + 1] += p[i][j + 1] + p[i + 1][j] - p[i][j] + u[i][j];
		}
	}

	vector<vector<int>> a(n, vector<int>(n));
	rep(i, 0, n) {
		rep(j, 0, n) {
			a[i][j] = p[j + 1][j + 1] - p[i][j + 1] - p[j + 1][i] + p[i][i];
		}
	}

	vector<int> dp1(n + 1, 1e18), dp2(n + 1, 1e18);
	dp1[0] = 0;
	rep(i, 0, k) {
		if (i % 2 == 0) {
			solve(1, n, 0, n - 1, dp1, dp2, a);
		}
		else {
			solve(1, n, 0, n - 1, dp2, dp1, a);
		}
	}
	if (k % 2 == 0) {
		print(dp1.back() / 2);
	}
	else {
		print(dp2.back() / 2);
	}
}
