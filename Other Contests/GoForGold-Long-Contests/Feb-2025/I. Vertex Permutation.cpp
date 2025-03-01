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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, m;
        input(n, m);

        vector<vector<int>> graph(n);
        rep(i, 0, m) {
            int u, v;
            input(u, v);

            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        vector<int> dp(1 << n, 1e9);
        dp[0] = 0;
        rep(i, 1, 1 << n) {
            int x = __builtin_popcount(i);

            rep(j, 0, n) {
                if ((i & (1 << j)) == 0) {
                    continue;
                }

                int c = 0;
                for (int v : graph[x - 1]) {
                    c += 
                }
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + c);
            }
        }

        print(dp.back());
    }
}
