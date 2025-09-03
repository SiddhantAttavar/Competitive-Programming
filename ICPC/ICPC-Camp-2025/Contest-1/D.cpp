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

    bool flag = true;
    vector<vector<bool>> v(10, vector<bool>(10, false));
    rep(i, 0, n) {
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        r--;
        c--;

        if (d == 0) {
            rep(i, c, c + l) {
                if (min(r, i) < 0 or max(r, i) >= 10 or v[r][i]) {
                    flag = false;
                }
                else {
                    v[r][i] = true;
                }
            }
        }
        else {
            rep(i, r, r + l) {
                if (min(c, i) < 0 or max(c, i) >= 10 or v[i][c]) {
                    flag = false;
                }
                else {
                    v[i][c] = true;
                }
            }
        }
    }

    if (flag) {
        cout << 'Y';
    }
    else {
        cout << 'N';
    }
}
