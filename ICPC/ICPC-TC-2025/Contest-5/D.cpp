#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cmb(int a, int b, int n) {
    return n * a + b;
}

void rook(int x, int y, vector<vi> &graph, vector<string> &a) {
    int n = sz(a), k = cmb(x, y, n);
    rep(i, 0, n) {
        if (i != x and a[i][y] != '.') {
            graph[cmb(i, y, n)].push_back(k);
        }
    }
    rep(j, 0, n) {
        if (j != y and a[x][j] != '.') {
            graph[cmb(x, j, n)].push_back(k);
        }
    }
}

void bishop(int x, int y, vector<vi> &graph, vector<string> &a) {
    int n = sz(a), k = cmb(x, y, n);
    rep(i, 1, n) {
        if (x - i >= 0 and y - i >= 0 and a[x - i][y - i] != '.') {
            graph[cmb(x - i, y - i, n)].push_back(k);
        }
    }
    rep(i, 1, n) {
        if (x + i < n and y + i < n and a[x + i][y + i] != '.') {
            graph[cmb(x + i, y + i, n)].push_back(k);
        }
    }
    rep(i, 1, n) {
        if (x - i >= 0 and y + i < n and a[x - i][y + i] != '.') {
            graph[cmb(x - i, y + i, n)].push_back(k);
        }
    }
    rep(i, 1, n) {
        if (x + i < n and y - i >= 0 and a[x + i][y - i] != '.') {
            graph[cmb(x + i, y - i, n)].push_back(k);
        }
    }
}

void knight(int x, int y, vector<vi> &graph, vector<string> &a) {
    int n = sz(a), k = cmb(x, y, n);
    vector<pair<int, int>> l = {
        {x - 2, y - 1},
        {x - 1, y - 2},
        {x + 1, y - 2},
        {x + 2, y - 1},
        {x - 2, y + 1},
        {x - 1, y + 2},
        {x + 1, y + 2},
        {x + 2, y + 1}
    };
    for (auto [i, j] : l) {
        if (min(i, j) >= 0 and max(i, j) < n and a[i][j] != '.') {
            graph[cmb(i, j, n)].push_back(k);
        }
    }
}

void king(int x, int y, vector<vi> &graph, vector<string> &a) {
    int n = sz(a), k = cmb(x, y, n);
    vector<pair<int, int>> l = {
        {x - 1, y - 1}, {x - 1, y}, {x - 1, y + 1},
        {x, y - 1}, {x, y + 1},
        {x + 1, y - 1}, {x + 1, y}, {x + 1, y + 1}
    };
    for (auto [i, j] : l) {
        if (min(i, j) >= 0 and max(i, j) < n and a[i][j] != '.') {
            graph[cmb(i, j, n)].push_back(k);
        }
    }
}

void dfs(int u, vector<vi> &graph, vector<bool> &vis, vector<pair<int, int>> &l) {
    vis[u] = true;
    for (int v : graph[u]) {
        if (!vis[v]) {
            l.push_back({u, v});
            dfs(v, graph, vis, l);
        }
    }
}

void solve() {
    int n;
    char d;
    cin >> n >> d;

    vector<string> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vector<vi> graph(n * n);
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (a[i][j] == 'R') {
                rook(i, j, graph, a);
            }
            else if (a[i][j] == 'Q') {
                rook(i, j, graph, a);
                bishop(i, j, graph, a);
            }
            else if (a[i][j] == 'B') {
                bishop(i, j, graph, a);
            }
            else if (a[i][j] == 'N') {
                knight(i, j, graph, a);
            }
            else if (a[i][j] == 'K') {
                king(i, j, graph, a);
            }
        }
    }

    vector<bool> vis(n * n, false);
    vector<pair<int, int>> l;
    int u = -1, c = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (a[i][j] != '.') {
                u = cmb(i, j, n);
                c++;
            }
        }
    }
    dfs(u, graph, vis, l);
    if (accumulate(vis.begin(), vis.end(), 0ll) != c) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    reverse(l.begin(), l.end());
    for (auto [u, v] : l) {
        cout << (v / n + 1) << ' ' << (v % n + 1) << ' ';
        cout << (u / n + 1) << ' ' << (u % n + 1) << '\n';
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
