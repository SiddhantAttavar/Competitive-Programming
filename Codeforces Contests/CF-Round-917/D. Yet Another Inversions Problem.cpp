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
const int MOD = 998244353;

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, k;
        input(n, k);

        vector<int> p(n), q(k);
        arrput(p);
        arrput(q);

        ordered_set o;
        int res = 0;
        for (int i : q) {
            res += o.size() - o.order_of_key(i);
            o.insert(i);
        }
        res = (res * n) % MOD;

        range(i, 0, min(30ll, k)) {
            o.clear();
            for (int j : p) {
                res = (res + (o.size() - o.order_of_key(j << i)) * (k - i)) % MOD;
                o.insert(j);
            }
            res = (res + o.size() * max(0ll, k - 30) * max(0ll, k - 29) / 2) % MOD;
        }

        reverse(p.begin(), p.end());
        range(i, 1, min(30ll, k)) {
            o.clear();
            for (int j : p) {
                res = (res + o.order_of_key(j << i) * (k - i)) % MOD;
                o.insert(j);
            }
        }

        print(res);
    }
}

