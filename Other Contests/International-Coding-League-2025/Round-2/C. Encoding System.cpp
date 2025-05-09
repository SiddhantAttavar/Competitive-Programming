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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
        input(n, k);

        vector<int> dp(n + 2);
        int y = 0;
        dp[0] = 1;
        int x = 1;
        rep(i, 1, n + 1) {
            dp[i] = (20 * x) % MOD;
            y = y * 5 % MOD;
            y = (y + 5 * dp[i - 1]) % MOD;
            if (i - k - 1 >= 0) {
                y = (y - mod_pow(5, k + 1) * dp[i - k - 1] % MOD + MOD) % MOD;
            }
            x = (y + dp[i]) % MOD;
            // print(x);
        }

        print(x);
	}
}
