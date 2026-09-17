#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, q;
	cin >> n >> q;

	vi v(n), c(n);
	rep(i, 0, n) {
		cin >> v[i];
	}
	rep(i, 0, n) {
		cin >> c[i];
	}

	while (q--) {
		int a, b;
		cin >> a >> b;

		int x = 0, y = 0;
		vi dp(n + 1, -1e18);
		dp[0] = 0;
		rep(i, 0, n) {
			int z = dp[c[i]] + a * v[i];
			if (x != c[i]) {
				z = max(z, dp[x] + b * v[i]);
			}
			if (y != c[i]) {
				z = max(z, dp[y] + b * v[i]);
			}
			dp[c[i]] = max(dp[c[i]], z);
			
			if (dp[x] < dp[y]) {
				swap(x, y);
			}
			if (x == c[i] or y == c[i]) {
				continue;
			}
			if (z > dp[x]) {
				y = x;
				x = c[i];
			}
			else if (z > dp[y]) {
				y = c[i];
			}
		}
		cout << *max_element(all(dp)) << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
