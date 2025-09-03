#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int res = 100, c = 100;
    rep(i, 0, n) {
        int x;
        cin >> x;
        c += x;
        res = max(res, c);
    }
    cout << res << endl;
}
