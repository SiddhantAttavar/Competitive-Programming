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

int square(int x) {
    x %= MOD;
    return mod_div((x * (x + 1) % MOD) * (2 * x + 1) % MOD, 6);
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, k;
        input(n, k);

        int s = 2;
        while (s * s <= n) {
            s++;
        }

        int res = 0;
        rep(p, 2, min(k + 1, s)) {
            int x = n;
            int y = 0;
            while(x) {
                y = (y * p + (x % p)) % MOD;
                x /= p;
            }
            res = (res + y) % MOD;
        }

        while (s <= k) {
            int l = s, r = min(k, n), t = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (n / s == n / m) {
                    t = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            int x = n / s;
            if (x == 0) {
                res = (res + n * ((k - s + 1) % MOD)) % MOD;
                break;
            }
            // print(x, s, t, res);
            // assert(x == n / t and (t == k or x != n / (t + 1)));
            int y = (t - s + 1) % MOD, z = (s + t) % MOD;
            res = (res + x * y) % MOD;
            res = (res + n * mod_div((y * z % MOD), 2) % MOD) % MOD;
            res = (res - x * (square(t) - square(s - 1) + MOD) % MOD + MOD) % MOD;
            s = t + 1;
        }
        print(res);
    }
}
