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

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int mod_div(int a, int b) {
    return (a * mod_pow(b, MOD - 2)) % MOD;
}

int32_t main() {
    setup();
    int n, m;
    input(n, m);

    if (n == 2) {
        print(0);
        return 0;
    }

    int x = 1, y = 1, z = 1;
    range(i, 2, m + 1) {
        x = (x * i) % MOD;
    }
    range(i, 2, n) {
        y = (y * i) % MOD;
    }
    range(i, 2, m - n + 2) {
        z = (z * i) % MOD;
    }

    int res = ((n - 2) * mod_pow(2, n - 3)) % MOD;
    res = (res * mod_div(x, (y * z) % MOD)) % MOD;
    print(res);
}
