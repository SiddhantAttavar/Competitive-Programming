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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n);
    rep(i, 0, n) {
        cin >> c[i];
    }

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        
        u--;
        v--;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    const int inf = 1e9;
    vector<vector<int>> a(n, vector<int>(n, inf)), b(n, vector<int>(n, inf));
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == j) {
                a[i][j] = 0;
            }
            if (!graph[i][j]) {
                continue;
            }
            if (c[i] == c[j]) {
                a[i][j] = 1;
            }
            else {
                b[i][j] = 1;
            }
        }
    }
    rep(k, 0, n) {
        vector<vector<int>> na = a, nb = b;
        rep(i, 0, n) {
            rep(j, 0, n) {
                na[i][j] = min({na[i][j], a[i][k] + a[k][j], b[i][k] + b[k][j]});
                nb[i][j] = min({nb[i][j], a[i][k] + b[k][j], b[i][k] + a[k][j]});
            }
        }
        a = na;
        b = nb;
    }

    int res = 0;
    rep(u, 0, n) {
        rep(v, 0, n) {
            rep(i, 0, k + 1) {
                res = max(res, min(a[u][v] + i, b[u][v] + k - i));
            }
        }
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
