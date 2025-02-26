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
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, x;
        input(n, x);

        vector<int> a(n);
        arrput(a);

        map<int, int> m;
        for (int i : a) {
            m[i]++;
        }

        if (x == 1) {
            int res = 0;
            for (pair<int, int> p : m) {
                res = max(res, p.second);
            }
            print(res);
            continue;
        }

        map<int, int> dp;
        map<int, int> s;
        for (int i : a) {
            dp[i * x]++;
            s[i * x] = max(s[i * x], dp[i * x]);
            if (i % x == 0) {
                dp[i] = max(0ll, dp[i] - 1);
            }
        }

        int res = 0;
        for (pair<int, int> p : m) {
            res = max(res, p.second + s[p.first]);
        }
        print(res);
    }
}
