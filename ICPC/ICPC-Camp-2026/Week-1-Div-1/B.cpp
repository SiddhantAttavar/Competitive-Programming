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

	vi c(n);
	rep(i, 0, n) {
		cin >> c[i];
	}

	int res = 0;
	while (!c.empty()) {
		res++;
		int d = 0;
		for (int i : c) {
			d += i % 2;
		}

		if (d != 1) {
			cout << -1 << endl;
			return;
		}

		vi nc;
		for (int i : c) {
			if (i / 2) {
				nc.push_back(i / 2);
			}
		}
		c = nc;
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
