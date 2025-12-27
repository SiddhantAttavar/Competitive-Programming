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
    int n, m;
	cin >> n >> m;

    vector<vi> ncr(21, vi(21, 0));
    vector<int> dp(n + m + 1, 0);
    rep(x, 1, n + 1) {
        rep(y, 1, m + 1) {
            dp[x + y]++;
        }
    }

    int k = *max_element(dp.begin(), dp.end());
    rep(i, 0, n + m + 1) {
        if (dp[i] == k) {
            cout << i << endl;
        }
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
