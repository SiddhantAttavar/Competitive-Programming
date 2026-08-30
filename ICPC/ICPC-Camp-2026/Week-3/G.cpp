#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> v(n);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        v[b - 1].push_back({a - 1, c - 1});
    }

    vi dp(1 << n, 0);
    dp[(1 << n) - 1] = 1;
    for (int i = (1 << n) - 2; i >= 0; i--) {
        rep(b, 0, n) {
            if (i >> b & 1) {
                continue;
            }
            bool flag = true;
            for (auto [a, c] : v[b]) {
                if ((i >> a & 1) == (i >> c & 1)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                dp[i] = (dp[i] + dp[i | (1 << b)]) % MOD;
            }
        }
    }
    cout << dp[0] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
