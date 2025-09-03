#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    long double k = 1;
    if (a == 0) {
        a = 1;
        k = 1 + 1.0 / b;
    }

    vector<long double> dp(n + 1, 0);
    vector<long double> pdp(n + 2, 0);
    rep(i, 1, n + 1) {
        int l = max(0ll, i - b), r = max(-1ll, i - a);
        dp[i] = (pdp[r + 1] - pdp[l]) / (b - a + 1) + k;
        pdp[i + 1] = pdp[i] + dp[i];
    }
    cout << fixed << setprecision(10) << dp[n] << endl;
}
