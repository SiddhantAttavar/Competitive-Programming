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

int solve(vector<int> &a, vector<int> &b, int k) {
    int res = 0;
    for (int i : a) {
        res += upper_bound(b.begin(), b.end(), k - i) - b.begin();
    }
    return res;
}

int32_t main() {
    setup();

    int n, k;
    input(n, k);

    vector<int> a(n), b(n);
    arrput(a);
    arrput(b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = 0, r = 2e9, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (solve(a, b, m) >= k) {
            res = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    print(res);
}
