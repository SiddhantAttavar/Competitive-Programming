#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int m, n;
        input(m, n);

        vector<vector<int>> a(m, vector<int>(n));
        range(i, 0, m) {
            arrPut(a[i]);
        }

        int res = (int) -1e12;
        range(i, 0, m) {
            range(j, 0, n) {
                int c = 0, y = (int) -1e12, x = a[i][j];
                int t = min({i, j, m - i - 1, n - j - 1}) + 1;
                if (t == 1) {
                    continue;
                }
                range(k, 1, t) {
                    c += a[i - k][j - k] + a[i + k][j + k];
                    c += a[i - k][j + k] + a[i + k][j - k];
                    y = max(y, c);
                }
                x += y;
                res = max(res, x + y);
            }
        }

        range(i, 0, m - 1) {
            range(j, 0, n - 1) {
                int c = 0, y = 0, x = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
                int t = min({i, j, m - i - 2, n - j - 2}) + 1;
                range(k, 1, t) {
                    c += a[i - k][j - k] + a[i + k + 1][j + k + 1];
                    c += a[i - k][j + k + 1] + a[i + k + 1][j - k];
                    y = max(y, c);
                }
                x += y;
                c = 0;
                y = 0;
                range(k, 1, t) {
                    y = max(y, c);
                }
                res = max(res, x + y);
            }
        }

        print(res);
        cout.flush();
    }
}
