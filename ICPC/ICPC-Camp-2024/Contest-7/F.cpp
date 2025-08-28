#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);

    int w, h;
    cin >> w >> h;

    int a, b;
    cin >> a >> b;

    int x = 0, y = 0;
    int p = a, q = b;
    if (p > w or q > h) {
        x = 1e9;
    }
    else {
        while (p < w) {
            p *= 2;
            x++;
        }
        while (q < h) {
            q *= 2;
            x++;
        }
    }
    
    p = b, q = a;
    if (p > w or q > h) {
        y = 1e9;
    }
    else {
        while (p < w) {
            p *= 2;
            y++;
        }
        while (q < h) {
            q *= 2;
            y++;
        }
    }

    if (x == 1e9 and y == 1e9) {
        cout << "-1\n";
    }
    else {
        cout << min(x, y) << endl;
    }

}
