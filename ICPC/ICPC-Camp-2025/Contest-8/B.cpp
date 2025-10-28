#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void dfs(int u, vector<vector<pair<int, int>>> &tree, vector<pair<int, int>> &par) {
    for (auto [v, w] : tree[u]) {
        if (v != par[u].first) {
            par[v] = {u, w};
            dfs(v, tree, par);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, pair<int, int>>> edges(n - 1);
    vector<vector<pair<int, int>>> tree(n);
    rep(i, 0, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        
        u--;
        v--;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
        edges[i] = {w, {u, v}};
    }

    sort(edges.begin(), edges.end());

    vector<int> a(n);
    rep(i, 0, n) {
        a[i] = i;
    }
    vector<vector<int>> l(n);
    UF d(n);
    for (auto [w, p] : edges) {
        int u = d.find(p.first), v = d.find(p.second);
        d.join(u, v);
        l[max(a[u], a[v])].push_back(w);
        a[d.find(u)] = min(a[u], a[v]);
    }

    vector<pair<int, int>> par(n, {-1, 0});
    dfs(0, tree, par);
    
    vector<bool> vis(n, false);
    multiset<int> m = {0};
    int res = 0;
    vis[0] = true;
    cout << res << endl;
    rep(i, 1, n) {
        for (int w : l[i]) {
            res += w;
            m.insert(w);
            if (m.size() > k) {
                res -= *m.begin();
                m.erase(m.begin());
            }
        }
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; while (t--) {
        solve();
    }
}
