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

int32_t main() {
    int N = 4e6;
    vector<int> v;
    int x = 2;
    while ((1ll << x) * (x - 1) <= N) {
        v.push_back((1ll << x) * (x - 1));
        x++;
    }

    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i : v) {
        vector<int> ndp(N + 1, 0);
        vector<int> a(i, 0);
        range(j, 0, N + 1) {
            ndp[j] = (dp[j] + a[j % i]) % MOD;
            a[j % i] += dp[j];
        }
        dp = ndp;
    }

    setup(); int tc; input(tc); while (tc--) {
        int y;
        input(y);
        print(dp[y]);
    }
}
