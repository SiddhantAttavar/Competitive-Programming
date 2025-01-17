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

void dfs1(int u, int p, vector<vector<int>> &graph, vector<int> &l, vector<int> &s, vector<int> &a, vector<bool> &b) {
    l[u] += graph[u].size() <= 1;
    b[u] = graph[u].size() <= 1;
    s[u] = 1;
    for (int v : graph[u]) {
        if (v != p) {
            dfs1(v, u, graph, l, s, a, b);
            l[u] += l[v];
            s[u] += s[v];
            a[u] += a[v];
        }
        b[u] = b[u] or graph[v].size() <= 1;
    }
    a[u] += b[u];
}

int dfs2(int u, int p, int p2, vector<vector<int>> &graph, vector<int> &l, vector<int> &s, vector<int> &a, vector<bool> &b) {
    int res = 0;
    if (p != -1 and b[p]) {
        res = (s[0] - s[u]) - (a[0] - a[u]);
    }
    for (int v : graph[u]) {
        if (v != p and b[v]) {
            res += s[v] - a[v];
        }
    }
    if (graph[u].size() <= 1) {
        res = s[0] - l[0];
    }
    for (int v : graph[u]) {
        if (v != p) {
            res += dfs2(v, u, p, graph, l, s, a, b);
        }
    }
    return res;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<vector<int>> graph(n);
        range(i, 0, n - 1) {
            int u, v;
            input(u, v);

            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        vector<int> l(n, 0), s(n, 0), a(n, 0);
        vector<bool> b(n, false);
        dfs1(0, -1, graph, l, s, a, b);
        print(dfs2(0, -1, -1, graph, l, s, a, b));
    }
}
