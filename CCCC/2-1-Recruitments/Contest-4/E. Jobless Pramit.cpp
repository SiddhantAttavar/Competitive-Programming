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
const int MOD = 998244353;

int32_t main() {
    setup();
    int n;
    input(n);

    vector<int> a(n), b(n);
    arrput(a);
    arrput(b);

    int m;
    input(m);

    vector<int> c(m), d(m);
    arrput(c);
    arrput(d);

    map<int, int> x, y;
    range(i, 0, n) {
        x[a[i]] = b[i];
    }
    range(i, 0, m) {
        y[c[i]] = d[i];
    }

    int res = 1;
    for (pair<int, int> p : x) {
        if (!y.count(p.first) or y[p.first] != p.second) {
            res *= 2;
            res %= MOD;
        }
    }
    for (pair<int, int> p : y) {
        if (!x.count(p.first) or x[p.first] < p.second) {
            res = 0;
        }
    }
    print(res);
}
