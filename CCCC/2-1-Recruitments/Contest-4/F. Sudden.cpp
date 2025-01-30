#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
// #define int long long
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

        vector<vector<int>> f(n, vector<int>(n, 0));
        range(i, 0, n) {
            f[i][i] = 0;
            range(j, i + 1, n) {
                f[i][j] = f[i][j - 1] + (a[i] > a[j]);
            }
        }

        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            g[i][i] = 0;
            for (int j = i - 1; j >= 0; j--) {
                g[j][i] = g[j + 1][i] + f[j][i];
            }
        }

        long long res = 0;
        range(i, 0, n) {
            range(j, i + 2, n - 1) {
                if (a[i] < a[j]) {
                    res += g[i + 1][n - 1] - g[j][n - 1] - g[i + 1][j];
                }
            }
        }
        print(res);
    }
}
