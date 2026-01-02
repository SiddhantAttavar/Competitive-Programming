#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = (1ll << 31) - 1;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    rep(i, 0, n + 1) {
        cin >> p[i];
    }

    map<int, int> dp;
    dp[p[0]] = 1;
    rep(i, 1, n) {
        map<int, int> ndp;
        for (auto [w, k] : dp) {
            int x = w, y = p[i], z = p[i + 1];
            if (x > y) {
                swap(x, y);
            }
            if (z < y) {
                ndp[y] = (ndp[y] + k) % MOD;
            }
            if (z > x) {
                ndp[x] = (ndp[x] + k) % MOD;
            }
        }
        dp = ndp;
    }
    int res = 0;
    for (auto [x, p] : dp) {
        res = (res + p) % MOD;
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
