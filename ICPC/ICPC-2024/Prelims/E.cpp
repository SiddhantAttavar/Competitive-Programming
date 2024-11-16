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

map<pair<pair<int, int>, int>, int> memo;

int f(int l, int r, int k) {
    // print(l, r, k);
    if (r == 0) {
        return 0;
    }

    pair<pair<int, int>, int> key = {{l, r}, k};
    if (memo.count(key)) {
        return memo[key];
    }
    int x = 0;
    while ((1ll << (x + 1)) <= r) {
        x++;
    }

    int n = r - l + 1 - (1ll << x);
    if ((1ll << x) & l) {
        n = r - l + 1;
    }
    int p = r - n + 1;
    int a = mod_pow(10, x);
    int res = mod_div((a * (mod_pow(10, n * k) - 1)) % MOD, (mod_pow(10, k) + MOD - 1) % MOD);
    if ((1ll << x) & l) {
        l -= 1ll << x;
        r -= 1ll << x;
        res = (res + f(l, r, k)) % MOD;
    }
    else {
        res = (res + f(l, l + (1ll << x) - 1, k)) % MOD;
        r -= 1ll << x;
        res = (res + f(l, r, k) * mod_pow(10, (1ll << x) * k)) % MOD;
    }
    return memo[key] = res;
}

int solve(int n) {
    if (n == 1) {
        return 1;
    }

    int x = 0;
    while ((1ll << (x + 1)) <= n) {
        x++;
    }

    int l = (x + 1) * (n - (1ll << x) + 1);
    return (mod_pow(10, l) * solve((1ll << x) - 1) + f(1ll << x, n, x + 1)) % MOD;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        print(solve(n));
    }
}
