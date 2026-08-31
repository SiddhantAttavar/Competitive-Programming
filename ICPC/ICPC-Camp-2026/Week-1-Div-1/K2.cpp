#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi get(vi &p) {
	const int N = 1e18;
	vi l = {1};
	for (int i : p) {
		vi nl = l;
		int z = 1;
		while (z <= N / i) {
			z *= i;
			int x = N / z;
			for (int j : l) {
				if (j > x) {
					break;
				}
				nl.push_back(j * z);
			}
		}
		l = nl;
		sort(all(l));
	}
	return l;
}

int calc(int k, vi &x, vi &y) {
	int res = 0;
	for (int i : x) {
		res += upper_bound(all(y), k / i) - y.begin();
	}
	return res;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
	cin >> n;

	vi p(n);
	rep(i, 0, n) {
		cin >> p[i];
	}

	shuffle(all(p), rng);

	vi q;
	while (sz(p) > sz(q)) {
		q.push_back(p.back());
		p.pop_back();
	}

	int k;
	cin >> k;

	vi x = get(p), y = get(q);
	int l = 1, r = 1e18, res = 1e18;
	while (l <= r) {
		int m = (l + r) / 2;
		if (calc(m, x, y) >= k) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1;
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
