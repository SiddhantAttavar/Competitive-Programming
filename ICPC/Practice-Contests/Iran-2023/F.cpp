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
    vector<string> v;
    string q;
    while (getline(cin, q)) {
        v.push_back(q);
    }

    int n = sz(v), m = sz(v[0]);
    set<pii> s;
    vector<set<int>> a(n), b(m);
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (v[i][j] == '+') {
                s.insert({i, j});
                a[i].insert(j);
                b[j].insert(i);
            }
        }
    }

    vector<array<int, 4>> l;
    while (!s.empty()) {
        auto [x1, y1] = *s.begin();
        int x2 = *next(b[y1].begin()), y2 = *next(a[x1].begin());
        l.push_back({x1, x2, y1, y2});

        s.erase({x1, y1});
        a[x1].erase(y1);
        b[y1].erase(x1);

        s.erase({x1, y2});
        a[x1].erase(y2);
        b[y2].erase(x1);

        s.erase({x2, y1});
        a[x2].erase(y1);
        b[y1].erase(x2);

        s.erase({x2, y2});
        a[x2].erase(y2);
        b[y2].erase(x2);
    }

    l.erase(l.begin());
    vector<set<int>> z;
    map<string, int> p;
    for (auto [x1, x2, y1, y2] : l) {
        set<int> t;
        rep(i, x1 + 1, x2) {
            string u;
            rep(j, y1 + 1, y2) {
                if (v[i][j] == ' ') {
                    continue;
                }
                if ('A' <= v[i][j] and v[i][j] <= 'Z') {
                    v[i][j] += 'a' - 'A';
                }
                u += v[i][j];
            }
            if (u.empty()) {
                continue;
            }
            if (!p.count(u)) {
                p[u] = sz(p);
            }
            t.insert(p[u]);
        }
        z.push_back(t);
    }

    int res = 1e18;
    rep(i, 0, sz(l)) {
        rep(j, i + 1, sz(l)) {
            rep(k, j + 1, sz(l)) {
                set<int> t = z[i];
                t.insert(all(z[j]));
                t.insert(all(z[k]));
                res = min(res, sz(t));
            }
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
