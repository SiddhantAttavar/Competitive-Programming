#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

vi dfs(int u, int p, int d, vector<vi> &graph) {
    if (graph[u].empty()) {
        return {0, 1};
    }

    vi a = {0};
    for (int v : graph[u]) {
        if (v == p) {
            return {(int) -1e18};
        }

        vi b = dfs(v, u, d, graph);
        vi c(sz(a) + sz(b) - 1, 0);
        rep(i, 0, sz(a)) {
            rep(j, 0, sz(b)) {
                c[i + j] = max(c[i + j], a[i] + b[j]);
            }
        }
        a = c;
    }
    a.insert(a.begin(), 0);
    return a;
}

void solve() {
    int m, n, d;
    cin >> m >> n >> d;

    vector<pii> a(n);
    rep(i, 0, n) {
        cin >> a[i].first >> a[i].second;
    }

    vector<array<int, 3>> b(d);
    rep(i, 0, d) {
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    }

    vector<vi> graph(n + d);
    vi v(n + d, true);
    rep(i, 0, d) {
        rep(j, 0, d) {
            if (i != j and dist({b[i][0], b[i][1]}, {b[j][0], b[j][1]}) <= b[i][2] * b[i][2]) {
                graph[i].push_back(j);
                v[j] = false;
            }
        }
        rep(j, 0, n) {
            if (dist({b[i][0], b[i][1]}, a[j]) <= b[i][2] * b[i][2]) {
                graph[i].push_back(j + d);
                v[j + d] = false;
            }
        }
    }
    vi dp = {0};
    rep(u, 0, n + d) {
        if (!v[u]) {
            continue;
        }
        vi a = dfs(u, -1, d, graph);
        vi ndp(sz(a) + sz(dp) - 1, 0);
        rep(i, 0, sz(a)) {
            rep(j, 0, sz(dp)) {
                ndp[i + j] = max(ndp[i + j], a[i] + dp[j]);
            }
        }
        dp = ndp;
    }
    int res = 0;
    rep(i, 0, min(m, n) + 1) {
        res = max(res, dp[i]);
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
