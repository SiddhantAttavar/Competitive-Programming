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
    int n, m, q;
    cin >> n >> m >> q;

    vector<array<int, 4>> e;
    vi l;
    rep(i, 0, m) {
        int u, v, p, w;
        cin >> u >> v >> p >> w;
        e.push_back({u - 1, v - 1, p, w});
        l.push_back(p);
    }

    sort(all(l));
    l.erase(unique(all(l)), l.end());
    vector<vector<array<int, 3>>> g(sz(l));
    for (auto [u, v, p, w] : e) {
        int i = lower_bound(all(l), p) - l.begin();
        g[i].push_back({u, v, w});
    }

    vector<vi> d(n, vi(n, 1e18));
    rep(i, 0, n) {
        d[i][i] = 0;
    }
    vector<vi> a(sz(l), vi(n, 1e18)), b(sz(l), vi(n)), c(sz(l), vi(n));
    rep(i, 0, sz(l)) {
        for (auto [u, v, w] : g[i]) {
            rep(x, 0, n) {
                rep(y, 0, n) {
                    d[x][y] = min(d[x][y], d[x][u] + w + d[v][y]);
                }
            }
        }
        rep(j, 0, n) {
            a[i][j] = *max_element(all(d[j]));
        }
        iota(all(b[i]), 0);
        sort(all(b[i]), [&](int x, int y) {
            return a[i][x] < a[i][y];
        });
        c[i] = b[i];
        rep(j, 1, n) {
            c[i][j] = min(c[i][j], c[i][j - 1]);
        }
    }
    // rep(i, 0, sz(l)) {
    //     rep(j, 0, n) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    while (q--) {
        int o;
        cin >> o;

        if (o == 1) {
            int u, h;
            cin >> u >> h;
            u--;

            int s = 0, e = sz(l) - 1, res = -1;
            while (s <= e) {
                int m = (s + e) / 2;
                if (a[m][u] <= h) {
                    res = m;
                    e = m - 1;
                }
                else {
                    s = m + 1;
                }
            }

            if (res == -1) {
                cout << -1 << endl;
            }
            else {
                cout << l[res] << endl;
            }
        }
        else {
            int h;
            cin >> h;

            pii res = {-1, -1};
            int s = 0, e = sz(l) - 1;
            while (s <= e) {
                int m = (s + e) / 2;
                if (a[m][b[m][0]] <= h) {
                    res.second = m;
                    e = m - 1;
                }
                else {
                    s = m + 1;
                }
            }

            if (res.second == -1) {
                cout << -1 << ' ' << -1 << endl;
                continue;
            }

            s = 0, e = n - 1;
            while (s <= e) {
                int m = (s + e) / 2;
                if (a[res.second][b[res.second][m]] <= h) {
                    res.first = m;
                    s = m + 1;
                }
                else {
                    e = m - 1;
                }
            }

            cout << c[res.second][res.first] + 1 << ' ' << l[res.second] << endl;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
