#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    ll n, m; cin >> n >> m;
    vector<string> s(n); for(ll i = 0; i < n; i++) { cin >> s[i]; }

    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    for(ll r = 1; r < n; r++) {
        for(ll c = 0; c < m; c++) {

            for(ll dc = -1; dc <= 1; dc++) {
                ll nr = r-1;
                ll nc = c + dc;

                if(nc >= 0 && nc < m && s[nr][nc] != 'W') {
                    dp[r][c] = max(dp[r][c], dp[nr][nc] + (s[nr][nc] == 'B'));
                }

            }

        }
    }

    ll ans = 0;

    for(ll r = 0; r < n; r++) {
        for(ll c = 0; c < m; c++) {
            if(s[r][c] == 'W') {
                ans = max(ans, dp[r][c]);
            }
        }
    }

    cout << ans << endl;
}

 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}

}
