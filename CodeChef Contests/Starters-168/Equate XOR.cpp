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
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        int x = 0;
        vector<int> dp(n + 1, -1);
        map<int, int> m;
        m[0] = 0;
        range(i, 0, n) {
            x ^= a[i];
            if (m.count(x)) {
                dp[i + 1] = m[x];
            }
            m[x] = i + 1;
        }

        int res = 0;
        vector<bool> vis(n, false);
        for (int i = n - 1; i >= 0; i--) {
            if (vis[i]) {
                continue;
            }

            int u = i, c = 0;
            while (u != -1) {
                c += a[u];
                vis[u] = true;
                u = dp[u + 1];
            }
            res = max(res, c);
        }
        print(res);
    }
}
