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
    int n, x;
    cin >> n >> x;

    vi a(n), b(n);
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
    }
    if (accumulate(all(a), 0ll) > x or x > accumulate(all(b), 0ll)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    x -= accumulate(all(a), 0ll);
    rep(i, 0, n) {
        int t = min(x, b[i] - a[i]);
        x -= t;
        cout << a[i] + t << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
