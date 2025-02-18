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
            res = res * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        vector<int> p(n + 1, 0);
        range(i, 0, n) {
            p[i + 1] = p[i] + (a[i] == 2);
        }

        int res = 0;
        int x = 0, y = 0;
        range(i, 0, n) {
            if (a[i] == 1) {
                x = (x + mod_pow(2, (MOD - 1 - p[i]) % MOD)) % MOD;
                y++;
            }
            else if (a[i] == 3) {
                res = (res + x * mod_pow(2, p[i])) % MOD;
                res = (res - y + MOD) % MOD;
            }
        }
        print(res);
    }
}
