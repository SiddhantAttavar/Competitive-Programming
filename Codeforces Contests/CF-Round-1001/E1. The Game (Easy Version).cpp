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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

void dfs(int u, int p, vector<vector<int>> &graph, vector<vector<int>> &par, vector<int> &l) {
    for (int v : graph[u]) {
        if (v == p) {
            continue;
        }

        par[v][0] = u;
        l[v] = l[u] + 1;
        range(i, 1, 20) {
            if (par[v][i - 1] != -1) {
                par[v][i] = par[par[v][i - 1]][i - 1];
            }
        }
        dfs(v, u, graph, par, l);
    }
}

int lca(int u, int v, vector<vector<int>> &par, vector<int> &l) {
    if (u == -1) {
        return v;
    }
    if (v == -1) {
        return u;
    }

    if (l[u] < l[v]) {
        swap(u, v);
    }

    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != -1 and l[par[u][i]] >= l[v]) {
            u = par[u][i];
        }
    }
    
    if (u == v) {
        return u;
    }

    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> w(n);
        arrput(w);

        vector<vector<int>> graph(n);
        range(i, 0, n - 1) {
            int u, v;
            input(u, v);

            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        vector<pair<int, int>> v(n);
        range(i, 0, n) {
            v[i] = {w[i], i};
        }
        sort(v.begin(), v.end());

        vector<vector<int>> par(n, vector<int>(20, -1));
        vector<int> l(n, 0);
        dfs(0, -1, graph, par, l);

        int a = -1, b = -1, res = -1, r = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int na = a, nb = b;
            while (v[r].first > v[i].first) {
                int u = v[r].second;
                if (lca(b, u, par, l) == u) {
                    nb = lca(nb, u, par, l);
                }
                else {
                    na = lca(na, u, par, l);
                }
                r--;
            }
            a = na, b = nb;

            int u = v[i].second;
            if (lca(b, u, par, l) != u and lca(a, u, par, l) == u) {
                res = u;
                break;
            }
        }
        print(res + 1);
    }
}
