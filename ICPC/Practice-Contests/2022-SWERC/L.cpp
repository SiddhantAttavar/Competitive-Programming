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

#define yay {cout << "YES" << endl; continue; }
#define meh {cout << "NO" << endl; continue; }

void solve() {
	ll n; cin >> n;
    string s; cin >> s;
    ll pos = count(all(s), '+');
    ll neg = count(all(s), '-');

    ll Q; cin >> Q;
    for(ll _ = 0; _ < Q; _++) {
        ll a, b; cin >> a >> b;
        if(a < b) { swap(a, b); }
        
        if(neg == pos) { yay; }
        
        // neg != pos && a == b
        if(a == b) { meh; }

        ll rhs = b*(neg - pos);

        if((abs(rhs) % (a-b)) != 0) { meh; }

        ll q = rhs / (a-b);

        if(neg - pos > 0) {
            if(0 < q && q <= pos) {
                yay;
            } else {
                meh;
            }
        }
        if(neg - pos < 0) {
            if(-neg <= q && q < 0) {
                yay;
            } else {
                meh;
            }
        }

    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
