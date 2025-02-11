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

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        int res = 0;
        range(i, 0, n) {
            if (a[i] > 0) {
                res++;
            }
        }

        vector<int> d(n);
        if (a[0] == 0) {
            d[0] = 1e9;
        }
        else {
            d[0] = a[0];
        }
        range(i, 1, n) {
            if (a[i] == 0) {
                d[i] = d[i - 1];
            }
            else {
                d[i] = min(d[i - 1], a[i]);
            }
        }

        bool flag = false;
        set<int> s;
        int x = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > 0) {
                s.insert(a[i]);
                while (s.count(x)) {
                    x++;
                }
                continue;
            }

            int l = i - 1;
            while (l >= 0 and a[l] != 0 and d[l] >= x) {
                s.insert(a[l]);
                while (s.count(x)) {
                    x++;
                }
                l--;
            }

            if (l < 0 or a[l] == 0) {
                flag = true;
                break;
            }

            i = l + 1;
        }
        print(res + flag);
    }
}
