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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    setup();

    int n;
    input(n);

    vector<int> a(n);
    arrput(a);

    int res = 0;
    rep(i, 0, 10) {
        int x = a[rng() % n];

        map<int, int> m;
        for (int j : a) {
            m[__gcd(j, x)]++;
        }

        vector<int> v;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                v.push_back(j);
                v.push_back(x / j);
            }
        }

        for (int j : v) {
            int c = 0;
            for (pair<int, int> p : m) {
                if (p.first % j == 0) {
                    c += p.second;
                }
            }
            if (2 * c >= n) {
                res = max(res, j);
            }
        }
    }
    print(res);
}
