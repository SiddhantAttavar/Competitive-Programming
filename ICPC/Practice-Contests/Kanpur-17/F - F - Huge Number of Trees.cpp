#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 500;
const int D = 10;
const int K = 10;
int dp[D + 1][N + 1][K + 1];

void solve() { 
    int n, d;
    cin >> n >> d;
    int res = 0;
    rep(i, 1, K + 1) {
        res += dp[d][n][i];
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); int t; cin >> t; 
    int i = 0;
    while (t--) {
        solve();
    } 
}
