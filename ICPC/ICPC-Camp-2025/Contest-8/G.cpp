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

vector<int> basis(30, 0);
void insert(int x) {
    for (int i = 29; i >= 0; i--) {
        if (!(x >> i & 1)) {
            continue;
        }
        x ^= basis[i];
    }
    for (int i = 29; i >= 0; i--) {
        if (x >> i & 1) {
            basis[i] = x;
            break;
        }
    }
}

void dfs(int u, vector<vector<pair<int, int>>> &graph, vector<vector<int>> &tree, vector<int> &c) {
    for (auto [v, w] : graph[u]) {
        if (c[v] == -1) {
            c[v] = c[u] ^ w;
            tree[u].push_back(v);
            dfs(v, graph, tree, c);
        }
        else {
            insert(c[u] ^ c[v] ^ w);
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> graph(n);
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }

    vector<vector<int>> tree(n);
    vector<int> c(n, -1);
    c[0] = 0;
    dfs(0, graph, tree, c);

    vector<int> v(n + 1, 0);
    vector<vector<int>> p(n + 1, vector<int>(30, 0));
    rep(i, 0, n) {
        p[i + 1] = p[i];
        v[i + 1] = v[i] ^ c[i];
        rep(j, 0, 30) {
            p[i + 1][j] += c[i] >> j & 1;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        // int res = 0;
        // rep(i, l, r + 1) {
        //     rep(j, i + 1, r + 1) {
        //         int x = c[i] ^ c[j];
        //         for (int k = 29; k >= 0; k--) {
        //             if (!(x >> k & 1)) {
        //                 x ^= basis[k];
        //             }
        //         }
        //         res ^= x;
        //     }
        // }
        // cout << res << endl;

        int res = 0;
        if ((r - l) % 2) {
            res = v[r + 1] ^ v[l];
        }
        vector<int> b(30, false);
        for (int j = 29; j >= 0; j--) {
            int x = p[r + 1][j] - p[l][j];
            int y = r - l + 1 - x;
            int z = x * (x - 1) / 2 + y * (y - 1) / 2;
            if ((z & 1) ^ b[j]) {
                res ^= basis[j];
                for (int k = j - 1; k >= 0; k--) {
                    b[k] ^= basis[j] >> k & 1;
                }
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
