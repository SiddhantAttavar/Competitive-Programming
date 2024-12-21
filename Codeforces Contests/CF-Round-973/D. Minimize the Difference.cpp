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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

bool check1(vector<int> &a, int x) {
    int k = a[0] - x;
    range(i, 1, a.size()) {
        if (a[i] < x) {
            if (k < x - a[i]) {
                return false;
            }
            k -= x - a[i];
        }
        else {
            k += a[i] - x;
        }
    }
    return true;
}

bool check2(vector<int> &a, int x) {
    int k = x - a.back();
    for (int i = a.size() - 2; i >= 0; i--) {
        if (a[i] > x) {
            if (k < a[i] - x) {
                return false;
            }
            k -= a[i] - x;
        }
        else {
            k += x - a[i];
        }
    }
    return true;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrPut(a);

        int l = 0, r = a[0], x = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check1(a, m)) {
                x = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        l = a[n - 1], r = 1e18;
        int y = 1e18;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check2(a, m)) {
                y = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        print(y - x);
    }
}
