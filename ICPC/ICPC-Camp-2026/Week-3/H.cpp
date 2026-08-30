#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pii, int> dp;

int solve(int q, int a, vi &w, vector<int> &v) {
    if (dp.count({q, a})) {
        return dp[{q, a}];
    }

    int c = 0;
    for (int b : v) {
        c += (b & q) == a;
    }
    if (c <= 1) {
        return 0;
    }

    int res = 1e18;
    rep(i, 0, sz(w)) {
        if (!(q >> i & 1)) {
            res = min(res, max(
                solve(q | (1 << i), a, w, v),
                solve(q | (1 << i), a | (1 << i), w, v)
            ) + w[i]);
        }
    }
    return dp[{q, a}] = res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m, 0);
    rep(i, 0, m) {
        string s;
        cin >> s;
        rep(j, 0, n) {
            v[i] |= (s[j] == '1') << j;
        }
    }

    vi w(n);
    rep(i, 0, n) {
        cin >> w[i];
    }

    cout << solve(0, 0, w, v) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
