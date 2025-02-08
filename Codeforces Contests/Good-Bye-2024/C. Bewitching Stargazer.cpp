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

map<pair<int, int>, pair<int, int>> memo;

pair<int, int> solve(int n, int k) {
    if (n < k) {
        return {0, 0};
    }

    if (memo.count({n, k})) {
        return memo[{n, k}];
    }

    pair<int, int> p = solve(n / 2, k);
    return memo[{n, k}] = {
        2 * p.first + p.second * (n / 2 + n % 2) + (n % 2) * (n / 2 + 1),
        2 * p.second + (n % 2)
    };
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, k;
        input(n, k);

        print(solve(n, k).first);
    }
}
