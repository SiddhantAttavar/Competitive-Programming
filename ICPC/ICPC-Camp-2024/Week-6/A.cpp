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

const int MOD = (int) 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vi> a(n, vi(m));
	rep(i, 0, n) {
		string s;
		cin >> s;
		rep(j, 0, m) {
			a[i][j] = s[j] == 'B';
		}
	}

	vector<vi> dp(n, vi(m, 1));
	rep(i, 0, n) {
		rep(j, 0, m) {
			vector<pii> l = {
				{i - 1, j},
				{i + 1, j},
				{i, j - 1},
				{i, j + 1}
			};
			for (auto [x, y] : l) {
				if (x >= 0 and x < sz(a) and y >= 0 and y < sz(a[0]) and a[i][j] != a[x][y]) {
					dp[i][j] = 0;
				}
			}
		}
	}

	int res = 1;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (dp[i][j]) {
				res = res * 2 % MOD;
			}
		}
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
