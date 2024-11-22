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
        int n, m;
        input(n, m);

        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> p(n, vector<int>(m));
        vector<vector<int>> q(n, vector<int>(m));
        vector<vector<int>> r(n, vector<int>(m));
        vector<vector<int>> s(n, vector<int>(m));
        range(i, 0, n) {
            arrPut(a[i]);
        }

        range(i, 0, n) {
            range(j, 0, m) {
                p[i][j] = a[i][j];
                q[i][j] = a[i][j];
                r[i][j] = a[i][j];
                s[i][j] = a[i][j];
            }
        }

        range(i, 1, n) {
            range(j, 0, m) {
                p[i][j] = min(0ll, p[i - 1][j]) + a[i][j];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            range(j, 0, m) {
                q[i][j] = min(0ll, q[i + 1][j]) + a[i][j];
            }
        }

        range(i, 0, n) {
            range(j, 1, m) {
                r[i][j] = min(0ll, r[i][j - 1]) + a[i][j];
            }
        }

        range(i, 0, n) {
            for (int j = m - 2; j >= 0; j--) {
                s[i][j] = min(0ll, s[i][j + 1]) + a[i][j];
            }
        }

        int res = 1e18;
        range(i, 0, n) {
            range(j, 0, m) {
                res = min(res, p[i][j] + q[i][j] + r[i][j] + s[i][j] - 3 * a[i][j]);
            }
        }
        print(res);
    }
}
