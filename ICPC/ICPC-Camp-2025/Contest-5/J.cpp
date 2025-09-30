#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    set<ll> friends;
    vector<ll> f(n); for(ll i = 0; i < n; i++) { cin >> f[i]; friends.insert(f[i]); }

    ll ans = 0;

    vector<ll> freq(k+1, 0);
    vector<pair<ll, ll>> data;

    map<pair<ll, ll>, ll> mp;
    for(ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        data.push_back({a,b});
        if(friends.find(a) != friends.end() && friends.find(b) != friends.end()) {
            ans++;
        } else {
            if(a == b) {
                freq[a]++;
            } else {

                if(friends.find(a) != friends.end()) {
                    freq[b]++;
                } else if (friends.find(b) != friends.end()) {
                    freq[a]++;
                } else {
                    mp[{min(a,b), max(a,b)}]++;
                }

            }
        }
    }

    ll final_ans = ans;

    if(k == 1) {
        cout << final_ans << endl;
        return;
    }

    // for(ll i = 1; i <= k; i++) { 
    //     cout << i << ": " << freq[i] << endl;
    // }

    {
        multiset<ll> s;
        for(ll i = 1; i <= k; i++) {
            s.insert(freq[i]);
        }
        ll biggest = *(--s.end());
        s.erase(--s.end());
        ll second_biggest = *(--s.end());
        final_ans = max(final_ans, ans + biggest + second_biggest);
    }


    for(auto [p, x] : mp) {
        final_ans = max(final_ans, ans + x + freq[p.first] + freq[p.second]);
    }

    cout << final_ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT; cin >> TT;
    while(TT--) {
        solve();
    }
}
