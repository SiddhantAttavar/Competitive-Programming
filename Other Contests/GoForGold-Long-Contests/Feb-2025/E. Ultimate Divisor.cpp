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

    int N = 1e6;
    vector<int> p;
    vector<int> spf(N + 1);
    rep(i, 0, N + 1) {
        spf[i] = i;
    }
    rep(i, 2, N + 1) {
        if (spf[i] != i) {
            continue;
        }

        p.push_back(i);
        for (int j = i; j <= N; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }

    int n;
    input(n);

    vector<int> a(n);
    arrput(a);

    int res = 1;
    rep(i, 0, 8) {
        int x = a[rng() % n];

        if (x <= res) {
            continue;
        }

        map<int, int> s;
        int o = x;
        for (int j : p) {
            while (o % j == 0) {
                o /= j;
                s[j]++;
            }
        }
        if (o > 1) {
            s[o] = 1;
        }

        vector<int> v = {1};
        for (pair<int, int> p : s) {
            int z = 1;
            vector<int> l(v.begin(), v.end());
            rep(j, 0, p.second) {
                z *= p.first;
                for (int k : v) {
                    l.push_back(k * z);
                }
            }
            v = l;
        }

        map<int, int> m;
        for (int j : a) {
            m[__gcd(j, x)]++;
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int j : v) {
            if (j <= res) {
                break;
            }
            int c = 0;
            for (pair<int, int> p : m) {
                if (p.first % j == 0) {
                    c += p.second;
                }
            }
            if (2 * c >= n) {
                res = max(res, j);
                break;
            }
        }
    }
    print(res);
}
