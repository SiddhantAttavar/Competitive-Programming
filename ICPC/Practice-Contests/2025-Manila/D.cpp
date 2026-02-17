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

    vector<pii> v(n);
    rep(i, 0, n) {
        cin >> v[i].first;
    }
    rep(i, 0, n) {
        cin >> v[i].second;
    }

    sort(all(v), [](pii a, pii b) {
        return (a.second * 1.0 / a.first) > (b.second * 1.0 / b.first);
    });

    double p = v[0].second * 1.0 / v[0].first;
    int q = v[0].first;
    double res = p * q;
    rep(i, 1, sz(v)) {
        auto [x, y] = v[i];
        res += y + (p - y * 1.0 / x) * q * (log(q + x) - log(q));
        p = (p * q + y) / (q + x);
        q += x;
    }

    reverse(all(v));
    p = v[0].second * 1.0 / v[0].first;
    q = v[0].first;
    res -= p * q;
    rep(i, 1, sz(v)) {
        auto [x, y] = v[i];
        res -= y + (p - y * 1.0 / x) * q * (log(q + x) - log(q));
        p = (p * q + y) / (q + x);
        q += x;
    }
    res /= q;
    cout << fixed << setprecision(15) << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
