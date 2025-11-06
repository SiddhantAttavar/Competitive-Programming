#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n"

vector<vector<int>> matmul(vector<vector<int>> &a, vector<vector<int>> &b, int m) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size(), 0));
    assert(a[0].size() == b.size());
    rep(i, 0, a.size()) {
        rep(j, 0, b[0].size()) {
            __int128_t x = 0;
            rep(k, 0, b.size()) {
                __int128_t y = a[i][k];
                y *= b[k][j];
                x = (x + y % m) % m;
            }
            c[i][j] = x;
        }
    }
    return c;
}

vector<vector<int>> matpow(vector<vector<int>> &a, int b, int m) {
    vector<vector<int>> res(a.size(), vector<int>(a.size(), 0));
    rep(i, 0, a.size()) {
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = matmul(res, a, m);
        }
        a = matmul(a, a, m);
        b >>= 1;
    }
    return res;
}

void solve() {
    int a, b, m;
    cin >> a >> b >> m;

    a %= m;
    b %= m;
    __int128_t k = m;
    k *= (k - 1);
    k /= 2;
    k %= m;
    __int128_t p = a;
    p *= p;
    p %= m;
    p += m - 2;
    p %= m;
    vector<vector<int>> x = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {(int) k, 0, b, 0}
    };
    __int128_t q = a;
    q = q * a % m;
    q = q * a % m;
    q = (q - ((__int128_t) 3) * a);
    q = (q % m + m) % m;
    vector<vector<int>> y = {
        {1},
        {a},
        {(int) p},
        {(int) q}
    };
    vector<vector<int>> z = matpow(x, b, m);
    vector<vector<int>> w = matmul(z, y, m);
    // cout << w[0][0] << ' ' << w[1][0] << ' ' << w[2][0] << ' ' << w[3][0] << endl;
    cout << w[0][0] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1; while (t--) {
		solve();
	}
}
