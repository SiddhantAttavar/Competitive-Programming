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

	vi x(n), y(n);
	rep(i, 0, n) {
		cin >> x[i] >> y[i];
	}

	// int k = 1;
	// while ((k + 1) * (k + 1) <= m) {
	// 	k++;
	// }
	int k = 300;
	// cout << k << endl;
	
	vector<vector<pii>> v(n);
	rep(i, 0, m) {
		int o, k;
		cin >> o >> k;
		k--;
		// cout << o << ' ' << k << endl;
		// cout.flush();
		if (o == 1) {
			v[k].push_back({i, m});
		}
		else {
			v[k].back().second = i;
		}
	}
	
	vi res(m + 1, 0);
	vi a(m + 1, -1);
	rep(i, 0, n) {
		int s = x[i] + y[i];
		if (s <= k) {
			for (auto [l, r] : v[i]) {
				a[l] = i;
				a[r] = i;
			}
			continue;
		}
		for (auto [l, r] : v[i]) {
			for (int j = l + x[i]; j < r; j += s) {
				res[j]++;
				res[min(r, j + y[i])]--;
			}
		}
	}
	rep(i, 1, m) {
		res[i] += res[i - 1];
	}
	// rep(i, 0, m) {
	// 	cout << res[i] << ' ';
	// }
	// cout << endl;

	vector<vi> dp(k + 1, vi(k + 1, 0));
	vi w(n, -1);
	rep(t, 0, m) {
		if (a[t] != -1 and w[a[t]] == -1) {
			int i = a[t];
			w[i] = t;
			int s = x[i] + y[i];
			int j = (w[i] + x[i]) % s;
			rep(k, 0, y[i]) {
				dp[s][j]++;
				j++;
				if (j == s) {
					j = 0;
				}
			}
		}
		else if (a[t] != -1) {
			int i = a[t];
			int s = x[i] + y[i];
			int j = (w[i] + x[i]) % s;
			rep(k, 0, y[i]) {
				dp[s][j]--;
				j++;
				if (j == s) {
					j = 0;
				}
			}
			w[i] = -1;
		}

		int z = res[t];
		rep(s, 2, k + 1) {
			z += dp[s][t % s];
			// cout << t << ' ' << s << ' ' << dp[s][t % s] << endl;
		}
		cout << z << endl;
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
