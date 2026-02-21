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
    int n, k;
    cin >> n >> k;
    
    vi r(n), c(n);
    rep(i, 0, n) {
        cin >> r[i] >> c[i];
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    int x1 = *min_element(all(r)), x2 = *max_element(all(r));
    int y1 = *min_element(all(c)), y2 = *max_element(all(c));
    int l = x2 - x1 + 1, w = y2 - y1 + 1;
    int res = 0;
    rep(i, 0, k + 1) {
        res = max(res, (l + i) * (w + k - i));
    }
    rep(i, 0, n) {
        int p = min(r[i] - x1, x2 - r[i]), q = min(c[i] - y1, y2 - c[i]), t = k;
        int z = min({p, q, t});
        t -= z;
        p -= z;
        q -= z;
        if (p) {
            int z = min(p, t);
            res = max(res, (l + t - z) * (w + t));
        }
        else {
            int z = min(q, t);
            res = max(res, (l + t) * (w + t - z));
        }
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
