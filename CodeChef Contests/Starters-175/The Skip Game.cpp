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

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int mod_div(int a, int b) {
    return a * mod_pow(b, MOD - 2) % MOD;
}

const int N = 2e5;
int fact[N + 1];

int nCr(int n, int r) {
    if (r > n) {
        return 0;
    }
    return mod_div(fact[n], fact[r] * fact[n - r] % MOD);
}

int32_t main() {
    fact[0] = 1;
    rep(i, 1, N + 1) {
        fact[i] = i * fact[i - 1] % MOD;
    }
    setup(); int tc; input(tc); while (tc--) {
        int n, k;
        input(n, k);

        vector<int> a(n);
        arrput(a);

        int x = n - 1;
        rep(i, 0, n - 1) {
            x -= a[i] == -1;
        }

        int res = 0;
        rep(p, 0, k + 2) {
            res = (res + nCr(x, p) * nCr(n - x - 1, k + 1 - p)) % MOD;
        }
        if (k < n) {
            res = res * fact[n - k - 1] % MOD;
        }
        res = res * k % MOD;

        int z = 0;
        rep(p, 0, k) {
            z = (z + nCr(x, p) * nCr(n - x - 1, k - 1 - p)) % MOD;
        }
        z = z * fact[n - k] % MOD;

        res = (res + z) % MOD;
        res = res * fact[n - x] % MOD;
        print(res);
    }
}
