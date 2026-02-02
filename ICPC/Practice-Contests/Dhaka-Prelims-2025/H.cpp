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

void dfs(int u, vector<vi> &graph, vi &vis) {
    vis[u] = true;
    for (int v : graph[u]) {
        if (!vis[v]) {
            dfs(v, graph, vis);
        }
    }
}

void solve() {
	int n, m;
    cin >> n >> m;

    set<int> c;
    rep(i, 0, n) {
        int x;
        cin >> x;
        c.insert(x);
    }
    set<int> s = c;

    map<int, vector<pii>> v;
    rep(i, 0, m) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }

    while (!s.empty()) {
        set<int> ns;
        for (int x : s) {
            for (auto [y, z] : v[x]) {
                if (c.count(y) and !c.count(z)) {
                    ns.insert(z);
                }
            }
        }
        s = ns;
        c.insert(all(s));
    }
    cout << sz(c) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
