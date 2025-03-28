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

int dfs(int u, int p, vector<vector<int>> &graph, vector<int> &l, vector<int> &r, vector<int> &a) {
    int res = 0;
    for (int v : graph[u]) {
        if (v != p) {
            res += dfs(v, u, graph, l, r, a);
            a[u] = max(a[u], a[v]);
        }
    }
    a[u] = min(max(a[u], l[u]), r[u]);
    for (int v : graph[u]) {
        if (v != p) {
            res += max(0ll, a[v] - a[u]);
        }
    }
    return res;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> l(n), r(n);
        range(i, 0, n) {
            input(l[i], r[i]);
        }

        vector<vector<int>> graph(n);
        range(i, 0, n - 1) {
            int u, v;
            input(u, v);

            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        vector<int> a(n);
        print(dfs(0, -1, graph, l, r, a) + a[0]);
    }
}
