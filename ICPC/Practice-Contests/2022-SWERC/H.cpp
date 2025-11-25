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
    vector<ll> a(n); for(ll i = 0; i < n; i++) { cin >> a[i]; }
    vector<ll> b(n); for(ll i = 0; i < n; i++) { cin >> b[i]; }

    ll pb = n-1, pa = n-1;
    while(pb >= 0 && pa >= 0) {
        while(pa >= 0 && a[pa] != b[pb]) {
            pa--;
        }
        if(pa == -1) { break; }
        // matched. move on
        pb--;
    }
    cout << pb + 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
