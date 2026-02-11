#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e7 + 7;

int mpow(int a, int b) {
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

int mdiv(int a, int b) {
    return a * mpow(b, MOD - 2) % MOD;
}

int brute(int n) {
    int x = 1;
    rep(i, 1, n + 1) {
        x *= i;
    }
    vector<vi> d(x + 1);
    rep(i, 1, x + 1) {
        for (int j = i; j <= x; j += i) {
            d[j].push_back(i);
        }
    }
    int res = 0;
    for (int i : d[x]) {
        res += sz(d[i]);
    }
    return res % MOD;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    const int N = 1e6;
    vi spf(N + 1);
    iota(all(spf), 0);
    vi p;
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

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        int res = 1;
        for (int i : p) {
            if (i > n) {
                break;
            }

            int z = i, c = 0;
            while (z <= n) {
                c += n / z;
                z *= i;
            }
            res = res * ((c + 1) * (c + 2) / 2 % MOD) % MOD;
        }
        cout << res << endl;
    }
}
