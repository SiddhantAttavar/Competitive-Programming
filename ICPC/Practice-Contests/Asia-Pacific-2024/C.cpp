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
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << (1ll << a[0]) - 1 << endl;
        return;
    }

    if (n == 2 and a[0] == a[1] - 1) {
        cout << (2ll << a[0]) - 2 << endl;
        return;
    }

    int u = 0;
    rep(i, 0, n - 1) {
        if (a[u] - a[u + 1] < a[i] - a[i + 1]) {
            u = i;
        }
    }
    
    int d = a[u] - a[u + 1];
    if (d < 0) {
        cout << -1 << endl;
        return;
    }
    
    int x = (1ll << (d + 1)) - 1;
    x -= u;

    int b = a[0] - __builtin_popcountll(x);
    if (x < 0 or b < 0) {
        cout << -1 << endl;
        return;
    }
    x |= ((1ll << b) - 1) << (d + 2);
    rep(i, 0, n) {
        if (__builtin_popcountll(x + i) != a[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}

