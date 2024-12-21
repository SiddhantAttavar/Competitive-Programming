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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrPut(a);

        int o = 0;
        for (int i : a) {
            o = __gcd(o, i);
        }
        range(i, 0, n) {
            a[i] /= o;
        }

        int res = *min_element(a.begin(), a.end());
        int z = res;
        range(i, 1, n) {
            if (z == 1) {
                res++;
                continue;
            }
            int y = z;
            for (int j : a) {
                if (__gcd(z, j) < y) {
                    y = __gcd(z, j);
                }
            }
            z = y;
            res += z;
        }
        print(res * o);
    }
}
