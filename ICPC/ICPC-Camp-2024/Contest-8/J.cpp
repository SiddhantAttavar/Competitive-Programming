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
    ll n; cin >> n;
    vector<ll> a(n), b(n), delta(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ll cnt_0 = 0;
    ll non_zeroes = 0, zeroes = 0;

    for(ll i = 0; i < n; i++) {
        if(b[i] == 0) {
            delta[i] = -1;
            cnt_0++;
            zeroes += a[i];
        } else {
            delta[i] = a[i] - b[i] + 1;
            non_zeroes += a[i];
        }
    }

    sort(all(delta));

    if(cnt_0 >= 2) {
        cout << delta[n-1] << " " << non_zeroes << endl;
    } else if (cnt_0 == 1) {
        cout << delta[n-1] + 1 << " " << zeroes + non_zeroes << endl;
    } else {
        cout << min(delta[n-1], delta[n-2] + 1) << " " << non_zeroes << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
