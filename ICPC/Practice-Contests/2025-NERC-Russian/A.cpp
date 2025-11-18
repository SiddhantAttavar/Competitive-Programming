#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n), c(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
    }

    rep(i, 0, n) {
        c[i] = a[i] / b[i];
    }

    int x = accumulate(c.begin(), c.end(), 0ll) - k;
    if (x < 0) {
        rep(i, 0, n) {
            cout << 0 << ' ';
        }
        cout << endl;
        return;
    }

    rep(i, 0, n) {
        int t = min(x, c[i]);
        x -= t;
        c[i] -= t;
        cout << c[i] << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
