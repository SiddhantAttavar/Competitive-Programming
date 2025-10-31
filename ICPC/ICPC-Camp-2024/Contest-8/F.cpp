#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second

void solve() {
    ll n; cin >> n;
    
    vector<ll> dp(4*n + 1, 0);
    dp[0] = 1;

    vector<pair<ll, ll>> segs;
    for(ll i = 0; i < n; i++) {
        ll l, r; cin >> l >> r;
        l++, r++;
        segs.push_back({l, r});
    }
    sort(all(segs));


    vector<ll> smallest_r_that_starts_after(4*n + 1);
    {
        multiset<pair<ll, ll>> active_segs;
        ll seg_idx = 0;
        for(auto[l, r] : segs) {
            active_segs.insert({r, l});
        }

        for(ll i = 1; i <= 4*n; i++) {
            while(seg_idx < n && segs[seg_idx].ff < i) {
                active_segs.erase(active_segs.find({segs[seg_idx].ss, segs[seg_idx].ff}));
                seg_idx++;
            }
            smallest_r_that_starts_after[i] = active_segs.begin()->first;
        }
    }


    ll seg_idx = 0;

    multiset<pair<ll, ll>> active_segs;
    multiset<ll> aL; // active_segs left endpoints.

    vector<ll> par(4*n+1, -1);

    for(ll i = 1; i <= 4*n; i++) {
        while(seg_idx < n && segs[seg_idx].ff == i) {
            active_segs.insert({segs[seg_idx].ss, segs[seg_idx].ff});
            aL.insert(segs[seg_idx].ff);
            seg_idx++;
        }

        while(active_segs.empty() == false && (*(active_segs.begin())).first < i) { 
            aL.erase(aL.find(active_segs.begin()->second));
            active_segs.erase(active_segs.begin());
        }

        // i have active segs

        if(active_segs.empty() == false) {
            ll j = *aL.begin() - 1;

            if(smallest_r_that_starts_after[j+1] < i) {

            } else {
                dp[i] |= dp[j];
                if(dp[i] == 1) { par[i] = j; }
            }
        }

        if(aL.find(i) == aL.end()) {
            dp[i] |= dp[i-1];
            if(dp[i-1] == 1) { par[i] = -2; }
        }
    }

    if (!dp[4 * n]) {
        cout << -1 << endl;
        return;
    }

    // for (int i : dp) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (int i : par) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    
    int u = 4 * n;
    vector<int> res;
    while (par[u] != -1) {
        if (par[u] != -2) {
            res.push_back(u - 1);
            u = par[u];
        }
        else {
            u--;
        }
    }

    cout << res.size() << endl;
    for (int i : res) {
        cout << i << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
