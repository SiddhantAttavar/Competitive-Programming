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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7, M = (int) 1e7 + 19; //998244353;

void solve(int l, int r, vi dp, vector<array<int, 4>> &a, vi &res) {
	if (l == r) {
		for (auto [v, w, s, e] : a) {
			for (int i = sz(dp) - 1; i >= w; i--) {
				dp[i] = max(dp[i], dp[i - w] + v);
			}
		}
		for (int i = sz(dp) - 1; i > 0; i--) {
			res[l] = (res[l] * M + dp[i]) % MOD;
		}
		return;
	}

	int m = (l + r) / 2;
	vector<array<int, 4>> f, g;
	for (auto [v, w, s, e] : a) {
		if (s <= l and r <= e) {
			for (int i = sz(dp) - 1; i >= w; i--) {
				dp[i] = max(dp[i], dp[i - w] + v);
			}
			continue;
		}

		if (s <= m) {
			f.push_back({v, w, s, e});
		}
		if (e > m) {
			g.push_back({v, w, s, e});
		}
	}

	solve(l, m, dp, f, res);
	solve(m + 1, r, dp, g, res);
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<array<int, 4>> a(n);
	rep(i, 0, n) {
		int v, w;
		input(v, w);
		a[i] = {v, w, 0, -1};
	}

	vi b;
	int q;
	input(q);
	rep(i, 0, q) {
		int o;
		input(o);

		if (o == 1) {
			int v, w;
			input(v, w);
			a.push_back({v, w, i, -1});
		}
		else if (o == 2) {
			int x;
			input(x);
			a[x - 1][3] = i;
		}
		else {
			b.push_back(i);
		}
	}

	rep(i, 0, sz(a)) {
		if (a[i][3] == -1) {
			a[i][3] = q - 1;
		}
	}

	vi dp(k + 1, 0), res(q, 0);
	solve(0, q - 1, dp, a, res);
	for (int i : b) {
		print(res[i]);
	}
}
