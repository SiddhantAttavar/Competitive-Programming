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
	int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, -1));
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        graph[u - 1][v - 1] = i;
        graph[v - 1][u - 1] = i;
    }

    vector<int> res(m);
    if (m == n * (n - 1) / 2) {
        res[graph[0][1]] = 1;
        rep(j, 2, n) {
            res[graph[0][j]] = 2;
        }
        rep(i, 1, n) {
            rep(j, i + 1, n) {
                res[graph[i][j]] = 3;
            }
        }
    }
    else {
        int u = -1;
        rep(i, 0, n) {
            if (count(graph[i].begin(), graph[i].end(), -1) > 1) {
                u = i;
                break;
            }
        }
        rep(i, 0, n) {
            rep(j, i + 1, n) {
                if (graph[i][j] != -1) {
                    res[graph[i][j]] = 2;
                }
            }
        }

        rep(v, 0, n) {
            if (graph[u][v] != -1) {
                res[graph[u][v]] = 1;
            }
        }
    }

    int k = *max_element(res.begin(), res.end());
    cout << k << endl;
    rep(i, 0, m) {
        cout << res[i] << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
