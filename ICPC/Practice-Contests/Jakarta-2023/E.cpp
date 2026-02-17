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
    const int N = 1000;
	int n;
    cin >> n;

    vi v(2 * n);
    rep(i, 0, 2 * n) {
        cin >> v[i];
    }

    vi p(2 * n + 1, 0);
    rep(i, 0, 2 * n) {
        p[i + 1] = max(p[i], v[i]);
    }

    vector<vi> dpa(2 * n + 1, vi(2 * n + 1, false));
    vector<vi> dpb(2 * n + 1, vi(2 * n + 1, false));
    dpa[0][n] = true;
    rep(i, 0, 2 * n) {
        rep(x, 1, 2 * n + 1) {
            dpa[i + 1][x] = dpa[i][x - 1] or (v[i] == p[i + 1]) and dpb[i][x - 1];
        }
        rep(x, 0, 2 * n) {
            dpb[i + 1][x] = dpb[i][x + 1] or (v[i] == p[i + 1]) and dpa[i][x + 1];
        }
    }

    if (!dpa[2 * n][n] and !dpb[2 * n][n]) {
        cout << -1 << endl;
        return;
    }

    int f = dpb[2 * n][n], i = n - 1, j = n - 1, x = n;
    vi a(n), b(n);
    for (int k = 2 * n - 1; k >= 0; k--) {
        if (f) {
            b[j] = v[k];
            j--;
            x++;
            f = dpb[k][x];
        }
        else {
            a[i] = v[k];
            i--;
            x--;
            f = v[k] == p[k + 1] and dpb[k][x];
        }
    }

    rep(i, 0, n) {
        cout << a[i] << ' ';
    }
    cout << endl;
    rep(i, 0, n) {
        cout << b[i] << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
