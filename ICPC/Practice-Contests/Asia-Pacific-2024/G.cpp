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
	ll n, m, k; cin >> n >> m >> k;
    vector<string> s(n);
    for(ll i = 0; i < n; i++) { cin >> s[i]; }


    vector<vector<vector<ll>>> solved(m, vector<vector<ll>>(26, vector<ll>()));

    {
        ll b = 0;
        for(ll i = 0; i < m; i++) {
            if(s[b][i] == '.') { continue; }
            solved[i][s[b][i] - 'A'].push_back(b);
        }
    }

    for(ll b = 1; b < n; b++) {

        auto check = [&](ll a) -> bool {
            // >= a.
            vector<ll> mp(n, 0);
            for(ll i = 0; i < m; i++) {
                if(s[b][i] == '.') { continue; }
                for(auto x : solved[i][s[b][i] - 'A']) {
                    if(x >= a) {
                        mp[x]++;
                        if(mp[x] >= k) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }; 

        ll l = 0, r = b-1, ans = -1;
        while(l <= r) {
            ll mid = l + (r-l)/2;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if(ans != -1) {
            cout << ans+1 << " " << b+1 << endl;
            return;
        }

        // update solved.
        for(ll i = 0; i < m; i++) {
            if(s[b][i] == '.') { continue; }
            solved[i][s[b][i] - 'A'].push_back(b);
        }
    }

    cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
