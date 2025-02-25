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
        int a, b, c, d;
        input(a, b, c, d);

        int res = 0;
        while (c > a and d > b) {
            if (c > d) {
                int x = max(1ll, (c - max(a, d) + d - 1) / d);
                c -= d * x;
                res += x;
            }
            else {
                int x = max(1ll, (d - max(b, c) + c - 1) / c);
                d -= c * x;
                res += x;
            }
        }

        if (c == a) {
            if (d < b or (d - b) % a > 0) {
                print(-1);
            }
            else {
                print(res + (d - b) / a);
            }
            continue;
        }

        if (d == b) {
            if (c < a or (c - a) % b > 0) {
                print(-1);
            }
            else {
                print(res + (c - a) / b);
            }
            continue;
        }

        print(-1);
    }
}
