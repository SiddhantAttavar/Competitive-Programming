#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, m) {
        cin >> b[i];
    }

    int res = 0;
    rep(i, 1, n) {
        res += abs(a[i] - a[i - 1]);
    }
    rep(i, 1, m) {
        res += abs(b[i] - b[i - 1]);
    }
    cout << res << endl;
}
