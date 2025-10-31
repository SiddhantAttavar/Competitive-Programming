#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
#define ld long double
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    ll n; cin >> n;
    vector<ll> x(n), y(n), a(n), b(n);
    for(ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> a[i] >> b[i];
    }

    auto check = [&](ld mid) -> bool {
        ld tot = 0;
        for(ll i = 0; i < n; i++) {
            tot += max(1.0*y[i] - mid*x[i], 1.0*b[i] - mid*a[i]);
        }
        if(tot >= 0) {
            return true;
        } else {
            return false;
        }
    };


    ld eps = 1e-10;
    ld L = 0, R = 1e9, ans = -1;
    while(R - L >  eps) {
        ld mid = L + (R-L)/2.0;
        if(check(mid)) {
            ans = mid; 
            L = mid + eps;
        } else {
            R = mid - eps;
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
}   

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
