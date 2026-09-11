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
    int n;
	cin >> n;

	bitset<4096> c = 0;
	string s;
	cin >> s;
	rep(i, 0, n) {
		c[i] = s[i] == '1';
	}

	pii res = {1e18, -1};
	rep(b, 0, 1 << 8) {
		vi dp(1 << 7), x(1 << 7, 0);
		rep(j, 0, 1 << 7) {
			dp[j] = __builtin_popcount(j);
			x[j] = __builtin_popcount(j & b) & 1;
		}
		rep(i, 0, n) {
			vi ndp(1 << 7, 1e18);
			rep(j, 0, 1 << 7) {
				if (x[j] == c[i]) {
					ndp[j >> 1] = min(ndp[j >> 1], dp[j]);
				}
				if ((x[j] ^ (b >> 7 & 1)) == c[i]) {
					ndp[(j >> 1) | (1 << 6)] = min(ndp[(j >> 1) | (1 << 6)], dp[j] + 1);
				}
			}
			dp = ndp;
		}
		res = min(res, {*min_element(all(dp)), b});
	}
	cout << bitset<8>(res.second) << ' ' << res.first << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
