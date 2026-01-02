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

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    map<int, int> m;
    for (int i : a) {
        m[i]++;
    }

    if (sz(m) == 1) {
        cout << 0 << endl;
        return;
    }

    int res = n - m.rbegin()->second;
    rep(i, 0, n) {
        auto [x, y] = *m.rbegin();
        res = min(res, n - y);
        m.erase(prev(m.end()));
        if (y > 1) {
            m[x - 1] += y - 1;
        }
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
