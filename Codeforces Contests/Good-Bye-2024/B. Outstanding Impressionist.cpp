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

        vector<int> l(n), r(n);
        range(i, 0, n) {
            input(l[i], r[i]);
        }

        vector<int> a(2 * n + 1, 0);
        range(i, 0, n) {
            if (l[i] == r[i]) {
                a[l[i]]++;
            }
        }

        vector<int> b(2 * n + 1);
        range(i, 1, 2 * n + 1) {
            b[i] = b[i - 1] + (a[i] > 0);
        }
        range(i, 0, n) {
            if (l[i] == r[i]) {
                cout << (a[l[i]] == 1);
            }
            else {
                cout << (b[r[i]] - b[l[i] - 1] < r[i] - l[i] + 1);
            }
        }
        cout << endl;
    }
}
