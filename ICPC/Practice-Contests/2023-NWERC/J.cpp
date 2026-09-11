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
    int t, s;
	cin >> t >> s;

	int x;
	cin >> x;
	if (s == 1) {
		cout << (t % x == 0) << endl;
		return;
	}

	int y;
	cin >> y;
	if (s == 2) {
		int res = 0;
		rep(q, 0, y) {
			int u = t - q * x;
			if (u >= 0 and u % y == 0) {
				res += (u / y) / x + 1;
			}
		}
		cout << res << endl;
		return;
	}

	int z;
	cin >> z;

	int res = 0;
	rep(q, 0, z) {
		rep(s, 0, z) {
			int u = t - x * q - y * s;
			if (u < 0 or u % z) {
				continue;
			}
			u /= z;
			rep(g, 0, y) {
				int v = u - g * x;
				if (v >= 0) {
					v /= y;
					res += (v / x + 1) * (v + v % x + 2) / 2;
				}
			}
		}
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
