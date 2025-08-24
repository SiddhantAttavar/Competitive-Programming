/*
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

bitset<1 << 13> conv(bitset<1 << 13> &a, bitset<1 << 13> &b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    bitset<1 << 13> c = 0;
    rep(j, 0, 1 << 13) {
        if (!a[j]) {
            continue;
        }
        rep(k, 0, 1 << 13) {
            if (b[k]) {
                c[j | k] = true;
            }
        }
    }
    return c;
}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(13, 0);
    rep(i, 0, n) {
        int x;
        cin >> x;
        v[x - 1]++;
    }

    vector<bitset<1 << 13>> a(4);
    rep(i, 1, 1 << 13) {
        int c = 0;
        rep(j, 0, 13) {
            if (i & (1 << j)) {
                c += v[j];
            }
        }
        if (c <= k) {
            a[0][i] = true;
        }
    }

    rep(i, 1, 4) {
        a[i] = conv(a[i - 1], a[i - 1]);
    }

    int l = 0, r = 13;
    bitset<1 << 13> b = 0;
    for (int i = 3; i >= 0; i--) {
        bitset<1 << 13> t = conv(b, a[i]);
        if (!t[(1 << 13) - 1]) {
            b = t;
            l |= (1 << i);
        }
        else {
            r = min(r, l | (1 << i));
        }
    }
    cout << r << endl;
}
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(13, 0);
    rep(i, 0, n) {
        int x;
        cin >> x;
        v[x - 1]++;
    }

    vector<int> l;
    rep(i, 1, 1 << 13) {
        int c = 0;
        rep(j, 0, 13) {
            if (i & (1 << j)) {
                c += v[j];
            }
        }
        if (c <= k) {
            l.push_back(i);
        }
    }

    vector<int> a(1 << 13, 13);
    a[0] = 0;
    for (int i : l) {
        rep(j, 0, 1 << 13) {
            a[i | j] = min(a[i | j], a[j] + 1);
        }
    }

    cout << a.back() << endl;
}
