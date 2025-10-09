#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7;

vector<int> query(vector<int> &v) {
    int k = *max_element(v.begin(), v.end());
    cout << k << endl;
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
    cout.flush();
    vector<int> res(v.size());
    vector<vector<int>> s(k);
    rep(i, 0, k) {
        int x;
        cin >> x;
        s[i].resize(x);
        rep(j, 0, x) {
            int u;
            cin >> u;
            res[u - 1] = i + 1;
        }
    }
    return res;
}

void norm(vector<int> &a) {
    map<int, int> m;
    for (int i : a) {
        m[i]++;
    }
    rep(i, 0, a.size()) {
        a[i] = m[a[i]];
    }
}

void solve(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &x, vector<int> &y, vector<int> &z) {
    norm(a);
    norm(b);
    norm(c);
    norm(x);
    norm(y);
    norm(z);
    map<tuple<int, int, int>, int> m;
    rep(i, 0, a.size()) {
        // cout << x[i] << ' ' << y[i] << ' ' << z[i] << endl;
        m[{x[i], y[i], z[i]}] = i;
    }
    rep(i, 0, a.size()) {
        // cout << a[i] << ' ' << b[i] << ' ' << c[i] << endl;
        cout << m[{a[i], b[i], c[i]}] + 1 << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int k = 1;
    while (k * (k + 1) / 2 <= n) {
        k++;
    }
    k--;

    if (k * (k + 1) / 2 + k == n) {
        k++;
        vector<int> a(n);
        int l = 0;
        rep(i, 2, k + 1) {
            rep(j, 0, i) {
                a[l] = i - 1;
                l++;
            }
        }
        vector<int> x = query(a);

        vector<int> b(n);
        l = 0;
        rep(i, 2, k + 1) {
            rep(j, 0, i) {
                b[l] = j + 1;
                l++;
            }
        }
        b[n - 1] = 1;
        vector<int> y = query(b);

        vector<int> c(n, 0);
        l = 0;
        int t = 0;
        rep(i, n - k + 1, n) {
            t++;
            c[i] = t;
            rep(j, 0, t - 1) {
                c[l] = t;
                l++;
            }
        }
        rep(i, 0, n) {
            if (c[i] == 0) {
                c[i] = t;
            }
        }
        vector<int> z = query(c);

        solve(a, b, c, x, y, z);
        return 0;
    }

    vector<int> a(n);
    int l = 0;
    rep(i, 1, k + 1) {
        rep(j, 0, i) {
            a[l] = i;
            l++;
        }
    }
    while (l < n) {
        a[l] = k;
        l++;
    }
    vector<int> x = query(a);

    vector<int> b(n);
    l = 0;
    rep(i, 1, k + 1) {
        rep(j, 0, i) {
            b[l] = k - j;
            l++;
        }
    }
    while (l < n) {
        b[l] = k;
        l++;
    }
    vector<int> y = query(b);

    vector<int> c(n, 0);
    l = 0;
    int t = 0;
    rep(i, k * (k + 1) / 2 - 1, n) {
        t++;
        c[i] = t;
        rep(j, 0, t - 1) {
            c[l] = t;
            l++;
        }
    }
    rep(i, 0, n) {
        if (c[i] == 0) {
            c[i] = t;
        }
    }
    vector<int> z = query(c);

    solve(a, b, c, x, y, z);
}
