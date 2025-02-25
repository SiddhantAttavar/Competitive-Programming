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

const int N = 15;

int32_t main() {
    setup();

    int n, m;
    input(n, m);

    vector<bitset<N>> k(n);
    rep(i, 0, m) {
        int u, v;
        input(u, v);

        u--;
        v--;

        if (u > v) {
            swap(u, v);
        }
        k[u] |= 1 << v;
    }
    int y = 0;
    for (int i = n - 1; i >= 0; i--) {
        // print(k[i], bitset<N>(k[i].to_ulong() >> (i + 1)));
        y = (y << (n - i - 1)) | (k[i].to_ulong() >> (i + 1));
    }
    // print(bitset<N>(y));
    rep(i, 0, n) {
        rep(j, 0, i) {
            k[i][j] = k[j][i];
        }
    }
    rep(i, 0, n) {
        k[i] |= 1 << i;
    }


    int res = 1e9;
    rep(i, 0, 1 << (n * (n - 1) / 2)) {
        int c = __builtin_popcount(y ^ i);
        if (c > res) {
            continue;
        }

        vector<bitset<N>> x(n, 0);
        int o = i;
        rep(j, 0, n) {
            x[j] = (o & ((1 << (n - j - 1)) - 1)) << (j + 1);
            o >>= n - j - 1;
        }
        rep(i, 0, n) {
            rep(j, 0, i) {
                x[i][j] = x[j][i];
            }
        }
        rep(i, 0, n) {
            x[i] |= 1 << i;
        }

        // print(c);
        // rep(i, 0, n) {
        //     print(x[i]);
        // }

        bool flag = true;
        rep(i, 0, n) {
            rep(j, 0, i) {
                if (x[j][i] and (x[j] | x[i]) != ((1 << n) - 1)) {
                    // print(j, i);
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            res = c;
        }
    }
    print(res);
}
