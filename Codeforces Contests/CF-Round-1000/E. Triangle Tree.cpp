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

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &l, vector<int> &s, vector<int> &a, vector<int> &b) {
    s[u] = 1;
    b[u] = 0;
    for (int v : graph[u]) {
        if (v == p) {
            continue;
        }


        l[v] = l[u] + 1;
        dfs(v, u, graph, l, s, a, b);
        s[u] += s[v];
        a[u] += a[v] + s[v];
    }
    for (int v : graph[u]) {
        if (v != p) {
            b[u] += (a[v] + s[v]) * (a[u] - a[v] - s[v]);
            b[u] += a[v] + s[v];
        }
    }
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<vector<int>> graph(n);
        range(i, 0, n - 1)  {
            int u, v;
            input(u, v);
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> l(n, 0), s(n, 0), a(n, 0), b(n, 0);
        dfs(0, -1, graph, l, s, a, b);

        vector<int> x(n, 0);
        for (int i : l) {
            x[i]++;
        }

        int res = 0;
        res += accumulate(b.begin(), b.end(), 0);
        int y = 0, z = 0;
        range(i, 0, n) {
            res -= (z * i - y) * x[i];
            y += i * x[i];
            z += x[i];
        }
        res -= n * (n - 1) / 2;
        res += accumulate(s.begin(), s.end(), 0) - n;

        print(res);
    }
}
