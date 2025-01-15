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

bool solve(vector<int> x, vector<int> y, int m) {
    int l = 0, c = y[0];
    range(i, 1, y.size()) {
        c += y[i];
        while (l < x.size() and c > m) {
            c += x[l];
            l++;
        }
        if (c > m) {
            return false;
        }
        c = max(c, y[i]);
    }
    return true;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        vector<int> x, y;
        for (int i : a) {
            if (i < 0) {
                x.push_back(i);
            }
            else {
                y.push_back(i);
            }
        }

        if (y.empty()) {
            print(0);
            continue;
        }

        int l = *max_element(a.begin(), a.end()), r = 1e18, res = 1e18;
        while (l <= r) {
            int m = (l + r) / 2;
            if (solve(x, y, m)) {
                res = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        print(res);
    }
}
