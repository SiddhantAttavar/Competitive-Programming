#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 998244353;

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

signed main() {
    const int N = 1e6;
    vector<int> fact(N + 1, 1);
    rep(i, 2, N + 1) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int x = 1, n = s.size();
    int res = (mod_pow(2, n) + MOD - 1) % MOD;
    rep(i, 1, n) {
        if (s[i] == s[i - 1]) {
            x++;
            continue;
        }

        int l = i - x, r = n - i;
        for (int a = l; a < l + x; a++) {
            int p = mod_div(fact[n], fact[a + 1] * fact[n - a - 1] % MOD);
            int q = mod_div(fact[a + r], fact[a + 1] * fact[r - 1] % MOD);
            res = (res - p + q + MOD) % MOD;
        }
        for (int a = l; a < l + x; a++) {
            res = (res + (l + x - a) * mod_div(fact[a + r - 1], fact[a] * fact[r - 1] % MOD)) % MOD;
        }
        if (l) {
            for (int b = r; b < r + x; b++) {
                res = (res + (r + x - b) * mod_div(fact[b + l - 1], fact[b] * fact[l - 1] % MOD)) % MOD;
            }
        }
        x = 1;
    }
    int l = n - x, r = 0;
    for (int a = l; a < l + x; a++) {
        int p = mod_div(fact[n], fact[a + 1] * fact[n - a - 1] % MOD);
        int q = 0;
        res = (res - p + q + MOD) % MOD;
    }
    if (l) {
        for (int b = r; b < r + x; b++) {
            res = (res + (r + x - b) * mod_div(fact[b + l - 1], fact[b] * fact[l - 1] % MOD)) % MOD;
        }
    }
    else {
        res = n;
    }
    cout << res << endl;
}
