#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> dg(n+1);
    for(ll i = 2; i <= n; i++) {
        ll par; cin >> par;
        dg[par].push_back(i);
    }

    vector<ll> ht(n+1, 0);
    map<ll, ll> freq;
    function<void(ll)> dfs = [&](ll v) -> void {
        for(auto x : dg[v]) {
            dfs(x);
            ht[v] = max(ht[v], ht[x]+1);
        }
        freq[ht[v]]++;
    };
    dfs(1);
    ll ans = n+1;
    for(auto [height, num] : freq) {
        ans = min(ans, height + num);
    }
    cout << ans << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll T; cin >> T;
    while(T--) { solve(); }
}
