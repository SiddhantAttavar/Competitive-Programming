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

int solve(int i, vector<int> &a, vector<int> &b, int k, int x, int y, int z) {
    if (x + y >= 2ll * a.size()) {
        return k;
    }

    if (i == a.size()) {
        return k;
    }
    
    if (b[i] <= x + y) {
        if (b[i] > x) {
            y = x;
            x = b[i];
        }
        else if (a[i] > y) {
            y = b[i];
        }
        return solve(i + 1, a, b, k, x, y, z);
    }

    if (a[i] <= x + y) {
        if (a[i] > x) {
            y = x;
            x = a[i];
        }
        else if (a[i] > y) {
            y = a[i];
        }
        return solve(i + 1, a, b, k, x, y, max(z, b[i]));
    }

    int p = x, q = y;
    if (z > x) {
        q = p;
        p = z;
    }
    else {
        q = z;
    }

    if (b[i] <= p + q) {
        if (b[i] > p) {
            q = p;
            p = b[i];
        }
        else if (a[i] > q) {
            q = b[i];
        }
        return solve(i + 1, a, b, k + 1, x, y, 0);
    }

    if (a[i] <= p + q) {
        if (a[i] > x) {
            q = p;
            p = a[i];
        }
        else if (a[i] > q) {
            q = a[i];
        }
        return solve(i + 1, a, b, k + 1, p, q, 0);
    }

    if (b[i] > x) {
        y = x;
        x = b[i];
    }
    else if (a[i] > q) {
        y = b[i];
    }
    return solve(i + 1, a, b, k + 1, x, y, z);
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n), b(n);
        arrPut(a);
        arrPut(b);

        range(i, 0, n) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
            }
        }

        if (b[0] < b[1]) {
            swap(b[0], b[1]);
        }
        print(n - 2 - solve(2, a, b, 0, b[0], b[1], 0));
    }
}
