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

bool f(string s, int i, int a, int b, int c, int d, int x) {
    if (i >= s.size()) {
        return true;
    }

    if (s[i] == 'A') {
        if (i == s.size() - 1 or s[i + 1] == 'A') {
            return a > 0 and f(s, i + 1, a - 1, b, c, d, x);
        }

        if (c > 0 and f(s, i + 2, a, b, c - 1, d, x)) {
            return true;
        }

        if (c == 0 and a > 0 and b > 0 and f(s, i + 2, a - 1, b - 1, c, d, x)) {
            return true;
        }

        return a > 0 and x > 0 and f(s, i + 1, a - 1, b, c, d, x - 1);
    }

    if (i == s.size() - 1 or s[i + 1] == 'B') {
        return b > 0 and f(s, i + 1, a, b - 1, c, d, x);
    }

    if (d > 0 and f(s, i + 2, a, b, c, d - 1, x)) {
        return true;
    }

    if (d == 0 and a > 0 and b > 0 and f(s, i + 2, a - 1, b - 1, c, d, x)) {
        return true;
    }

    return b > 0 and x > 0 and f(s, i + 1, a, b - 1, c, d, x - 1);
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        string s;
        input(s);

        int a, b, c, d;
        input(a, b, c, d);

        if (f(s, 0, a, b, c, d, 2)) {
            print("YES");
        }
        else {
            print("NO");
        }
    }
}
