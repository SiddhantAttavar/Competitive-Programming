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

int query(int l, int r) {
    print('?', l, r);
    cout.flush();
    int x;
    input(x);
    assert(x != -1);
    return x;
}

int32_t main() {
    int tc; input(tc); while (tc--) {
        int n;
        input(n);

        int a = query(1, n / 2);
        int b = query(1, n / 4);
        int c = query(n / 4 + 1, n / 2);

        if (a ^ b ^ c == 0) {
            int l = n / 2 + 1, r = n - 1, k = n - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                int p = 0;
                if (b ^ c) {
                    p = query(1, m);
                }
                else {
                    p = query(n - m + 1, n);
                }
                if (p) {
                    l = m + 1;
                }
                else {
                    k = m;
                    r = m - 1;
                }
            }
            print('!', k);
            cout.flush();
        }
        else {
            int l = 2, r = n / 2, k = 2;
            while (l <= r) {
                int m = (l + r) / 2;
                int p = 0;
                if (b ^ c) {
                    p = query(n / 2 + 1, n / 2 + m);
                }
                else {
                    p = query(1, m);
                }
                if (p) {
                    k = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            print('!', k);
            cout.flush();
        }
    }
}
