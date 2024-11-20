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

int mod_pow(int a, int b, int m = MOD) {
    int res = 1;
    b %= MOD - 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }

        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int mod_div(int a, int b) {
    return (a * mod_pow(b, MOD - 2)) % MOD;
}

int nCr(int n, int r) {
    int res = 1;
    range(i, n - r + 1, n + 1) {
        res = (res * i) % MOD;
    }
    range(i, 1, r + 1) {
        res = mod_div(res, i) % MOD;
    }
    return res;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, c;
        input(n, c);

        n %= MOD - 1;
        int res = mod_pow(c, 5 * n * n);
        int k = mod_pow(c, n * n);
        int x = nCr(k, 4);
        int y = (nCr(k, 3) * 3) % MOD;
        int z = nCr(k, 2);

        int a, b;
        if (n % 2 == 0) {
            a = mod_pow(c, n * n / 2);
            b = mod_pow(c, n * n / 4);
        }
        else {
            a = mod_pow(c, (n - 1) * (n + 1) / 2 + 1);
            b = mod_pow(c, (n - 1) * (n + 1) / 4 + 1);
        }

        a = (a - b + MOD) % MOD;
        b = (b * (3 * x + 7 * y + 10 * z)) % MOD;
        a = (a * (3 * z)) % MOD;

        print((res - a - b + 2 * MOD) % MOD);
    }
}
