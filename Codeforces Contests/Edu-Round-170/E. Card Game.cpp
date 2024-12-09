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
const int MOD = 998244353;

int32_t main() {
    setup();

    int N = 500;
    int n, m;
    input(n, m);

    vector<int> v(N + 1, 0);
    v[0] = 1;
    range(i, 0, m) {
        vector<int> nv(N + 1, 0);
        nv[0] = v[1];
        range(j, 1, N) {
            nv[j] = (v[j - 1] + v[j + 1]) % MOD;
        }
        nv[N] = v[N - 1];
        v = nv;
    }

    vector<int> dp(v.begin(), v.end());
    range(i, 0, n - 1) {
        vector<int> ndp(N + 1, 0);
        range(j, 0, N + 1) {
            range(k, j, N + 1) {
                ndp[j] = (ndp[j] + dp[k] * v[k - j]) % MOD;
            }
        }
        dp = ndp;
    }
    print(dp[0]);
}
