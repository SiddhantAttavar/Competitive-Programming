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

int mpow(int a, int b) {
    b %= MOD - 1;
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int mdiv(int a, int b) {
    return (a * mpow(b, MOD - 2)) % MOD;
}

map<pair<int, int>, int> memo;

int f(int k, int b) {
    pair<int, int> p = {k, b};
    if (memo.count(p)) {
        return memo[p];
    }
    if (k == 0) {
        return 0;
    }

    if (k == 1) {
        return b * (b + 1) / 2;
    }

    int c = (b * mdiv((mpow(10, k) - 1 + MOD) % MOD, 9)) % MOD;
    if (k & 1) {
        int z = mpow(10, k - 1);
        int y = (b * mdiv((z - 1 + MOD) % MOD, 9)) % MOD;
        return memo[p] = (((f(k - 1, b) * 10 - b * (k - 1) * (9 - b) + f(1, b) + y * f(1, 9)) % MOD) + MOD) % MOD;
    }

    int l = 1;
    while ((2 * l) < k) {
        l *= 2;
    }

    int x = f(k / 2, b);
    int z = mpow(10, k / 2);
    int y = (b * mdiv((z - 1 + MOD) % MOD, 9)) % MOD;
    return memo[p] = ((x * z - b * ((k / 2) % MOD) * (z - y - 1 + MOD) + x + y * f(k / 2, 9)) % MOD + MOD) % MOD;
}

int brute(int n) {
    int s = 0;
    range(i, 1, n + 1) {
        int x = i;
        while (x) {
            s += x%10;
            s %= MOD;
            x /= 10;
        }
    }
    return s;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int m;
        input(m);

        vector<pair<int, int>> a(m);
        range(i, 0, m) {
            input(a[i].first, a[i].second);
        }

        reverse(a.begin(), a.end());
        int l = 0, x = 0, res = 0;
        for (pair<int, int> p : a) {
            int k, b;
            tie(k, b) = p;

            int z = mpow(10, l);
            int c = (b * mdiv((mpow(10, k) - 1 + MOD) % MOD, 9)) % MOD;

            int y = (f(k, b) * z) % MOD;
            int t = (b * (k % MOD) * ((z - x - 1 + MOD) % MOD)) % MOD;
            y = (y - t + MOD) % MOD;
            y = (y + c * f(l, 9)) % MOD;

            res = (res + y) % MOD;
            l += k;
            x = (x + c * z) % MOD;
        }
        print(res);
    }
}
