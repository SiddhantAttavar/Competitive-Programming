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

int mod_pow(int a, int b, int m = MOD) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }

        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    int N = 1e5;
    vector<bool> seive(N + 1, true);
    vector<int> primes;
    range(i, 2, N + 1) {
        if (!seive[i]) {
            continue;
        }

        primes.push_back(i);
        for (int j = i; j <= N; j += i) {
            seive[j] = false;
        }
    }

    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrPut(a);

        vector<int> b(N + 1, 0);
        for (int i : a) {
            b[i]++;
        }

        int res = 1;
        for (int p : primes) {
            map<int, int> m;
            int x = 0;
            for (int i = p; i <= N; i += p) {
                int k = i, c = 0;
                while (k % p == 0) {
                    c++;
                    k /= p;
                }
                m[c] += b[i];
                x += b[i];
            }

            for (pair<int, int> i : m) {
                int c, t;
                tie(c, t) = i;

                if (t == 0) {
                    continue;
                }
                x -= t;

                int k = (mod_pow(2, t, MOD - 1) - 1 + MOD - 1) % (MOD - 1);
                k = (k * mod_pow(2, x, MOD - 1)) % (MOD - 1);
                res = (res * mod_pow(p, (c * k) % (MOD - 1))) % MOD;
            }
        }
        print(res);
    }
}
