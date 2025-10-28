#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e7;
int c[N + 1];

bool check(int x) {
    int z = c[0] + accumulate(c + x, c + N + 1, 0ll);
    int y = 1;
    for (int i = x - 1; i > 0; i--) {
        if (c[i] <= y) {
            y += y - c[i];
            if (y >= 1e16) {
                return false;
            }
        }
        else {
            z += c[i] - y;
        }
    }
    return y <= z;
}

void solve() {
    int n;
    cin >> n;

    rep(i, 0, n) {
        cin >> c[i];
    }

    int l = 0, r = N, res = 0;
    if (accumulate(c, c + n, 0ll) == *max_element(c, c + n)) {
        l = max(1ll, (int) (find(c, c + n, *max_element(c, c + n)) - c));
        res = l;
    }
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            res = max(res, m);
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; while (t--) {
        solve();
    }
}
