#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

    int d, m, y;
    cin >> d >> m >> y;
    array<int, 3> k = {y - 18, m, d};

    int res = -1;
    array<int, 3> s = {-1, -1, -1};

    int n;
    cin >> n;
    rep(i, 0, n) {
        int x, y, z;
        cin >> x >> y >> z;

        array<int, 3> t = {z, y, x};
        if (t <= k and s < t) {
            s = t;
            res = i + 1;
        }
    }
    
    cout << res << endl;
}
