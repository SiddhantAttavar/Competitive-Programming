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

    vector<vi> a(n, vi(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }

    vi d(m);
    rep(j, 0, m) {
        cin >> d[j];
    }

    if (m <= 18) {
        int res = 2e18;
        rep(i, 1, 1 << m) {
            vi b(n, 2e18);
            int c = 0;
            rep(j, 0, m) {
                if (!(i >> j & 1)) {
                    continue;
                }
                c += d[j];
                rep(k, 0, n) {
                    b[k] = min(b[k], a[k][j]);
                }
            }
            res = min(res, c + accumulate(all(b), 0ll));
        }
        cout << res << endl;
        return;
    }

    vi dp(1 << n, 2e18);
    dp[0] = 0;
    rep(j, 0, m) {
        vi p(1 << n, d[j]);
        rep(i, 0, 1 << n) {
            rep(k, 0, n) {
                if (i >> k & 1) {
                    p[i] += a[k][j];
                }
            }
        }
        for (int i = (1 << n) - 1; i; i--) {
            for (int k = i; k; ) {
                --k &= i;
                dp[i] = min(dp[i], dp[k] + p[i ^ k]);
            }
        }
    }
    cout << dp.back() << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
