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
    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    rep(i, 2, N + 1) {
        if (!prime[i]) {
            continue;
        }

        for (int j = 2 * i; j <= N; j += i) {
            prime[j] = false;
        }
    }

    int f = 0, g = 1e18, h = 1e18, k = 1e18, l = 1e18, m = 1e18;
    rep(i, 0, n) {
        int t = f;
        f = m;
        if (i < 1 or prime[a[i] + a[i - 1]]) {
            f = min(f, t);
        }
        if (i < 2 or (a[i] % 2 == a[i - 2] % 2 or prime[a[i] + 1] and prime[a[i - 2] + 1])) {
            f = min(f, g);
        }
        if (i < 3 or (a[i] % 2 != a[i - 3] % 2 or prime[a[i] + 1] and prime[a[i - 3] + 1] or a[i] == 1 or a[i - 3] == 1)) {
            f = min(f, h);
        }
        if (i < 4 or (a[i] % 2 == a[i - 4] % 2 or prime[a[i] + 1] or prime[a[i - 4] + 1])) {
            f = min(f, l);
        }
        if (i < 5 or (a[i] % 2 == 1 or a[i - 5] % 2 == 1 or prime[a[i] + 1] or prime[a[i - 5] + 1])) {
            f = min(f, k);
        }

        m = min(m, k) + 1;
        k = l + 1;
        l = h + 1;
        h = g + 1;
        g = t + 1;
        // cout << f << ' ' << g << ' ' << h << ' ' << l << ' ' << k << ' ' << m << endl;   
    }
    cout << min({f, g, h, k, l, m}) << endl;
}
