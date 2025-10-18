#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> d(h + 1, vector<int>(w + 1)), pd(h + 1, vector<int>(w + 1, 0)), qd(h + 1, vector<int>(w + 1, 0));
    vector<vector<int>> f(h + 1, vector<int>(w + 1)), pf(h + 1, vector<int>(w + 1, 0)), qf(h + 1, vector<int>(w + 1, 0));
    rep(i, 1, h + 1) {
        rep(j, 1, w + 1) {
            if (j >= 3) {
                rep(k, 1, i - 1) {
                    d[i][j] = (d[i][j] + (i - k - 1) * (j * pd[k][j - 2] % MOD - qd[k][j - 2] + MOD)) % MOD;
                    f[i][j] = (f[i][j] + (i - k - 1) * (j * pf[k][j - 2] % MOD - qf[k][j - 2] + MOD)) % MOD;
                }
            }
            f[i][j] = (f[i][j] + 1) % MOD;
            d[i][j] = (d[i][j] + i * j * f[i][j]) % MOD;
            pd[i][j] = (pd[i][j - 1] + d[i][j]) % MOD;
            pf[i][j] = (pf[i][j - 1] + f[i][j]) % MOD;
            qd[i][j] = (qd[i][j - 1] + (j + 1) * d[i][j]) % MOD;
            qf[i][j] = (qf[i][j - 1] + (j + 1) * f[i][j]) % MOD;
        }
    }

    cout << d[h][w] << endl;
}
