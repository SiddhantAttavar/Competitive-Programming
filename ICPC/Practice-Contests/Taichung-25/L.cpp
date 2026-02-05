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

void solve() {
    int n, m, k;
	cin >> n >> m >> k;

	string s;
	cin >> s;

	vi x(n, 0);
	rep(i, 1, n) {
		x[i] = s[i] != s[i - 1];
	}

	vector<vi> dp(2, vi(m + 1, -1e18));
	dp[0][0] = 0;
	rep(i, 0, k) {
		rep(z, 0, m + 1) {
			dp[x[i]][z] = max(dp[0][z], dp[1][z]) + x[i];
			dp[!x[i]][z] = -1e18;
		}
		if (i == 0) {
			dp[1][0] = 0;
		}

		for (int j = i + k; j < n; j += k) {
			vector<vi> ndp(2, vi(m + 1, -1e18));
			ndp[x[j]][0] = max(dp[0][0], dp[1][0]) + x[j];
			rep(z, 1, m + 1) {
				ndp[x[j]][z] = max(dp[0][z], dp[1][z]) + x[j];
				ndp[!x[j]][z] = max(dp[0][z - 1] + (j > k), dp[1][z - 1] - (j > k)) + !x[j];
			}
			dp = ndp;
		}

		if (i != n % k) {
			continue;
		}

		vector<vi> ndp(2, vi(m + 1, -1e18));
		ndp[0][0] = max(dp[0][0], dp[1][0]);
		ndp[1][0] = max(dp[0][0], dp[1][0]);
		rep(z, 1, m + 1) {
			ndp[0][z] = max({dp[0][z], dp[1][z], dp[0][z - 1] + (n > k), dp[1][z - 1] - (n > k)});
			ndp[1][z] = max({dp[0][z], dp[1][z], dp[0][z - 1] + (n > k), dp[1][z - 1] - (n > k)});
		}
		dp = ndp;
	}
	cout << max(*max_element(all(dp[0])), *max_element(all(dp[1]))) + 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
