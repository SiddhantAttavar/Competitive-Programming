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

        int h = 20;
        vector<vector<int>> v(n, vector<int>(h, -1));
        range(i, 0, n) {
            v[i][0] = a[i];
            range(j, 1, h) {
                if (i < (1 << (j - 1))) {
                    break;
                }
                v[i][j] = __gcd(v[i][j - 1], v[i - (1 << (j - 1))][j - 1]);
            }
        }

        vector<vector<int>> dp(n + 1, {0});
        vector<vector<int>> b(n + 1);
        dp[0].push_back(1);
        b[0].push_back(-1);
        range(i, 0, n) {
            int r = i, k = a[i];
            while (r >= 0) {
                k = __gcd(k, a[r]);
                int l = r;
                for (int j = h - 1; j >= 0; j--) {
                    if (l != -1 and v[l][j] != -1 and v[l][j] % k == 0) {
                        l -= 1 << j;
                    }
                }
                l++;

                if (k > n) {
                    r = l - 1;
                    continue;
                }

                int s = lower_bound(b[k - 1].begin(), b[k - 1].end(), l - 1) - b[k - 1].begin();
                int t = upper_bound(b[k - 1].begin(), b[k - 1].end(), r - 1) - b[k - 1].begin() - 1;
                if (s <= t and s >= 0) {
                    dp[k].push_back((dp[k].back() + dp[k - 1][t + 1] - dp[k - 1][s] + MOD) % MOD);
                    b[k].push_back(i);
                }

                r = l - 1;
            }
            dp[0].push_back(i + 2);
            b[0].push_back(i);
        }

        int res = 0;
        range(i, 1, n + 1) {
            res = (res + dp[i].back()) % MOD;
        }
        print(res);
    }
}
