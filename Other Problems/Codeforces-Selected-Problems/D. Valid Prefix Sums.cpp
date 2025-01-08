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
        int n, k;
        input(n, k);

        vector<int> a(k);
        arrput(a);

        if (k == 1) {
            print("YES");
            continue;
        }

        vector<int> v(k - 1);
        range(i, 1, k) {
            v[i - 1] = a[i] - a[i - 1];
        }

        bool flag = true;
        range(i, 1, k - 1) {
            if (v[i] < v[i - 1]) {
                flag = false;
                break;
            }
        }

        if (flag and (n - k + 1) * v[0] >= a[0]) {
            print("Yes");
        }
        else {
            print("No");
        }
    }
}
