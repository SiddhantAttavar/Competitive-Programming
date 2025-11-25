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
    ll n; cin >> n;
    vector<ll> p(n); for(ll i = 0; i < n; i++) { cin >> p[i]; }

    ll tot_gcd = p[0];
    for(ll i = 1; i < n; i++) {
        tot_gcd = gcd(tot_gcd, p[i]);
    }

    ll ans = 0;
    ans += tot_gcd;

    vector<ll> pre(n), suf(n);
    pre[0] = p[0]; suf[n-1] = p[n-1];

    for(ll i = 1; i < n; i++) {
        pre[i] = gcd(pre[i-1], p[i]);
    }

    for(ll i = n-2; i >= 0; i--) {
        suf[i] = gcd(suf[i+1], p[i]);
    }

    for(ll i = 1; i < n-1; i++) {
        ans += min(pre[i], suf[i]);
    }

    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
