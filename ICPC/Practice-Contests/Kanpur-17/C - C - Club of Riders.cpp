#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

void solve() { 
    int x, y;
    cin >> x >> y;
    int z = x * y;

    int n;
    cin >> n;

    vector<int> g(n), s(n);
    rep(i, 0, n) {
        cin >> g[i];
    }
    rep(i, 0, n) {
        cin >> s[i];
    }
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());

    vector<int> a(n, 0);
    int l = 0;
    rep(i, 0, n) {
        while (l < n and g[i] * s[l] > z) {
            l++;
        }
        l--;
        a[i] = l + 1;
    }

    int res = 1;
    rep(i, 0, n) {
        if (a[i] <= i) {
            res = 0;
            break;
        }
        res = res * (a[i] - i) % MOD;
    }
    cout << res << endl;
}
signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); int t; cin >> t; 
    int i = 0;
    while (t--) {
        cout << "Case " << ++i <<": ";
        solve();
    } 
}
