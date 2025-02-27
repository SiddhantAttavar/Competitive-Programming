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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
    setup();
    int n;
    input(n);

    string s;
    input(s);

    ordered_set o;
    map<int, int> m;
    int p = 0, res = 0;
    rep(i, 0, n) {
        int q = p + (s[i] == '1');
        res += o.order_of_key(i - 4 * q) + m[i - 4 * q + 2];
        // print(i, o.order_of_key(i - 4 * q) + m[i - 4 * q + 2], i - 4 * p);
        // arrprint(o);
        m[i - 4 * p]++;
        o.insert(i - 4 * p);
        p = q;
    }
    print(res);
}
