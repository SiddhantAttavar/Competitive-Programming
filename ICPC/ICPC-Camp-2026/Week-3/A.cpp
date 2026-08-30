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
    int n, t;
    cin >> n >> t;

    vi a(n - 1);
    rep(i, 0, n - 1) {
        cin >> a[i];
    }

    int s = accumulate(all(a), 0ll);
    int p = *min_element(all(a)), q = *max_element(all(a));

    vi res;
    int x = 0;
    int k = t - (s - p - q);
    if (p <= k and k <= q) {
        res.push_back(k);
        x++;
    }
    if (q < ((int) 1e9) and s - p == t) {
        res.push_back(1e9);
        x += 1e9 - q;
    }
    if (p > 0 and s - q == t) {
        res.push_back(0);
        x += p;
    }

    if (res.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << x << ' ' << *min_element(all(res)) << ' ' << *max_element(all(res)) << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
