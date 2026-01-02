#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int p, k;
    cin >> p >> k;

    int res = 0;
    rep(i, 0, p) {
        int n;
        cin >> n;

        vi v(n);
        rep(i, 0, n) {
            cin >> v[i];
        }

        vector<int> dp(n + 1, 0);
        multiset<int> m;
        rep(i, 0, n) {
            if (v[i] <= i + 1) {
                m.insert(dp[i + 1 - v[i]]);
            }
            int j = i - (k + 1);
            if (j >= 0 and v[j] <= j + 1) {
                m.erase(m.find(dp[j + 1 - v[j]]));
            }
            dp[i + 1] = 0;
            while (m.count(dp[i + 1])) {
                dp[i + 1]++;
            }
        }
        res ^= dp[n];
    }
    
    if (res) {
        cout << "Alice can win.\n";
    }
    else {
        cout << "Bob will win.\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
