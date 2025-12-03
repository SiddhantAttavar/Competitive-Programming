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
    vector<ll> c(n+1);
    for(ll i = 1; i <= n; i++) { cin >> c[i]; }

    vector<ll> a(n+1); for(ll i = 1; i <= n; i++) { a[i] = i; }

    vector<pair<ll, ll>> ops;
    vector<ll> fp(n+1);

    ll cp = n;
    for(cp = n; cp >= 1; cp--) {
        ll x = c[cp];
        // get x to the beginning of a
        ll ap = -1;
        for(ll i = 1; i <= n; i++) {
            if(a[i] == x) {
                ap = i;
                break;
            }
        }

        while(ap > 1) {
            ops.push_back({a[ap], a[ap-1]});
            swap(a[ap], a[ap-1]);
            ap--;
        }
    }



    for(ll i = 1; i <= n; i++) {
        assert(a[i] == c[i]);
    }

    cout << sz(ops) << endl;
    for(auto [x,y] : ops) {
        cout << x << " " << y << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
