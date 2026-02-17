#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

int get(int x, int m, vector<array<int, 3>> &e, vector<vi> &g, vi &btoa) {
    g = vector<vi>(m);
    btoa = vi(m, -1);
    for (auto [w, i, j] : e) {
        if (w <= x) {
            g[i].push_back(j);
        }
    }
    return hopcroftKarp(g, btoa);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> d(n + 1, vi(n + 1));
    rep(i, 0, n + 1) {
        rep(j, 0, n + 1) {
            cin >> d[i][j];
        }
    }

    rep(k, 0, n + 1) {
        rep(i, 0, n + 1) {
            rep(j, 0, n + 1) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector<array<int, 3>> e;
    rep(i, 0, m) {
        rep(j, m, n) {
            e.push_back({d[n][j] + d[j][i], i, j - m});
        }
        rep(j, n, 2 * m) {
            e.push_back({d[n][i], i, j - m});
        }
    }

    int l = 0, r = 1e9, res = 1e9;
    vector<vi> g(m);
    vi btoa(m);
    while (l <= r) {
        int k = (l + r) / 2;
        if (get(k, m, e, g, btoa) == m) {
            res = k;
            r = k - 1;
        }
        else {
            l = k + 1;
        }
    }
    assert(get(res, m, e, g, btoa) == m);
    get(res, m, e, g, btoa);
    cout << res << endl;
    vi atob(m);
    rep(i, 0, m) {
        atob[btoa[i]] = i;
    }
    rep(i, 0, m) {
        if (m + atob[i] < n) {
            cout << m + atob[i] + 1 << endl;
        }
        else {
            cout << 0 << endl;
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
