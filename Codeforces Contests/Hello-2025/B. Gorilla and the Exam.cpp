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

        vector<int> a(n);
        arrput(a);

        if (k == n) {
            print(1);
            continue;
        }

        map<int, int> m;
        for (int i : a) {
            m[i]++;
        }

        vector<int> v;
        for (pair<int, int> p : m) {
            v.push_back(p.second);
        }
        sort(v.begin(), v.end());

        int x = 0;
        int res = v.size();
        range(i, 0, v.size()) {
            if (x + v[i] <= k) {
                x += v[i];
            }
            else {
                res -= i;
                break;
            }
        }
        print(res);
    }
}
