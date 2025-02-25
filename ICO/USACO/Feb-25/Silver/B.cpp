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

int dfs(int u, vector<set<int>> &graph, vector<int> &d, vector<int> &s) {
    s[u] = graph[u].size() == 0;
    for (int v : graph[u]) {
        d[v] = d[u] + 1;
        s[u] += dfs(v, graph, d, s);
    }
    return s[u];
}

int32_t main() {
    setup();

    int n;
    input(n);

    vector<int> p(n);
    arrput(p);

    vector<set<int>> graph(n + 1);
    rep(i, 0, n) {
        graph[p[i]].insert(i + 1);
    }
    p.insert(p.begin(), -1);

    vector<int> d(n + 1, 0), s(n + 1, 0);
    int m = dfs(0, graph, d, s);

    vector<int> a(m);
    arrput(a);

    vector<int> t(n + 1, 0);
    for (int u : a) {
        while (u != -1 and s[u] - t[u] == 1) {
            if (p[u] != -1) {
                t[p[u]] += t[u];
            }
            u = p[u];
        }
        if (u == -1) {
            print(0);
        }
        else {
            print(d[u] + 1);
            t[u]++;
        }
    }
}
