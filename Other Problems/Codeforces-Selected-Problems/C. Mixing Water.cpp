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

int comp(int h, int c, int n, int m, int t) {
    int a = abs(n * (h + c) + h - t * (2 * n + 1));
    int b = abs(m * (h + c) + h - t * (2 * m + 1));
    return a * (2 * m + 1) <= b * (2 * n + 1);
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int h, c, t;
        input(h, c, t);

        if (t >= h) {
            print(1);
            continue;
        }
        else if (2 * t <= c + h) {
            print(2);
            continue;
        }

        if ((h - t) % (2 * t - c - h) == 0) {
            print(2 * (h - t) / (2 * t - c - h) + 1);
            continue;
        }

        int res = (h - t) / (2 * t - c - h);
        print(2 * res + 1 + 2 * !comp(h, c, res, res + 1, t));
    }
}
