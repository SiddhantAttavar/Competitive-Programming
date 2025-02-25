#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int cycle(vector<int> &v, vector<int> &c, vector<int> &d) {
    // arrprint(v);
    if (v.size() == 1) {
        return min(c[v[0]], d[v[0]]);
    }
    if (v.size() == 2) {
        return min({c[v[0]] + c[v[1]], c[v[0]] + d[v[1]], d[v[0]] + c[v[1]]});
    }

    int n = v.size();
    vector<int> dp(n);
    dp[0] = c[v[0]];
    dp[1] = c[v[1]] + c[v[0]];
    rep(i, 2, n) {
        dp[i] = c[v[i]] + min(dp[i - 1], d[v[i - 1]] + dp[i - 2]);
    }
    // arrprint(dp);

    int res = min(dp[n - 1], dp[n - 2] + d[v[n - 1]]);
    dp[0] = c[v[0]];
    dp[1] = c[v[1]] + min(c[v[0]], d[v[0]]);
    rep(i, 2, n) {
        dp[i] = c[v[i]] + min(dp[i - 1], d[v[i - 1]] + dp[i - 2]);
    }
    // arrprint(dp);
    return min(res, dp[n - 1]);
}

int perm(int n, vector<int> &a, vector<int> &c) {
    vector<int> d(n, 0);
    vector<bool> vis(n, false);
    int res = 0;
    rep(i, 0, n) {
        if (vis[i]) {
            continue;
        }

        vector<int> v = {i};
        int u = a[i];
        vis[i] = true;
        while (u != i) {
            v.push_back(u);
            vis[u] = true;
            u = a[u];
        }
        res += cycle(v, c, d);
    }
    return res;
}

void dfs(int u, vector<vector<int>> &graph, vector<int> &x, vector<int> &y, vector<int> &c, vector<int> &a) {
    if (a[u] != u) {
        x[u] = c[u];
    }
    for (int v : graph[u]) {
        dfs(v, graph, x, y, c, a);
        x[u] += min(x[v], y[v]);
        y[u] += x[v];
    }
    // print(u, 'u', x[u], y[u]);
    // arrprint(graph[u]);
}

int32_t main() {
    setup();

    int n;
    input(n);

    vector<int> a(n), c(n);
    arrput(a);
    arrput(c);
    rep(i, 0, n) {
        a[i]--;
    }

    set<int> s(a.begin(), a.end());
    if (s.size() == n) {
        print(perm(n, a, c));
        return 0;
    }

    vector<bool> vis(n, false), in_cycle(n, false);
    int t = 0;
    rep(i, 0, n) {
        if (vis[i]) {
            continue;
        }

        int u = a[i];
        set<int> s = {i};
        while (!vis[u]) {
            vis[u] = true;
            s.insert(u);
            u = a[u];
        }

        if (!s.count(u)) {
            continue;
        }

        in_cycle[u] = true;
        u = a[u];
        while (!in_cycle[u]) {
            in_cycle[u] = true;
            u = a[u];
        }
    }

    vector<vector<int>> rev_graph(n);
    rep(i, 0, n) {
        if (!in_cycle[i]) {
            rev_graph[a[i]].push_back(i);
        }
    }

    vector<int> x(n, 0), y(n, 0);
    rep(i, 0, n) {
        if (in_cycle[i]) {
            dfs(i, rev_graph, x, y, c, a);
        }
    }

    vector<bool> done(n, false);
    int res = 0;
    rep(i, 0, n) {
        if (!in_cycle[i] or done[i]) {
            continue;
        }

        vector<int> v = {i};
        int u = a[i];
        done[i] = true;
        while (!done[u]) {
            done[u] = true;
            v.push_back(u);
            u = a[u];
        }

        res += cycle(v, x, y);
    }
    // rep(i, 0, n) {cout << i + 1 << ' ';} cout << endl;
    // arrprint(x);
    // arrprint(y);
    print(res);
}
