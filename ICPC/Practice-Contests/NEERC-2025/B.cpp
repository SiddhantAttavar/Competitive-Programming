#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;

    const int N = 1000;
    vi w(n), h(n), d(n);
    rep(i, 0, n) {
        cin >> w[i] >> h[i] >> d[i];
        if (w[i] > h[i]) {
            swap(w[i], h[i]);
        }
        if (h[i] > d[i]) {
            swap(h[i], d[i]);
        }
        if (w[i] > h[i]) {
            swap(w[i], h[i]);
        }
    }

    int res = 0;
    rep(x, 1, N + 1) {
        int y = 1e18, z = 1e18;
        bool flag = true;
        rep(i, 0, n) {
            if (w[i] >= x) {
                y = min(y, h[i]);
                z = min(z, d[i]);
            }
            else if (h[i] >= x) {
                y = min(y, w[i]);
                z = min(z, d[i]);
            }
            else if (d[i] >= x) {
                y = min(y, w[i]);
                z = min(z, h[i]);
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            res = max(res, x * y * z);
        }
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
