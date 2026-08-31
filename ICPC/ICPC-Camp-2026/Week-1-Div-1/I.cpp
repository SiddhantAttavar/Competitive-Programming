#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void solve() {
    int n;
	cin >> n;

	vi s(n);
	rep(i, 0, n) {
		cin >> s[i];
	}

	vector<vector<array<int, 3>>> z(n);
	rep(i, 0, n) {
		if (s[i] == *max_element(all(s))) {
			continue;
		}

		int j = (i + 1) % n;
		while (s[j] < s[i]) {
			j = (j + 1) % n;
		}
		int k = (i - 1 + n) % n;
		while (s[k] < s[i]) {
			k = (k - 1 + n) % n;
		}

		z[(k - j + 1 + 2 * n) % n].push_back({(j - i - 1 + 2 * n) % n, (i - k - 1 + 2 * n) % n, i});
	}

	vector<vector<ld>> dp(n, vector<ld>(n, 0));
	vector<ld> res(n, 1);
	rep(k, 1, n) {
		vector<vector<ld>> ndp(n, vector<ld>(n, 0));
		rep(l, 0, n) {
			rep(r, 0, n) {
				if (l + r + k + 1 == 2) {
					ndp[l][r] = 1;
					continue;
				}
				if (l > 0) {
					ndp[l][r] += ndp[l - 1][r] * (l + 1);
				}
				if (r > 0) {
					ndp[l][r] += ndp[l][r - 1] * (r + 1);
				}
				if (k > 1) {
					ndp[l][r] += dp[l][r] * (k - 1);
				}
				ndp[l][r] /= l + r + k + 1;
			}
		}
		dp = ndp;
		for (auto [l, r, i] : z[k]) {
			res[i] = dp[l][r];
		}
	}

	cout << fixed << setprecision(15);
	for (ld i : res) {
		cout << i << endl;
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
