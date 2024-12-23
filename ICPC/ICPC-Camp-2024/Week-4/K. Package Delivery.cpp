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

signed main() {
    // code
    int n;
    cin >> n;
    if (n == 1) {
        print(2);
        return 0;
    }
    if (n == 2) {
        print(24);
        return 0;
    }
    vector<int> f(n + 1), g(n + 1), h(n + 1);
    f[1] = 1;
    if (n >= 2) {
        f[2] = 6;
        g[2] = 2;
    }
    if (n >= 3) {
        f[3] = 20;
        g[3] = 4;
        h[3] = 1;
    }
    range(i, 4, n + 1) {
        h[i] = (2 * h[i - 1]) % MOD;
        g[i] = (2 * f[i - 2] + 2 * h[i]) % MOD;
        f[i] = (2 * f[i - 1] + 2 * g[i]) % MOD;
    }
    int res = 0;
    if (n == 3) {
        res += 16 * f[n - 2];
        res %= MOD;
    }
    else if (n > 3) {
        res += 8 * f[n - 2];
        res += 8 * h[n];
        res += 8 * f[n - 2];
        res += 8 * h[n];
        res %= MOD;
    }
    range(k,3,n-1) {
        res = (res + 16 * ((h[k + 1] * f[n - k]) % MOD)) % MOD;
    }
    res += 4 * f[n];
    res %= MOD;
    cout << res << endl;
}
