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

        int h = 60;
        vector<vector<int>> v(n, vector<int>(h, n));
        for (int i = n - 2; i >= 0; i--) {
            range(j, 0, h) {
                if ((a[i] ^ a[i + 1]) >> j) {
                    v[i][j] = i + 1;
                }
                else {
                    v[i][j] = v[i + 1][j];
                }
            }
        }
        
        int res = 0;
        range(i, 0, n) {
            int l = i, c = n - 1;
            range(j, 0, h) {
                int r = min(n - 1, l + (1ll << j) - 1);
                if (v[i][j + 1] <= r) {
                    c = v[i][j + 1] - 1;
                    break;
                }
                l = r + 1;
                if (l == n) {
                    break;
                }
            }
            res += c - i + 1;
        }
        print(res);
    }
}
