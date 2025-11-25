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

// check if m is less than 0, then return -1e18
int fn(vi& gaps, int m, int k){
    int n = gaps.size()-1;
    // rep(i, 0, n+1){
    //     cout << gaps[i] << " ";
    // }cout << endl;
    
    if(m < 0){
        return -1;
    }
    vector<vi> subs(k);
    vector<vi> fv(k);
    for(int i = 1; i<n; i++){
        subs[(i%k)].push_back(gaps[i]);
    }
    // for(auto it : subs){
    //     for(auto it1 : it){
    //         cout << it1 << " ";
    //     }cout << endl;
    // }

    vi f(m + 1, -100), g(m + 1, -100);
    g[0] = 0;
    for(auto it : subs){
        if (it.empty()) continue;
        int n1 = it.size();
        vi nf(m + 1, -100), ng(m + 1, -100);
        rep(x, 1, m + 1) {
            nf[x] = max(f[x - 1], g[x - 1]) + 1 - it[0];
        }
        rep(x, 0, m + 1) {
            ng[x] = max(f[x], g[x]) + it[0];
        }
        f = nf;
        g = ng;
        for(int i = 1; i<n1; i++){
            vi nf(m + 1, -100), ng(m + 1, -100);
            rep(x, 1, m + 1) {
                nf[x] = max(
                    f[x - 1] + it[i - 1] - (1 - it[i - 1]) + 1 - it[i],
                    g[x - 1] + (1 - it[i - 1]) - it[i - 1] + 1 - it[i]
                );
            }
            rep(x, 0, m + 1) {
                ng[x] = max(
                    f[x] + it[i],
                    g[x] + it[i]
                );
            }
            f = nf;
            g = ng;
        }
        // rep(i, 0, m + 1) {
        //     cout << f[i] << ' ';
        // }
        // cout << endl;
        // rep(i, 0, m + 1) {
        //     cout << g[i] << ' ';
        // }
        // cout << endl;
    }
    
    int res = 0;
    rep(i, 0, m + 1) {
        res = max({res, f[i], g[i]});
    }
    // cout << endl;
    return res;
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vi gaps(n+1, 1);
    rep(i, 0, n-1){
        if(s[i] == s[i+1]){
            gaps[i+1] = 0;
        }
    }
    int ex = accumulate(gaps.begin(), gaps.end(), 0ll) - 2;
    if(m == 0 || n == k){
        cout << accumulate(gaps.begin(), gaps.end(), 0ll) - 1 << endl;
        return;
    }
    // rep(i, 0, n+1){
    //     cout << gaps[i] << " ";
    // }cout << endl;
    // dont take both
    ex = max(ex, fn(gaps, m, k));
    bool changed = false;
    if(gaps[k] == 0){
        changed= true;
    }
    gaps[k] = 1;
    ex = max(ex, fn(gaps, m-1, k));
    gaps[n-k] = 1;
    ex = max(ex, fn(gaps, m-2, k));
    if(changed){
        gaps[k] = 0;
    }
    ex = max(ex, fn(gaps, m-1, k));
    int ans = 1 + ex;
    
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
