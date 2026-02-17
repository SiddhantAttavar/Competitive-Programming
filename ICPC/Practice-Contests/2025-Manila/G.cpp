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
    int n, b;
    cin >> n >> b;

    vi a(n - 1);
    rep(i, 0, n - 1) {
        cin >> a[i];
    }

    int k = *max_element(all(a));
    if (-k > b) {
        cout << -1 << endl;
        return;
    }
    if (k < 0) {
        cout << b + k << endl;
        return;
    }

    int res = 0;
    for (int i : a) {
        res += max(0ll, i);
    }
    cout << b + res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
