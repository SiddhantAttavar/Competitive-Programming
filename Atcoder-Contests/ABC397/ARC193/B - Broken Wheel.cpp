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
const int MOD = 998244353;

int32_t main() {
    setup();

    int n;
    input(n);

    string s;
    input(s);

    int x = 0;
    for (char c : s) {
        x += c == '1';
    }

    vector<vector<int>> dp(n - 1, vector<int>(x + 1, 1));
    dp[0][0] = 3;
    if (s[0] == '1') {
        dp[0][1] = 3;
    }
    rep(i, 1, n - 1) {
        dp[i][0] = 2 * dp[i - 1][0] % MOD;
        rep(j, 1, x + 1) {
            dp[i][j] = 2 * dp[i - 1][j] % MOD;
            if (s[i] == '1') {
                dp[i][j] = (dp[i][j] + 2 * dp[i - 1][j - 1]) % MOD;
            }
        }
    }
    // rep(i, 0, n - 1) {
    //     arrprint(dp[i]);
    // }

    int res = accumulate(dp[n - 2].begin(), dp[n - 2].end(), 0ll) % MOD;
    if (s[n - 1] == '1') {
        res = (res + accumulate(dp[n - 2].begin(), dp[n - 2].end() - 1, 0ll)) % MOD;
    }
    print(res);
}
