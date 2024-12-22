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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, m, x;
        input(n, m, x);
        
        vector<vector<int>> a(n, vector<int>(m));
        range(i, 0, n) {
            arrPut(a[i]);
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));
        vector<vector<int>> f(n, vector<int>(m, 1e18));
        range(k, 0, m) {
            dp[n - 1][m - 1][k] = k * x + a[n - 1][(m - 1 + k) % m];
            f[n - 1][m - 1] = min(f[n - 1][m - 1], dp[n - 1][m - 1][k]);
        }

        for (int j = m - 2; j >= 0; j--) {
            range(k, 0, m) {
                dp[n - 1][j][k] = a[n - 1][(j + k) % m] + dp[n - 1][j + 1][k];
                f[n - 1][j] = min(f[n - 1][j], dp[n - 1][j][k]);
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            range(k, 0, m) {
                dp[i][m - 1][k] = k * x + a[i][(m - 1 + k) % m] + f[i + 1][m - 1];
                f[i][m - 1] = min(f[i][m - 1], dp[i][m - 1][k]);
            }
            for (int j = m - 2; j >= 0; j--) {
                range(k, 0, m) {
                    dp[i][j][k] = a[i][(j + k) % m] + min(k * x + f[i + 1][j], dp[i][j + 1][k]);
                    f[i][j] = min(f[i][j], dp[i][j][k]);
                }
            }
        }

        print(f[0][0]);
    }
}
