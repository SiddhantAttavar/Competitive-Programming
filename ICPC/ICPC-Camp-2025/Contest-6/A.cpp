#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;

    int m;
    cin >> m;

    int x, y;
    cin >> x >> y;

    t *= 60;
    int res = (m + x - 1) / x + (n - m + y + 1) / y;
    cout << max(0ll, (res - t + 59) / 60) << endl;
}
