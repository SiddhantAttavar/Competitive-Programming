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

	vector<vector<pii>> a(30), b(30);
	rep(i, 0, m) {
		int l, r, q;
		cin >> l >> r >> q;
		l--;
		r--;
		rep(j, 0, 30) {
			if (q >> j & 1) {
				a[j].push_back({l, r});
			}
			else {
				b[j].push_back({l, r});
			}
		}
	}

	vi res(n, 0);
	rep(j, 0, 30) {
		vi z(n + 1, 0);
		for (auto [l, r] : a[j]) {
			z[l]++;
			z[r + 1]--;
		}
		rep(i, 0, n) {
			z[i + 1] += z[i];
		}

		vi x(n, -1);
		rep(i, 0, n) {
			if (z[i]) {
				res[i] |= 1 << j;
				x[i] = i ? x[i - 1] : -1;
			}
			else {
				x[i] = i;
			}
		}

		for (auto [l, r] : b[j]) {
			if (x[r] < l) {
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
