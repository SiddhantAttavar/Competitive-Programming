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
    int x = 0;
    for (int i = 0; i < 30; i += 2) {
        x |= 1 << i;
    }

	int tc; input(tc); while (tc--) {
        print(x);
        cout.flush();
        int a, b;
        input(a);

        print(x * 2);
        cout.flush();
        input(b);

        vector<int> v(30);
        rep(i, 1, 30) {
            if (i % 2 == 1) {
                v[i] = (a >> i & 3) - 1;
            }
            else {
                v[i] = (b >> i & 3) - 1;
            }
        }
        v[0] = b & 3;

        print('!');
        cout.flush();

        int m;
        input(m);

        int res = 0;
        rep(i, 0, 30) {
            if ((1 << i) & m) {
                res += 2 << i;
            }
            else {
                res += v[i] << i;
            }
        }
        print(res);
        cout.flush();
	}
}
