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
    const int N = 2000;
    int n, m;
    cin >> n >> m;

    vector<bitset<N>> a(n, 0), b(m, 0);
    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, m) {
            a[i][j] = s[j] == '.';
            b[j][i] = s[j] == '.';
        }
    }

    vi x(n), y(m);
    rep(i, 0, n) {
        x[i] = a[i].count();
    }
    rep(j, 0, m) {
        y[j] = b[j].count();
    }

    int res = 0;
    rep(i, 0, n) {
        res += x[i] * (x[i] - 1) * (x[i] - 2) * (x[i] - 3);
    }
    rep(j, 0, m) {
        res += y[j] * (y[j] - 1) * (y[j] - 2) * (y[j] - 3);
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (!a[i][j]) {
                continue;
            }
            res += 2 * (x[i] - 1) * (y[j] - 1) * (y[j] - 2);
            res += 2 * (y[j] - 1) * (x[i] - 1) * (x[i] - 2);
        }
    }
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            int z = (a[i] & a[j]).count();
            res += 2 * z * max(0ll, x[i] - 1) * max(0ll, x[j] - 1);
        }
    }
    rep(i, 0, m) {
        rep(j, i + 1, m) {
            int z = (b[i] & b[j]).count();
            res += 2 * z * max(0ll, y[i] - 1) * max(0ll, y[j] - 1);
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
