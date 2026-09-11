#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bitset<6> dp[1 << 21][6];
vector<vi> m(6, vi(6, -1));
int res[1 << 21];

void solve() {
    int n;
	cin >> n;

	int z = 0;
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		z |= 1 << m[a - 1][b - 1];
	}

	cout << res[z] << endl;
}

signed main() {
	vi a, b;
	rep(x, 0, 6) {
		rep(y, 0, x + 1) {
			m[x][y] = sz(a);
			m[y][x] = sz(a);
			a.push_back(x);
			b.push_back(y);
		}
	}

	int n = 21;
	rep(i, 0, 1 << n) {
		fill(dp[i], dp[i] + 6, 0);
	}
	rep(i, 0, n) {
		dp[1 << i][a[i]][b[i]] = true;
	}
	rep(i, 1, 1 << n) {
		rep(x, 0, 6) {
			rep(y, 0, 6) {
				if (!dp[i][x][y]) {
					continue;
				}
				rep(j, 0, n) {
					if (i >> j & 1) {
						continue;
					}
					int k = i | (1 << j);
					if (x == a[j]) {
						dp[k][b[j]][y] = true;
					}
					if (x == b[j]) {
						dp[k][a[j]][y] = true;
					}
					if (y == a[j]) {
						dp[k][x][b[j]] = true;
					}
					if (y == b[j]) {
						dp[k][x][a[j]] = true;
					}
				}
			}
		}
	}

	rep(i, 0, 1 << n) {
		rep(a, 0, 6) {
			rep(b, 0, 6) {
				if (dp[i][a][b]) {
					res[i] = true;
				}
			}
		}
	}
	rep(i, 0, n) {
		rep(b, 0, 1 << n) {
			if (b >> i & 1) {
				res[b] += res[b ^ (1 << i)];
			}
		}
	}

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
