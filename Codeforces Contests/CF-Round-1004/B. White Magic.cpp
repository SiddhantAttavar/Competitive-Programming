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
        for (int i : a) {
            res += i > 0;
        }

        set<int> s;
        vector<int> v(n);
        v[n - 1] = a[n - 1] == 0;
        s.insert(a[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            v[i] = v[i + 1];
            s.insert(a[i]);
            while (s.count(v[i])) {
                v[i]++;
            }
        }

        bool flag = true;
        int x = 1e9;
        range(i, 0, n) {
            if (a[i] == 0) {
                break;
            }

            x = min(x, a[i]);
            if (i == n - 1 or x < v[i + 1]) {
                flag = false;
                break;
            }
        }

        print(res + flag);
    }
}
