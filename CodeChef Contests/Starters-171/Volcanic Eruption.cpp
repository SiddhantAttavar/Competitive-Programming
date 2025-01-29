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
        int n, p;
        input(n, p);

        vector<int> a(n);
        arrput(a);

        vector<int> l(n), r(n);
        l[0] = a[0] ? 1e9 : 0;
        range(i, 1, n) {
            if (a[i]) {
                l[i] = max(a[i], l[i - 1]);
            }
        }
        r[n - 1] = a[n - 1] ? 1e9 : 0;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i]) {
                r[i] = max(a[i], r[i + 1]);
            }
        }

        vector<int> res(n);
        range(i, 0, n) {
            res[i] = (min(l[i], r[i]) + p - 1) / p;
        }
        arrprint(res);
    }
}
