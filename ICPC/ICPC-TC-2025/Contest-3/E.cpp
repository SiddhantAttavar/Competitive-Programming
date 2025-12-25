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

    map<string, int> s;
    vector<pair<int, int>> e, f;
    rep(i, 0, n) {
        string u, w, v;
        cin >> u >> w >> v;

        if (!s.count(u)) {
            s[u] = sz(s);
        }
        if (!s.count(v)) {
            s[v] = sz(s);
        }

        if (w == "is-a") {
            e.push_back({s[u], s[v]});
        }
        else {
            f.push_back({s[u], s[v]});
        }
    }

    int k = sz(s);
    vector<vector<bool>> a(k, vector<bool>(k, false));
    rep(i, 0, k) {
        a[i][i] = true;
    }
    for (auto [u, v] : e) {
        a[u][v] = true;
    }
    rep(l, 0, k) {
        rep(i, 0, k) {
            rep(j, 0, k) {
                a[i][j] = a[i][j] or a[i][l] and a[l][j];
            }
        }
    }

    vector<vector<bool>> b(k, vector<bool>(k, false));
    for (auto [u, v] : f) {
        b[u][v] = true;
    }
    rep(l, 0, k) {
        rep(i, 0, k) {
            rep(j, 0, k) {
                b[i][j] = b[i][j] or b[i][l] and b[l][j];
            }
        }
    }
    rep(l, 0, k) {
        rep(i, 0, k) {
            rep(j, 0, k) {
                b[i][j] = b[i][j] or b[i][l] and a[l][j];
            }
        }
    }
    rep(l, 0, k) {
        rep(i, 0, k) {
            rep(j, 0, k) {
                b[i][j] = b[i][j] or b[i][l] and b[l][j];
            }
        }
    }
    rep(l, 0, k) {
        rep(i, 0, k) {
            rep(j, 0, k) {
                b[i][j] = b[i][j] or a[i][l] and b[l][j];
            }
        }
    }

    rep(i, 0, m) {
        string u, w, v;
        cin >> u >> w >> v;

        int p = s[u], q = s[v];
        cout << "Query " << i + 1 << ": ";
        if (w == "is-a" and a[p][q] or w == "has-a" and b[p][q]) {
            cout << "true\n";
        }
        else {
            cout << "false\n";
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
