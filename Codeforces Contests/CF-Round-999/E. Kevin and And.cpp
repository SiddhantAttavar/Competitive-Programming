#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, m, k;
        input(n, m, k);

        vector<int> a(n);
        arrput(a);

        vector<int> b(m);
        arrput(b);

        vector<vector<int>> f(n, vector<int>(m + 1, (1 << 30) - 1));
        range(i, 0, n) {
            vector<pair<int, int>> v = {{a[i], 0}};
            range(j, 0, m) {
                vector<pair<int, int>> nv(v.begin(), v.end());
                for (pair<int, int> p : v) {
                    nv.push_back({p.first & b[j], p.second + 1});
                }
                v = nv;
            }
            for (pair<int, int> p : v) {
                f[i][p.second] = min(f[i][p.second], p.first);
            }
        }

        vector<int> p; range(i, 0, n) {
            range(j, 0, m) {
                p.push_back(f[i][j] - f[i][j + 1]);
            }
        }
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        print(accumulate(a.begin(), a.end(), 0ll) - accumulate(p.begin(), p.begin() + k, 0ll));
    }
}
