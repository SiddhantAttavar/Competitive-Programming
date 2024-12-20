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

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() { 
    int n, m;
    cin >> n >> m;
    rep(i, 0, m) {
        string s;
        cin >> s;
        int k = s.size();
        if (k > n) {
            cout << "0\n";
        }
        else {
            cout << (mod_pow(26, n - k) * (n - k + 1)) % MOD << endl;
        }
    }

}
signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); int t; cin >> t; 
    int i = 0;
    while (t--) {
        cout << "Case " << ++i <<":\n";
        solve();
    } 
}
