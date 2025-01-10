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
        range(i, 0, n) {
            a[i] = i + 1;
        }

        if (n % 2 == 0) {
            int k = 1;
            while (2 * k <= n) {
                k *= 2;
            }
            if (k < n) {
                a.erase(a.begin() + k - 2);
                a.push_back(k - 1);
            }
            else {
                swap(a[0], a[1]);
            }
        }
        else if (n >= 5) {
            swap(a[n - 4], a[n - 5]);
        }

        int k = 0;
        range(i, 0, n) {
            if (i % 2 == 0) {
                k &= a[i];
            }
            else {
                k |= a[i];
            }
        }
        print(k);
        arrprint(a);
    }
}
