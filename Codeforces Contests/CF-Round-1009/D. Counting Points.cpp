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
        int n, m;
        input(n, m);

        vector<int> x(n), r(n);
        arrput(x);
        arrput(r);

        map<int, int> s;
        rep(i, 0, n) {
            rep(j, x[i] - r[i], x[i] + r[i] + 1) {
                int l = 0, e = 1e9, k = 0;
                while (l <= e) {
                    int y = (l + e) / 2;
                    if ((x[i] - j) * (x[i] - j) + y * y <= r[i] * r[i]) {
                        k = y;
                        l = y + 1;
                    }
                    else {
                        e = y - 1;
                    }
                }
                s[j] = max(s[j], k);
            }
        }

        int res = 0;
        for (pair<int, int> p : s) {
            // print(p.first, p.second, res);
            res += 2 * p.second + 1;
        }
        print(res);
    }
}
