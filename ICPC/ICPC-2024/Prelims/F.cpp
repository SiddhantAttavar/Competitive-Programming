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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int cost(vector<int> a, vector<int> b) {
    set<int> c(a.begin(), a.end());
    int res = 0;
    for (int i : b) {
        res += c.count(i);
    }
    return res;
}

int32_t main() {
    setup();
    int n;
    input(n);

    vector<int> c(n);
    arrPut(c);

    vector<vector<int>> v(n);
    range(i, 0, n) {
        v[i].resize(c[i]);
        arrPut(v[i]);
    }

    vector<int> f(n, 0), g(n, 0), h(n, 0);
    g[0] = h[0] = h[1] = 1e18;
    g[1] = cost(v[0], v[1]);
    range(i, 2, n) {
        int x = cost(v[i], v[i - 1]), y = cost(v[i], v[i - 2]);
        f[i] = min(f[i - 1], g[i - 1]);
        g[i] = min({f[i - 2] + x + y, g[i - 2] + x, h[i - 2] + x});
        h[i] = min(g[i - 1] + y, h[i - 1]);
    }

    print(min(g[n - 1], h[n - 1]));
}
