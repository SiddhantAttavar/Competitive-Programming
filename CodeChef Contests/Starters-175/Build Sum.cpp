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
        int x, y, z;
        input(x, y, z);

        if (x + y == z) {
            print(0);
            continue;
        }

        if ((x ^ y ^ z) & 1) {
            print(-1);
            continue;
        }

        int a = 0, b = 0, c = 0;
        bool d = 0;
        map<pair<int, int>, int> m;
        rep(i, 0, 30) {
            int k = (x >> i & 1) + (y >> i & 1);
            d = k + d >= 2;
            if (((x ^ y ^ z) >> (i + 1) & 1) != (k + d >= 2)) {
                d = !d;
                if (k == 0) {
                    m[{1, 2}] |= 1 << i;
                }
                else if (k == 1 and d == 0) {
                    if (x & (1 << i)) {
                        m[{2, 3}] |= 1 << i;
                    }
                    else {
                        m[{1, 3}] |= 1 << i;
                    }
                }
                else if (k == 1 and d == 1) {
                    if (x & (1 << i)) {
                        m[{1, 3}] |= 1 << i;
                    }
                    else {
                        m[{2, 3}] |= 1 << i;
                    }
                }
                else {
                    m[{1, 2}] |= 1 << i;
                }
            }
        }

        print(m.size());
        for (pair<pair<int, int>, int> p : m) {
            print(p.first.first, p.first.second, p.second);
        }
    }
}
