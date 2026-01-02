#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 5000;

void dfs(int u, vector<vi> &graph, vector<bool> &vis, vi &l) {
    vis[u] = true;
    for (int v : graph[u]) {
        if (!vis[v]) {
            dfs(v, graph, vis, l);
        }
    }
    l.push_back(u);
}

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    vector<vector<int>> graph(n), revgraph(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }

    vector<bool> vis(n, false);
    vi l;
    rep(i, 0, n) {
        if (!vis[i]) {
            dfs(i, graph, vis, l);
        }
    }

    vector<bitset<N>> dp1(n), dp2(n);
    for (int u : l) {
        for (int v : graph[u]) {
            dp1[u] |= dp1[v];
        }
        dp1[u][u] = true;
    }

    reverse(l.begin(), l.end());
    for (int u : l) {
        for (int v : revgraph[u]) {
            dp2[u] |= dp2[v];
        }
        dp2[u][u] = true;
    }

    int x = 0, y = 0, z = 0;
    rep(i, 0, n) {
        x += dp1[i].count() - 1 >= n - a;
        y += dp1[i].count() - 1 >= n - b;
        z += dp2[i].count() > b;
    }
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
