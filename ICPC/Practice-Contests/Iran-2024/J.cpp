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

constexpr ll inf = 1E18;

void solve() {

    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for (ll i = 1; i <= n; ++i) { for (ll j = 1; j <= m; ++j) { cin >> a[i][j]; }}

    vector<vector<ll>> nl(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> nr(n + 1, vector<ll>(m + 1, m + 1));
    vector<vector<ll>> nu(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> nd(n + 1, vector<ll>(m + 1, n + 1));

    // nl, nr
    for(ll i = 1; i <= n; i++) {

        vector<ll> stk;

        for(ll j = 1; j <= m; j++) {
            while(stk.empty() == false && a[i][stk.back()] > a[i][j]) {
                stk.pop_back();
            }

            nl[i][j] = (stk.empty() ? 0 : stk.back());
            stk.push_back(j);
        }

        stk.clear();
        for(ll j = m; j >= 1; j--) {
            while(stk.empty() == false && a[i][stk.back()] > a[i][j]) {
                stk.pop_back();
            }

            nr[i][j] = (stk.empty() ? (m+1) : stk.back());
            stk.push_back(j);
        }
    }

    // nu, nd
    for(ll j = 1; j <= m; j++) {

        vector<ll> stk;

        for(ll i = 1; i <= n; i++) {
            while(stk.empty() == false && a[stk.back()][j] > a[i][j]) {
                stk.pop_back();
            }

            nu[i][j] = (stk.empty() ? 0 : stk.back());
            stk.push_back(i);
        }

        stk.clear();
        for(ll i = n; i >= 1; i--) {
            while(stk.empty() == false && a[stk.back()][j] > a[i][j]) {
                stk.pop_back();
            }

            nd[i][j] = (stk.empty() ? (n+1) : stk.back());
            stk.push_back(i);
        }
    }

    vector<vector<array<ll, 3>>> db(n+2); // down bucket[x] = cells with nd == x : {nu, nl, nr}.

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(nu[i][j] == 0 || nd[i][j] == n+1) { continue; }
            if(nl[i][j] == 0 || nr[i][j] == m+1) { continue; }
            db[nd[i][j]].push_back({nu[i][j], nl[i][j], nr[i][j]});
        }
    }

    ll final_ans = 0;

    for(ll top = 1; top <= n; top++) {
        vector<ll> best_r(m+2, inf);

        for(ll bott = top; bott <= n; bott++) {

            // ensure "Active" cells can only come in from left or right
            for(auto[up, L, R] : db[bott]) {
                if(top <= up) {
                    best_r[L] = min(best_r[L], R);
                }
            }

            vector<ll> suf(m+3, inf);
            // suf[l] = min R among active segs with L >= l.
            for(ll i = m; i >= 1; i--) {
                suf[i] = min(best_r[i], suf[i+1]);
            }

            for(ll l = 1; l <= m; l++) {
                ll mx_r;
                if(suf[l] == inf) {mx_r = m;}
                else {mx_r = suf[l] - 1;}

                if(mx_r >= l) {
                    final_ans += (mx_r - l + 1);
                }
            }

        }
    }
    cout << final_ans << endl;

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}

