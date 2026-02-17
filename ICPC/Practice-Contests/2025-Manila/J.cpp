#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int other(vector<vi> &graph, int u, vi s) {
    if (sz(graph[u]) - sz(s) >= 2) {
        return 2;
    }
    set<int> res(all(graph[u]));
    for (int i : s) {
        res.erase(i);
    }
    return sz(res);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> graph(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;

        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int res = 0;
    rep(i, 0, n) {
        if (sz(graph[i]) <= 1) {
            continue;
        }
        if (sz(graph[i]) >= 4) {
            res++;
            continue;
        }
        if (sz(graph[i]) == 2) {
            int u = graph[i][0], v = graph[i][1];
            int s = other(graph, u, {i, v}), t = other(graph, v, {i, u});
            res += min(s, t) >= 2;
        }
        else {
            int u = graph[i][0], v = graph[i][1], w = graph[i][2];
            int s = other(graph, u, {i, v, w}), t = other(graph, v, {i, u, w}), r = other(graph, w, {i, u, v});
            res += min(s, t) or min(t, r) or min(r, s);
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
