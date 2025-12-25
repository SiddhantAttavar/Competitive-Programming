#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<int, int> dfs(int u, int p, vector<vi> &graph, vi &s) {
    pair<int, int> res = {-1, -1};
    int n = sz(graph), x = (n - 1) * (n - 2) / 2;
    for (int v : graph[u]) {
        if (v != p) {
            res = max(res, dfs(v, u, graph, s));
            s[u] += s[v];
            x -= s[v] * (s[v] - 1) / 2;
        }
    }
    x -= (n - s[u]) * (n - s[u] - 1) / 2;
    return max(res, {x, u});
}

void solve() {
    int n;
    cin >> n;

    n++;
    vector<vi> graph(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vi s(n, 1);
    auto [x, u] = dfs(0, -1, graph, s);

    vi t(n, 1);
    dfs(u, -1, graph, t);

    vi l;
    for (int v : graph[u]) {
        l.push_back(t[v]);
    }
    sort(l.begin(), l.end());
    
    cout << x << ' ';
    if (sz(l) >= 2) {
        x -= l[sz(l) - 1] * l[sz(l) - 2];
    }
    cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
