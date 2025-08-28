#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);

    int w, h, ax, ay, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;

    if (abs(ax - bx) >= 2) {
        cout << min(ax, bx) + 1 << ' ' << 0 << ' ' << min(ax, bx) + 1 << ' ' << h << endl;
        return 0;
    }
    if (abs(ay - ay) >= 2) {
        cout << 0 << ' ' << min(ay, ay) + 1 << ' ' << w << ' ' << min(ay, ay) + 1 << endl;
        return 0;
    }

    if (ax != bx) {
        cout << min(ax, bx) << ' ' << h << ' ' << max(ax, bx) << ' ' << 0 << endl;
    }
    else {
        cout << 0 << ' ' << min(ay, by) << ' ' << w << ' ' << max(ay, by) << endl;
    }
}
