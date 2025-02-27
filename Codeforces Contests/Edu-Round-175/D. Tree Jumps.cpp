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
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> p(n - 1);
        arrput(p);

        vector<vector<int>> graph(n);
        rep(i, 0, n - 1) {
            graph[p[i] - 1].push_back(i + 1);
        }

        queue<int> q;
        q.push(0);
        vector<int> v;
        vector<int> d(n, 0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            v.push_back(u);
            for (int v : graph[u]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }

        vector<int> dp(n, 0);
        vector<int> s(n + 1, 0);
        reverse(v.begin(), v.end());
        for (int i : v) {
            dp[i] = (1 + s[d[i] + 1]) % MOD;
            for (int j : graph[i]) {
                dp[i] = (dp[i] - dp[j] + MOD) % MOD;
            }
            s[d[i]] = (s[d[i]] + dp[i]) % MOD;
        }
        print((dp[0] + s[1]) % MOD);
    }
}
