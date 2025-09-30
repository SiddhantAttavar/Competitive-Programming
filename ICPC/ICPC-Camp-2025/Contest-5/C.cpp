#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 998244353;

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int mod_div(int a, int b) {
    return a * mod_pow(b, MOD - 2) % MOD;
}

const int N = 1e4;
vector<int> fact(N + 1), inv_fact(N + 1);

int comb(int n, int r) {
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int inv_comb(int n, int r) {
    return inv_fact[n] * fact[r] % MOD * fact[n - r] % MOD;
}

void dfs1(int u, int p, vector<vector<int>> &graph, vector<int> &a, vector<int> &s) {
    for (int v : graph[u]) {
        if (v == p) {
            continue;
        }
        dfs1(v, u, graph, a, s);
        s[u] += s[v];
        a[u] = a[u] * a[v] % MOD * inv_fact[s[v]] % MOD;
    }
    a[u] = a[u] * fact[s[u] - 1] % MOD;
}

void dfs2(int u, int p, vector<vector<int>> &graph, vector<vector<int>> &dp, vector<int> &a, vector<int> &s) {
    int n = graph.size();
    for (int v : graph[u]) {
        if (v == p) {
            continue;
        }

        int x = 0;
        rep(i, 0, n - s[v] + 1) {
            dp[v][i] = x * comb(n - i - 1, s[v] - 1) % MOD;
            if (n - i - 1 >= s[v]) {
                x = (x + dp[u][i] * inv_comb(n - i - 1, s[v])) % MOD;
            }
        }
        dfs2(v, u, graph, dp, a, s);
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    fact[0] = 1;
    inv_fact[0] = 1;
    rep(i, 1, N + 1) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = mod_div(1, fact[i]);
    }

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    rep(i, 1, n) {
        int p;
        cin >> p;

        graph[p - 1].push_back(i);
    }

    vector<int> a(n, 1), s(n, 1);
    dfs1(0, -1, graph, a, s);

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = a[0];
    dfs2(0, -1, graph, dp, a, s);

    rep(i, 0, n) {
        cout << dp[i][i] << ' ';
    }
    cout << endl;
}
