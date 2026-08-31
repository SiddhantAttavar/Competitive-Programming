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
    int n, m, q;
	cin >> n >> m >> q;

	vector<array<int, 3>> a(n, {0, 1, 0}), b(m, {0, 0, 1});
	rep(i, 0, n) {
		cin >> a[i][0];
	}
	rep(i, 0, m) {
		cin >> b[i][0];
	}

	sort(all(a));
	sort(all(b));
	
	vector<array<int, 3>> c(n + m);
	merge(all(a), all(b), c.begin());

	a.push_back({0, 0, 0});
	b.push_back({0, 0, 0});
	c.push_back({0, 0, 0});

	reverse(all(a));
	reverse(all(b));
	reverse(all(c));

	rep(i, 1, n + 1) {
		a[i][0] += a[i - 1][0];
	}
	rep(i, 1, m + 1) {
		b[i][0] += b[i - 1][0];
	}
	rep(i, 1, n + m + 1) {
		c[i][0] += c[i - 1][0];
		c[i][1] += c[i - 1][1];
		c[i][2] += c[i - 1][2];
	}

	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;

		auto [s, i, j] = c[z];
		if (i > x) {
			cout << a[x][0] + b[z - x][0] << endl;
		}
		else if (j > y) {
			cout << a[z - y][0] + b[y][0] << endl;
		}
		else {
			cout << s << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
