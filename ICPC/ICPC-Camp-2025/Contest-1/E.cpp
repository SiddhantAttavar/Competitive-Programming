#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

#define ll long long
const int MOD = 1e9 + 7;
#define vi vector<int>
#define sz(x) (int) x.size()

vi Z(vector<int> &S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size(), 0));
    rep(i, 0, c.size()) {
        rep(j, 0, c[i].size()) {
            rep(k, 0, b.size()) {
                c[i][j] += a[i][k] * b[k][j] % MOD;
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}

vector<vector<int>> matpow(vector<vector<int>> a, int b) {
    vector<vector<int>> res(a.size(), vector<int>(a.size(), 0));
    rep(i, 0, a.size()) {
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = matmul(res, a);
        }
        a = matmul(a, a);
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(n);
    rep(i, 0, n) {
        cin >> a[i];
        a[i] %= m;
    }
    rep(i, 0, n) {
        cin >> b[i];
        b[i] %= m;
    }
    
    vector<int> x(n), y(n);
    rep(i, 0, n) {
        x[i] = (a[i] - a[(i + 1) % n] + m) % m;
        y[i] = (m - (b[i] - b[(i + 1) % n] + m) % m) % m;
    }

    vector<int> c = x;
    c.push_back(-1);
    c.insert(c.end(), y.begin(), y.end());
    c.insert(c.end(), y.begin(), y.end());
    c.pop_back();

    vector<int> z = Z(c);
    int p = 0;
    rep(i, n + 2, z.size()) {
        p += z[i] == n;
    }

    if (k == 1) {
        cout << p << endl;
        return 0;
    }

    vector<vector<int>> l = matmul(
        matpow({
            {0, n - 1},
            {1, n - 2}
        }, k),
        {{1}, {0}}
    );
    cout << (p * l[1][0] + (z[n + 1] == n) * l[0][0]) % MOD << endl;
}
