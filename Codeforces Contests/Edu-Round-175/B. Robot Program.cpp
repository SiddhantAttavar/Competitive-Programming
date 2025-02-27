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

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, x, k;
        input(n, x, k);

        string s;
        input(s);

        int j = -1;
        rep(i, 0, n) {
            if (s[i] == 'L') {
                x--;
            }
            else {
                x++;
            }
            if (x == 0) {
                j = i;
                break;
            }
        }

        if (j == -1 or j >= k) {
            print(0);
            continue;
        }

        k -= j + 1;
        j = -1;
        rep(i, 0, n) {
            if (s[i] == 'L') {
                x--;
            }
            else {
                x++;
            }
            if (x == 0) {
                j = i;
                break;
            }
        }

        if (j == -1) {
            print(1);
        }
        else {
            print(1 + k / (j + 1));
        }
    }
}
