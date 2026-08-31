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
    int n;
	cin >> n;

	n *= 2;
	vi h(n);
	rep(i, 0, n) {
		cin >> h[i];
	}

	vector<vi> dp(n, vi(n, 1e18));
	for (int l = 2; l <= n; l += 2) {
		rep(i, 0, n - l + 1) {
			int j = i + l - 1;
			for (int k = i; k < j; k += 2) {
				dp[i][j] = min(dp[i][j],
					(k == i ? 0 : dp[i][k - 1]) + 
					(k == j - 1 ? 0 : dp[k + 1][j - 1]) + 
					abs(h[k] - h[j])
				);
			}
		}
	}

	cout << dp[0][n - 1] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
