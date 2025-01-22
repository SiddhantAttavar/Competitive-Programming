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
        int n, l, r;
        input(n, l, r);

        l--;
        r--;

        vector<int> a(n);
        arrput(a);

        vector<int> y(a.begin(), a.begin() + l);
        vector<int> x(a.begin() + l, a.begin() + r + 1);
        vector<int> z(a.begin() + r + 1, a.end());

        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(z.begin(), z.end());

        int c = accumulate(x.begin(), x.end(), 0ll);
        int res = c;
        int p = 0, q = 0, s = 0;
        range(i, 0, x.size()) {
            s += x[i];
            if (i < y.size()) {
                p += y[i];
                res = min(res, c - s + p);
            }
            if (i < z.size()) {
                q += z[i];
                res = min(res, c - s + q);
            }
        }
        print(res);
    }
}
