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
	int n, m;
	cin >> n >> m;

	vector<vi> a(n, vi(m));
	vi x(n, 0), y(m, 0);
	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> a[i][j];
			x[i] ^= a[i][j];
			y[j] ^= a[i][j];
		}
	}

	int c = accumulate(all(x), 0ll) + accumulate(all(y), 0ll), res = c;
	rep(i, 0, n) {
		rep(j, 0, m) {
			res = min(res, c - 2 * (x[i] & y[j]));
		}
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
