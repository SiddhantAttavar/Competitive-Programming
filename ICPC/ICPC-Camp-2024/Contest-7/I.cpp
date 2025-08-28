#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

int cross(int ax, int ay, int bx, int by) {
    return (ax & by) ^ (bx & ay);
}

int check(bitset<3> a, bitset<3> b) {
    return (a[2] ^ b[2] ^ cross(a[0], a[1], b[0], b[1])) == 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("integral.in", "r", stdin);
    freopen("integral.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        x[i] %= 2;
        if (x[i] == -1) {
            x[i] = 1;
        }
        y[i] %= 2;
        if (y[i] == -1) {
            y[i] = 1;
        }
        // cout << x[i] << ' ' << y[i] << endl;
    }
    x.push_back(x[0]);
    y.push_back(y[0]);

    vector<int> p(n + 1, 0);
    rep(i, 0, n) {
        p[i + 1] = p[i] ^ cross(x[i], y[i], x[i + 1], y[i + 1]);
    }
    // rep(i, 0, n + 1) {
    //     cout << p[i] << ' ';
    // }
    // cout << endl;

    if (p[n] == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v(1 << 3, 0);
    rep(i, 0, n) {
        v[x[i] | (y[i] << 1) | (p[i] << 2)]++;
    }
    // rep(i, 0, 1 << 3) {
    //     cout << v[i] << ' ';
    // }
    // cout << endl;

    int res = 0;
    rep(i, 0, 1 << 3) {
        if (check(i, i)) {
            // cout << i << ' ' << i << endl;
            res += v[i] * (v[i] - 1) / 2;
        }
        rep(j, i + 1, 1 << 3) {
            if (check(i, j)) {
                // cout << i << ' ' << j << endl;
                res += v[i] * v[j];
            }
        }
    }
    // rep(i, 0, n) {
    //     rep(j, i + 1, n) {
    //         res += check(
    //             x[i] | (y[i] << 1) | (p[i] << 2),
    //             x[j] | (y[j] << 1) | (p[j] << 2)
    //         );
    //         if (check(
    //             x[i] | (y[i] << 1) | (p[i] << 2),
    //             x[j] | (y[j] << 1) | (p[j] << 2)
    //         )) {
    //             cout << i << ' ' << j << endl;
    //         }
    //     }
    // }
    cout << res - n << endl;
}
