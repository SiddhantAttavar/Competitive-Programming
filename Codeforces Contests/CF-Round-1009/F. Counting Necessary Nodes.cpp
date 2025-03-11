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

int solve2(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    if (x == 0) {
        return 0;
    }
    // print(x, y);
    int a = 0, b = -1;
    rep(i, 0, 20) {
        if ((1 << i) & x) {
            b = i;
        }
    }
    rep(i, 0, 20) {
        if ((1 << i) & x) {
            a += 1 << (b - i);
        }
    }
    return a * (y / (1 << b)) + solve2(x, y % (1 << b));
}

int solve3(int l, int r, int a) {
    for (int i = 19; i >= 0; i--) {
        if (l / (1 << i) != r / (1 << i)) {
            int k = r - r % (1 << i);
            return (
                solve2(a, k - l) +
                solve2(a, r - k + 1)
            );
        }
        else if (l % (1 << i) == 0 and (r + 1) % (1 << i) == 0) {
            return solve2(a, r - l + 1);
        }
    }
    return solve2(a, r - l + 1);
}

int solve4(int a, int b, int c, int d) {
    for (int i = 19; i >= 0; i--) {
        if (a / (1 << i) != b / (1 << i)) {
            int k = b - b % (1 << i);
            return (
                solve3(c, d, k - a) +
                solve3(c, d, b - k + 1)
            );
        }
        else if (c / (1 << i) != d / (1 << i)) {
            int k = d - d % (1 << i);
            return (
                solve3(a, b, k - c) +
                solve3(a, b, d - k + 1)
            );
        }
        else if (a % (1 << i) == 0 and (b + 1) % (1 << i) == 0) {
            return solve3(c, d, b - a + 1);
        }
        else if (c % (1 << i) == 0 and (d + 1) % (1 << i) == 0) {
            return solve3(a, b, d - c + 1);
        }
    }
    return solve2(b - a + 1, d - c + 1);
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int a, b, c, d;
        input(a, b, c, d);

        print(solve4(a, b - 1, c, d - 1));
    }
}
