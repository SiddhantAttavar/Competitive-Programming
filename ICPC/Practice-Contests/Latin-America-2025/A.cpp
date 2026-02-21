#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dfs(int u, vector<vi> &graph, vi &vis) {
    vis[u] = true;
    int res = 0;
    for (int v : graph[u]) {
        res++;
        if (!vis[v]) {
            res += dfs(v, graph, vis);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    if (n > 2 and n % 2 == 0) {
        cout << "N\n";
        return;
    }

    int p;
    cin >> p;
    vi l(p);
    rep(i, 0, p) {
        cin >> l[i];
        l[i]--;
    }

    int q;
    cin >> q;
    vi r(q);
    rep(i, 0, q) {
        cin >> r[i];
        r[i]--;
    }
    
    if (p + q > n * (n - 1) / 2 + 1) {
        cout << "N\n";
        return;
    }

    if (n > 2 and p and q and l[0] != r[q - 1]) {
        cout << "N\n";
        return;
    }

    vector<vi> e(n, vi(n, true));
    rep(i, 0, n) {
        e[i][i] = false;
    }

    vi d(n, 0);
    rep(i, 1, p) {
        if (!e[l[i - 1]][l[i]]) {
            cout << "N\n";
            return;
        }
        e[l[i - 1]][l[i]] = false;
        e[l[i]][l[i - 1]] = false;
    }
    rep(i, 1, q) {
        if (!e[r[i - 1]][r[i]]) {
            cout << "N\n";
            return;
        }
        e[r[i - 1]][r[i]] = false;
        e[r[i]][r[i - 1]] = false;
    }

    vector<vi> graph(n);
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (e[i][j]) {
                graph[i].push_back(j);
                d[i]++;
            }
        }
    }

    int x = 0, y = 0;
    rep(i, 0, n) {
        x += d[i] % 2;
        y += d[i];
    }
    if (x != 0 and x != 2) {
        cout << "N\n";
        return;
    }
    
    
    int k = 0;
    vi vis(n, false);
    rep(i, 0, n) {
        if (d[i]) {
            k = dfs(i, graph, vis);
            break;
        }
    }
    if (k != accumulate(all(d), 0ll)) {
        cout << "N\n";
        return;
    }
    
    int s = p ? l[p - 1] : -1, t = q ? r[0] : -1;
    if (x == 0) {
        if (s != -1 and t != -1 and s != t) {
            cout << "N\n";
            return;
        }
        if (y and ((s != -1 and !vis[s]) or (t != -1 and !vis[t]))) {
            cout << "N\n";
            return;
        }
        if (s == -1 or t == -1) {
            cout << "Y\n";
            return;
        }
        if (y) {
            cout << "Y\n";
            return;
        }
        cout << "N\n";
        return;
    }
    
    if (s != -1 and t != -1 and s == t) {
        cout << "N\n";
        return;
    }
    if (y and ((s != -1 and !vis[s]) or (t != -1 and !vis[t]))) {
        cout << "N\n";
        return;
    }

    if ((s != -1 and d[s] % 2 == 0) or (t != -1 and d[t] % 2 == 0)) {
        cout << "N\n";
    }
    else {
        cout << "Y\n";
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
