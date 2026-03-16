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
    int r, c, n, p;
    cin >> r >> c >> n >> p;

    vector<vi> a(r, vi(c));
    rep(i, 0, r) {
        rep(j, 0, c) {
            cin >> a[i][j];
        }
    }

    vector<int> v(n, n);
    rep(i, 0, r) {
        rep(j, 0, c) {
            if (i and a[i][j] != 0 and a[i - 1][j] != 0) {
                int d = abs(a[i][j] - a[i - 1][j]);
                v[d] = min({v[d], a[i][j], a[i - 1][j]});
            }
            if (j and a[i][j] != 0 and a[i][j - 1] != 0) {
                int d = abs(a[i][j] - a[i][j - 1]);
                v[d] = min({v[d], a[i][j], a[i][j - 1]});
            }
        }
    }

    int res = 0;
    rep(q, 1, n + 1) {
        res += p != q and v[abs(p - q)] <= min(p, q);
    }
    cout << res << '/' << n - 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
