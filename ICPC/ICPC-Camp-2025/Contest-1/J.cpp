#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7;

void dfs(int u, vector<vector<int>> &tree, vector<int> &f, vector<int> &g) {
    if (tree[u].empty()) {
        f[u] = 1;
        g[u] = 1;
        return;
    }

    vector<int> a, b;
    for (int v : tree[u]) {
        dfs(v, tree, f, g);
        a.push_back(f[v]);
        b.push_back(g[v]);
    }

    if (a.size() == 1) {
        f[u] = (a[0] + b[0]) % MOD;
        g[u] = b[0];
        return;
    }

    vector<int> p(a.size()), s(a.size());
    p[0] = a[0];
    rep(i, 1, (int) a.size()) {
        p[i] = p[i - 1] * a[i] % MOD;
    }
    s.back() = a.back();
    for (int i = a.size() - 2; i >= 0; i--) {
        s[i] = s[i + 1] * a[i] % MOD;
    }

    g[u] = (b[0] * s[1] % MOD + b.back() * p[p.size() - 2] % MOD) % MOD;
    rep(i, 1, (int) a.size() - 1) {
        g[u] = (g[u] + p[i - 1] * s[i + 1] % MOD * b[i]) % MOD;
    }
    f[u] = (g[u] + s[0]) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    rep(i, 0, n - 1) {
        int p;
        cin >> p;

        tree[p - 1].push_back(i + 1);
    }

    vector<int> f(n, 0), g(n, 0);
    dfs(0, tree, f, g);
    cout << f[0] << endl;
}
