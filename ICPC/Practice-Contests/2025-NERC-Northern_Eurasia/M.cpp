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

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &match) {
    int x = 0;
    for (int v : graph[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u, graph, match);
        if (match[u] == -1 and match[v] == -1) {
            match[u] = v;
            match[v] = u;
        }
    }
}

void add(int u, vector<bool> &vis, vector<pair<int, int>> &res, vector<int> &match, vector<int> &other) {
    vector<int> v;
    while (!vis[u]) {
        vis[u] = true;
        v.push_back(u);
        u = other[u];

        if (vis[u]) {
            break;
        }
        vis[u] = true;
        v.push_back(u);
        if (match[u] == -1) {
            break;
        }
        u = match[u];
    }
    // cout << endl;
    // for (int i : v) {
    //     cout << i + 1 << ' ';
    // }
    // cout << endl;
    rep(i, 0, sz(v) / 2 - 1) {
        res.push_back({v[i], v[sz(v) - i - 2]});
    }
}

void solve() {
	int n;
    cin >> n;

    vector<int> a(2 * n);
    rep(i, 0, 2 * n) {
        cin >> a[i];
    }
    
    vector<vector<int>> graph(2 * n);
    rep(i, 0, 2 * n - 1) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vector<pair<int, int>> b(n, {-1, -1});
    rep(i, 0, 2 * n) {
        a[i]--;
        if (b[a[i]].first == -1) {
            b[a[i]].first = i;
        }
        else {
            b[a[i]].second = i;
        }
    }

    vector<int> other(2 * n);
    rep(i, 0, n) {
        other[b[i].first] = b[i].second;
        other[b[i].second] = b[i].first;
    }
    // rep(i, 0, 2 * n) {
    //     cout << other[i] + 1 << ' ';
    // }
    // cout << endl;
    
    vector<int> match(2 * n, -1);
    dfs(0, -1, graph, match);

    vector<bool> vis(2 * n, false);
    vector<pair<int, int>> res;
    rep(i, 0, 2 * n) {
        if (!vis[i] and match[i] == -1) {
            add(i, vis, res, match, other);
        }
    }
    rep(i, 0, 2 * n) {
        if (!vis[i]) {
            add(i, vis, res, match, other);
        }
    }

    cout << sz(res) << endl;
    for (auto [u, v] : res) {
        cout << u + 1 << ' ' << v + 1 << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
