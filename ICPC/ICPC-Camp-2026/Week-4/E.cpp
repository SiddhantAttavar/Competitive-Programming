#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs1(int u, vector<vector<pii>> &tree, vi &s, vi &dp) {
	for (auto [v, w] : tree[u]) {
		dfs1(v, tree, s, dp);
		s[u] += s[v];
		dp[u] += dp[v] + s[v] * w;
	}
}

void dfs2(int u, vector<vector<pii>> &tree, vi &s, vi &dp, vi &res) {
	for (auto [v, w] : tree[u]) {
		res[v] = res[u] - w * s[v] + (s[0] - s[v]);
		dfs2(v, tree, s, dp, res);
	}
}

void solve() {
    int n;
	cin >> n;

	vector<vector<pii>> tree(n);
	rep(i, 1, n) {
		int p, l;
		cin >> p >> l;
		tree[p - 1].push_back({i, l});
	}

	vi f(n);
	rep(i, 0, n) {
		cin >> f[i];
	}

	vi s = f, dp(n, 0);
	dfs1(0, tree, s, dp);

	vi res(n);
	res[0] = dp[0];
	dfs2(0, tree, s, dp, res);

	int k = *min_element(all(res));
	cout << k << endl;
	rep(i, 0, n) {
		if (res[i] == k) {
			cout << i + 1 << ' ';
		}
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
