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
        string s;
        input(s);

        bool flag = true;
        rep(i, 0, s.size() - 1) {
            flag &= s[i] != s[i + 1];
        }

        if (flag) {
            print(0);
            continue;
        }

        int x = 0;
        for (char c : s) {
            x += c == '0';
        }
        int y = s.size() - x;

        if (x > y) {
            swap(x, y);
        }

        if (y - x <= 1) {
            print(1);
            continue;
        }

        if (y - x <= 3) {
            print(2);
            continue;
        }

        print(3);
    }
}
