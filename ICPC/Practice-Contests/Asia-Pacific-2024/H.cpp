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

constexpr ll inf = 1E18;

void solve() {
	ll n; cin >> n;
    vector<string> s(n); for(ll i = 0; i < n; i++) { cin >> s[i]; }

    ll m0 = 0, m1 = 0;
    ll ans = 0;

    ll mn_0 = inf, mn_1 = inf;
    ll idx0 = -1, idx1 = -1;

    for(ll i = 0; i < n; i++) {
        ll c0 = count(all(s[i]), '0');
        ll c1 = count(all(s[i]), '1');

        if(c0 <= mn_0) {

        }

        if(c0 > c1) {
            ans += c1;
            m0++;
        } else if(c1 > c0) {
            ans += c0;
            m1++;
        } else {
            ans += c0;
            m0++; m1++;
        }
    }

    if(ans == 0) {
        cout << ans << endl;
        return;
    }

    if(m0 == 0) {
        // ecery string has more ones than zeroes
        
        ll mn = inf;
        for(ll i = 0; i < n; i++) {
            ll c1 = count(all(s[i]), '1');
            ll c0 = count(all(s[i]), '0');
            mn = min(mn,  c1 - c0);
        }

        cout << ans + mn << endl; return; 
    }

    if(m1 == 0) {
        // every string has more zeroes than ones
        
        ll mn = inf; 
        for(ll i = 0; i < n; i++) {
            ll c1 = count(all(s[i]), '1');
            ll c0 = count(all(s[i]), '0');
            mn = min(mn, c0 - c1);
        }

        cout << ans + mn << endl; return;
    }

    cout << ans << endl;
    
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
