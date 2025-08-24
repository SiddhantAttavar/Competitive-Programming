#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    const int N = 2e5;
    vector<bool> seive(N + 1, true);
    rep(i, 2, N + 1) {
        if (!seive[i]) {
            continue;
        }

        for (int j = 2 * i; j <= N; j += i) {
            seive[j] = false;
        }
    }

    vector<int> f(n), g(n), h(n), l(n), k(n);
    f[1] = !seive[a[0] + a[1]];
    g[1] = 1;
    h[1] = 1e18;
    l[1] = 1e18;
    k[1] = 1e18;
    rep(i, 2, n) {
        g[i] = f[i - 1] + 1;
        h[i] = g[i - 1] + 1;
        l[i] = h[i - 1] + 1;
        k[i] = min(k[i - 1], l[i - 1]) + 1;
        f[i] = k[i - 1];
        if (seive[a[i] + a[i - 1]]) {
            f[i] = min(f[i], f[i - 1]);
        }
        if (a[i] % 2 == a[i - 2] % 2 or (seive[a[i] + 1] and seive[a[i - 2] + 1])) {
            f[i] = min(f[i], g[i - 1]);
        }
        if (i >= 3 and (a[i] % 2 != a[i - 3] % 2 or seive[a[i] + 1] and seive[a[i - 3] + 1])) {
            f[i] = min(f[i], h[i - 1]);
        }
        if (i >= 4 and (a[i] % 2 == a[i - 4] % 2 or seive[a[i] + 1] or seive[a[i - 4] + 1])) {
            f[i] = min(f[i], l[i - 1]);
        }
    }
    cout << min({f[n - 1], g[n - 1], h[n - 1], l[n - 1], k[n - 1]}) << endl;
}
