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

    vi a(n), b(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vector<vi> dp(n, vi(n, 1e18));
    rep(i, 0, n) {
        dp[i][i] = 0;
        a[i]--;
        b[a[i]] = i;
    }
    rep(l, 2, n + 1) {
        rep(i, 0, n - l + 1) {
            int j = i + l - 1;
            dp[i][j] = dp[i + 1][j] + abs(b[i] - b[i + 1]);
            int x = 0;
            rep(k, i + 1, j) {
                x += abs(b[k - 1] - b[k]);
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + abs(b[i] - b[k + 1]));
            }
            dp[i][j] = min(dp[i][j], x + abs(b[j] - b[j - 1]));
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
