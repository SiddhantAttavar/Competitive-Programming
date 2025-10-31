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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vector<bool> b(n, false);
    vector<int> dp(k + 1, 0);
    dp[0] = 1e18;
    rep(i, 0, n) {
        if (dp[a[i]] + 1 < dp[a[i] - 1]) {
            dp[a[i]]++;
            b[i] = true;
        }
        else {
            dp[a[i]] = dp[a[i] - 1];
        }
    }

    int u = min_element(dp.begin(), dp.begin() + k + 1) - dp.begin();
    vector<int> res;
    for (int i = n - 1; i >= 0; i--) {
        if (u != a[i]) {
            continue;
        }
        if (b[i]) {
            res.push_back(i);
        }
        else {
            u--;
        }
    }

    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i : res) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
