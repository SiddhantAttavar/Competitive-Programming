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
        int x, y, z, k;
        input(x, y, z, k);

        int res = 1e18;
        range(u, 0, 1e8) {
            int q = z - k * (u * (u + 1) / 2);
            if (q < 0) {
                break;
            }


            int p = k * u + 1;
            while (p != -1) {
                res = min(res, p * x + u * y + y * ((q + p - 1) / p));
                int l = p + 1, r = k * u + k, o = (q + p - 1) / p;
                p = -1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if ((q + m - 1) / m != o) {
                        p = m;
                        r = m - 1;
                    }
                    else {
                        l = m + 1;
                    }
                }
            }
        }
        print(res);
    }
}
