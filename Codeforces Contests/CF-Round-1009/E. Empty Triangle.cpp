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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int query(int i, int j, int k) {
    print('?', i + 1, j + 1, k + 1);
    cout.flush();
    int x;
    input(x);
    return x - 1;
}

int32_t main() {
    int tc; input(tc); while (tc--) {
        int n;
        input(n);

        int i = 0, j = 1, k = 2;
        while (true) {
            int x = query(i, j, k);
            if (x == -1) {
                break;
            }

            int a = query(i, j, x), b = query(j, k, x), c = query(k, i, x);
            if (a == -1) {
                k = x;
                break;
            }
            else if (b == - 1) {
                i = x;
                break;
            }
            else if (c == -1) {
                j = x;
                break;
            }

            int y = rand() % 3;
            if (y == 0) {
                k = x;
            }
            else if (y == 1) {
                i = x;
            }
            else {
                j = x;
            }
        }
        print('!', i + 1, j + 1, k + 1);
        cout.flush();
    }
}
