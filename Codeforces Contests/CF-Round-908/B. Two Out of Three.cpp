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

        vector<int> a(n);
        arrput(a);

        map<int, int> m;
        for (int i : a) {
            m[i]++;
        }

        int x = -1, y = -1;
        for (pair<int, int> p : m) {
            if (p.second >= 2) {
                if (x == -1) {
                    x = p.first;
                }
                else {
                    y = p.first;
                }
            }
        }

        if (y == -1) {
            print(-1);
            continue;
        }

        vector<int> b(n, 1);
        int l = -1, r = -1;
        rep(i, 0, n) {
            if (a[i] == x and l == -1) {
                b[i] = 2;
                l  = i;
            }
            else if (a[i] == y and r == -1) {
                b[i] = 3;
                r = i;
            }
        }
        arrprint(b);
    }
}
