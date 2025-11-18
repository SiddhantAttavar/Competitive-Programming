#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int x = min(n, 1000ll);
    vector<int> p(n), q(n);
    
    rep(i, 0, n) {
        p[i] = __gcd(i + 1, a);
        q[i] = __gcd(i + 1, b);
    }

    vector<vector<int>> dp(x, vector<int>(x));
    dp[0][0] = 0;
    rep(i, 1, x) {
        dp[i][0] = dp[i - 1][0] + q[n - 1];
        dp[0][i] = dp[0][i - 1] + p[n - 1];
    }
    rep(i, 1, x) {
        rep(j, 1, x) {
            dp[i][j] = min(dp[i - 1][j] + p[n - j - 1], dp[i][j - 1] + q[n - i - 1]);
        }
    }

    int res = 1e18;
    rep(i, 0, x) {
        rep(j, 0, x) {
            if (p[n - i - 1] == 1 or q[n - i - 1] == 1) {
                res = min(res, dp[i][j] + (n - i - 1) + (n - j - 1));
            }
        }
    }
    res += accumulate(p.begin(), p.end(), 0ll);
    res += accumulate(q.begin(), q.end(), 0ll);
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
