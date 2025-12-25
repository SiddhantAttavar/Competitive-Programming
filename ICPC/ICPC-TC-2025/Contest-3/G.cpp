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
    int n, m;
    cin >> n >> m;

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vi l = {m};
    while (l.back()) {
        l.push_back((2 * l.back()) / 3);
    }

    vector<vector<int>> dp(n + 3, vi(sz(l), 0));
    rep(i, 0, n) {
        dp[i + 3][0] = *max_element(dp[i].begin(), dp[i].end()) + min(m, a[i]);
        rep(j, 0, sz(l)) {
            dp[i + 3][j] = max(dp[i + 3][j], dp[i + 1][j] + min(l[j], a[i]));
        }
        rep(j, 1, sz(l)) {
            dp[i + 3][j] = max(dp[i + 3][j], dp[i + 2][j - 1] + min(l[j], a[i]));
        }
    }
    cout << *max_element(dp[n + 2].begin(), dp[n + 2].end()) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
