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
    int tc; input(tc); while (tc--) {
        print(0);
        cout.flush();

        int x;
        input(x);
        print(x);
        cout.flush();

        int y;
        input(y);

        vector<int> v(30, 0);
        bool flag = x >> 30 & 1;
        for (int i = 29; i >= 0; i--) {
            if ((1 << i) & x) {
                if (flag) {
                    v[i] = 2;
                    flag = true;
                }
                else {
                    if ((y - x) >= (1 << i)) {
                        v[i] = 0;
                        flag = true;
                    }
                    else {
                        v[i] = 1;
                        flag = false;
                    }
                }
                x -= 1 << i;
                y -= (2 - v[i]) * (1 << i);
            }
            else {
                if (flag) {
                    if ((y - x) >= (1 << i)) {
                        v[i] = 1;
                        flag = true;
                    }
                    else {
                        v[i] = 2;
                        flag = false;
                    }
                }
                else {
                    v[i] = 0;
                    flag = false;
                }
            }
            print(v[i], i, flag, y);
        }

        print('!');
        cout.flush();

        int m;
        input(m);
        arrprint(v);
    }
}
