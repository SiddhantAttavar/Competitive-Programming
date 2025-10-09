#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7;

int N = 1000;
vector<int> fact(N + 1);

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int mod_div(int a, int b) {
    return a * mod_pow(b, MOD - 2) % MOD;
}

int comb(int n, int r) {
    if (n < r) {
        return 0;
    }
    return mod_div(fact[n], fact[r] * fact[n - r] % MOD);
}

int get(int a, int b, int c, int d) {
    int x = 0, y = 0;
    for (int k = 0; k <= min(a, b); k += 2) {
        x = (x + comb(a, k) * comb(b, k)) % MOD;
    }
    for (int k = 0; k <= min(c, d); k += 2) {
        y = (y + comb(c, k) * comb(d, k)) % MOD;
    }
    return x * y % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fact[0] = 1;
    rep(i, 1, N + 1) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int h, w;
    cin >> h >> w;

    int res = h * w * get(h - 1, w - 1, 0, 0);
    rep(i, 1, h - 1) {
        rep(j, 1, w - 1) {
            int x = 0;
            for (int k = 0; k <= min(i - 1, j - 1); k += 2) {
                x = (x + comb(c, k) * comb(d, k)) % MOD;
            }
            x = x * i * j % MOD;
            int l = h - i - 2, r = w - j - 2;
            for (int k = 0; k <= min(l, r); k += 2) {
                x = (x + comb(a, k) * comb(b, k)) % MOD;
            }
        }
    }
    cout << res << endl;
}
