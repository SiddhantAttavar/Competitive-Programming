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
const int MOD = 998244353;

void solve() {
	int n;
    cin >> n;

    vi pow2(n + 1, 1);
    rep(i, 1, n + 1) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
        a[i]--;
    }

    vi dp(n, 0);
    dp[0] = 1;
    rep(i, 1, n) {
        vi p(n + 1, 0);
        rep(j, 0, n) {
            p[j + 1] = (p[j] + dp[j]) % MOD;
        }
        rep(j, 0, i) {
            dp[j] = p[j + (a[i] > a[i - 1])] * pow2[i - j - 1] % MOD;
        }
    }
    cout << accumulate(all(dp), 0ll) % MOD << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
