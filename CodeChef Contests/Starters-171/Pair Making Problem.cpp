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
        int n, m, k;
        input(n, m, k);

        vector<int> a(n);
        arrput(a);

        if (k > (n / 2) * (n - n / 2)) {
            print(-1);
            continue;
        }

        vector<int> f(m);
        for (int i : a) {
            f[i]++;
        }

        int c = 0;
        range(i, 1, m / 2 + 1) {
            c += f[i] * f[m - i];
        }

        if (c >= k) {
            print(0);
            continue;
        }

        vector<vector<int>> dp(m, vector<int>(n + 1, 0));
        range(x, 1, m) {
            range(i, 0, n) {
                range(j, 0, n - i + 1) {
                    dp[x][i + j] = max(dp[x][i + j], (f[x] + i) * (f[m - x] + j) - f[x] * f[m - x]);
                }
            }
        }

        int res = n;
        range(x, 1, m) {
            vector<int> g(f.begin(), f.end());
            int d = c;

            int t = 0, z = x;
            range(i, 0, n) {
                t++;

                int y = -1;
                range(j, 1, m) {
                    if (m - j != z and g[m - j] and (y == -1 or g[j] < g[y])) {
                        y = j;
                    }
                }
                if (y == -1) {
                    break;
                }

                d -= g[y];
                g[m - y]--;

                if (d + dp[x][t] >= k) {
                    res = min(res, t);
                    break;
                }
            }
        }
        print(res);
    }
}
