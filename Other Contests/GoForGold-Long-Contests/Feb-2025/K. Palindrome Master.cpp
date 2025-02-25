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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup();

    string s;
    input(s);

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, false));
    range(i, 0, n) {
        dp[i][i] = true;
    }
    range(i, 0, n - 1) {
        dp[i][i + 1] = s[i] == s[i + 1];
    }
    range(l, 3, n + 1) {
        range(i, 0, n - l + 1) {
            int j = i + l - 1;
            dp[i][j] = dp[i + 1][j - 1] and s[i] == s[j];
        }
    }

    range(i, 0, n - 1) {
        dp[i][i + 1] += dp[i][i] + dp[i + 1][i + 1];
    }
    range(l, 3, n + 1) {
        range(i, 0, n - l + 1) {
            int j = i + l - 1;
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }

    int q;
    input(q);
    while (q--) {
        int l, r;
        input(l, r);

        l--;
        r--;
        print(dp[l][r]);
    }
}
