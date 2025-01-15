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

        vector<vector<int>> v(30), l(30);
        range(i, 0, n) {
            v[__builtin_popcount(a[i])].push_back(a[i]);
            l[__builtin_popcount(a[i])].push_back(i);
        }

        vector<int> b(n);
        range(i, 0, 30) {
            sort(v[i].begin(), v[i].end());
            range(j, 0, v[i].size()) {
                b[l[i][j]] = v[i][j];
            }
        }

        bool flag = true;
        range(i, 1, n) {
            if (b[i] < b[i - 1]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            print("Yes");
        }
        else {
            print("No");
        }
    }
}
