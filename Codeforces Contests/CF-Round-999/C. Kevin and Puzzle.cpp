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

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        if (n == 1) {
            print(1 + (a[0] == 0));
            continue;
        }

        vector<int> dp(n, 0);
        dp[0] = a[0] == 0;
        if (a[1] == 1) {
            dp[1] = 1;
        }
        else if (a[1] == 0 and a[0] == 0) {
            dp[1] = 1;
        }
        range(i, 2, n) {
            if (a[i] == a[i - 1]) {
                dp[i] = dp[i - 1];
            }
            if (a[i] == a[i - 2] + 1) {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }
        print((dp[n - 1] + dp[n - 2]) % MOD);
    }
}
