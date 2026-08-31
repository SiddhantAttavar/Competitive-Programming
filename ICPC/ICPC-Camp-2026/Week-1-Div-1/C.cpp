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
    int k;
	cin >> k;

	int N = 1e5;
	vector<array<int, 3>> v(k);
	rep(i, 0, k) {
		int x, y, r;
		cin >> x >> y >> r;
		v[i] = {x + 2 * N, y + 2 * N, r};
	}

	vector<vector<pii>> w(4 * N + 1, vector<pii>(k, {1e18, -1}));
	rep(x, 0, 4 * N + 1) {
		rep(i, 0, k) {
			if (abs(x - v[i][0]) > v[i][2]) {
				continue;
			}

			int l = v[i][1], r = 4 * N, q = v[i][1];
			while (l <= r) {
				int m = (l + r) / 2;
				if ((m - v[i][1]) * (m - v[i][1]) + (x - v[i][0]) * (x - v[i][0]) <= v[i][2] * v[i][2]) {
					q = m;
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			l = 0, r = v[i][1];
			int p = v[i][1];
			while (l <= r) {
				int m = (l + r) / 2;
				if ((m - v[i][1]) * (m - v[i][1]) + (x - v[i][0]) * (x - v[i][0]) <= v[i][2] * v[i][2]) {
					p = m;
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			w[x][i] = {p, q};
		}
	}

	int res = 0;
	rep(x, 0, 4 * N) {
		rep(j, 1, 1 << k) {
			int p = 0, q = 4 * N;
			rep(i, 0, k) {
				if (j >> i & 1) {
					p = max({p, w[x][i].first, w[x + 1][i].first});
					q = min({q, w[x][i].second, w[x + 1][i].second});
				}
			}
			int c = max(0ll, q - p);
			if (__builtin_popcountll(j) % 2) {
				res += c;
			}
			else {
				res -= c;
			}
		}
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
