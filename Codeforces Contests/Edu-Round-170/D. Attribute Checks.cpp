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
    setup();

    int n, m;
    input(n, m);

    vector<int> r(n);
    arrPut(r);

    vector<vector<int>> a(m + 1), b(m + 1);
    int x = 0;
    for (int i : r) {
        if (i == 0) {
            x++;
        }
        else if (i < 0) {
            a[x].push_back(-i);
        }
        else {
            b[x].push_back(i);
        }
    }

    range(i, 0, m + 1) {
        sort(a[i].begin(), a[i].end());
    }
    range(i, 0, m + 1) {
        sort(b[i].begin(), b[i].end());
    }

    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
    range(i, 0, m + 1) {
        range(j, 0, m - i + 1) {
            if (i) {
                dp[i][j] = dp[i - 1][j];
            }
            if (j) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }

            int k = i + j;
            dp[i][j] += upper_bound(a[k].begin(), a[k].end(), i) - a[k].begin();
            dp[i][j] += upper_bound(b[k].begin(), b[k].end(), j) - b[k].begin();
        }
    }

    int res = 0;
    range(i, 0, m + 1) {
        res = max(res, dp[i][m - i]);
    }
    print(res);
}
