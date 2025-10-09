#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> v, b;
    int x = -1;
    for (int i : a) {
        if (i > x + 1) {
            v.push_back(x + 1);
            b.push_back(i - x - 1);
        }
        x = i;
    }
    v.push_back(x + 1);
    b.push_back(1e9);

    vector<int> p(b.size() + 1, 0);
    rep(i, 0, b.size()) {
        p[i + 1] = p[i] + b[i];
    }

    while (q--) {
        int k;
        cin >> k;

        int j = lower_bound(p.begin(), p.end(), k) - p.begin();
        cout << v[j - 1] + k - p[j - 1] - 1 << ' ';
    }
    cout << endl;
}
