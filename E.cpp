#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
const int MOD = 998244353;

int mod_pow(int a, int b) {
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

int mod_div(int a, int b) {
    return (a * mod_pow(b, MOD - 2)) % MOD;
}

bool check(vector<int> &a, vector<int> &b) {
    rep(i, 0, a.size()) {
        rep(j, 0, a.size()) {
            if (min(a[i], b[j]) != min(a[j], b[i])) {
                return false;
            }
        }
    }
    return true;
}

int solve(int n, int m, int i, vector<int> &a, vector<int> &b) {
    if (i == n) {
        return check(a, b);
    }

    int res = 0;
    rep(j, 1, m + 1) {
        rep(k, 1, m + 1) {
            a[i] = j;
            b[i] = k;
            res = (res + solve(n, m, i + 1, a, b)) % MOD;
        }
    }
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    // vector<int> a(n), b(n);
    // cout << (solve(n, m, 0, a, b)) << endl;

    int res = 0;
    rep(i, 1, m + 1) {
        res = (res + mod_pow(m, n) - mod_pow(i, n) + MOD) % MOD;
    }
    res = (res * 2ll) % MOD;
    res = (res + mod_pow(m, n)) % MOD;
    cout << res << endl;

    return 0;
}
