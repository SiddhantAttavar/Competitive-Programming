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

const ll MOD = 998244353;

void norm(ll& a) {
    if(a < -MOD || a >= MOD) { a %= MOD; }
    if(a < 0) {a += MOD; }
}

void add(ll& a, ll b) {
    norm(a); norm(b);
    a += b;
    norm(a);
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); for(ll i = 0; i < n; i++) { cin >> a[i]; }
    map<ll, ll> dp;
    map<pair<ll, ll>, ll> mp;
    dp[0] = 1;
    for(ll i = 0; i < n; i++) {

        // cout << sz(mp) << " " << sz(dp) << endl;

        ll ele = a[i];
        map<ll, ll> new_dp;
        map<pair<ll, ll>, ll> new_mp;

        for(auto [p, ways] : mp) {
            auto [y, x] = p;
            if(y <= (x | ele)) {
                add(new_dp[(x | ele)], ways);
            } else {
                add(new_mp[{y, (x | ele)}], ways);
            }
        }
        for(auto [x, ways] : dp) { add(new_dp[(x | ele)], ways); }
        for(auto [x, ways] : new_dp) {add(new_mp[{x, 0}], ways); }

        dp.swap(new_dp);
        mp.swap(new_mp);
    }
    ll ans = 0;
    for(auto [x, ways] : dp) {
        add(ans, ways);
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
