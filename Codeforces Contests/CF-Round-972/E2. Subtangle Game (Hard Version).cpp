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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

const int L = 1500;

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int l, n, m;
        input(l, n, m);

        vector<int> a(l);
        arrPut(a);

        map<int, int> s;
        range(i, 0, l) {
            if (s.count(a[i])) {
                l = i;
                break;
            }
            s[a[i]] = i;
        }

        vector<vector<int>> b(n, vector<int>(m));
        range(i, 0, n) {
            arrPut(b[i]);
        }

        vector<bitset<L + 1>> dp(m + 1, bitset<L + 1>(false));
        for (int i = n - 1; i >= 0; i--) {
            vector<bitset<L + 1>> ndp(m + 1, bitset<L + 1>(false));
            for (int j = m - 1; j >= 0; j--) {
                ndp[j] = ndp[j + 1] | dp[j];
                if (s.count(b[i][j])) {
                    int k = s[b[i][j]];
                    ndp[j][k] = ndp[j][k] or !dp[j + 1][k + 1];
                }
            }
            dp = ndp;
        }

        if (dp[0][0]) {
            print('T');
        }
        else {
            print('N');
        }
    }
}
