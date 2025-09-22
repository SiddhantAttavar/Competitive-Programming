#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

vector<int> simulate(vector<pair<int, int>> &v, int x) {
    int c = x;
    vector<int> p;
    for (auto [a, b] : v) {
        c = max(c + 1, a) + b - 1;
        p.push_back(c);
    }
    return p;
}

void print(int x, int k) {
    if (x % k == 0) {
        cout << x / k << ' ' << k << endl;
    }
    else {
        cout << (x / k + 1) << ' ' << (x % k) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    vector<pair<int, int>> v(n);
    rep(i, 0, n) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> a = simulate(v, 0);
    int x = max(0ll, a.back() - k);
    vector<int> b = simulate(v, x);
    int y = max(0ll, b.back() - k);
    vector<int> c = simulate(v, y);
    int z = max(0ll, c.back() - k);
    // cout << x << ' ' << y << ' ' << z << endl;

    vector<int> p(n);
    p[0] = v[0].second;
    rep(i, 1, n) {
        p[i] = p[i - 1] + v[i].second;
    }

    while (q--) {
        int i, j;
        cin >> i >> j;
        j--;

        if (i == 1) {
            print(a[j], k);
            continue;
        }

        if (y == z) {
            print((i - 1) * k + c[j], k);
            continue;
        }

        int w = y + (z - y) * (i - 3);
        print((i - 1) * k + w + p[j], k);
    }
}
