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

int query(int i) {
    print('?', i + 1);
    cout.flush();
    int x;
    input(x);
    return x - 1;
}

int32_t main() {
    int n;
    input(n);

    int l = 0, r = n - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (query(m) < query(m + 1)) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }

    if (l == r or query(l) < query(r)) {
        print('!', l + 1);
    }
    else {
        print('!', r + 1);
    }
}
