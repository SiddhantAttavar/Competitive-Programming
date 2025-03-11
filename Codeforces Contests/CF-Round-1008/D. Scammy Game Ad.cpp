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
        int n;
        input(n);

        vector<pair<int, bool>> a(n), b(n);
        rep(i, 0, n) {
            char c, d;
            int x, y;
            input(c, x, d, y);

            a[i] = {c == '+', x};
            b[i] = {d == '+', y};
        }

        int p = 1, q = 1;
        rep(i, 0, n) {
            if (!a[i].first) {
                p *= a[i].second;
            }
            if (!b[i].first) {
                q *= b[i].second;
            }
        }

        int x = 1, y = 1;
        rep(i, 0, n) {
            int z = 0;
            if (a[i].first) {
                z += a[i].second;
            }
            else {
                z += (a[i].second - 1) * x;
            }

            if (b[i].first) {
                z += b[i].second;
            }
            else {
                z += (b[i].second - 1) * y;
            }

            if (!a[i].first) {
                p /= a[i].second;
            }
            if (!b[i].first) {
                q /= b[i].second;
            }

            if (p > q) {
                x += z;
            }
            else {
                y += z;
            }
        }
        print(x + y);
    }
}
