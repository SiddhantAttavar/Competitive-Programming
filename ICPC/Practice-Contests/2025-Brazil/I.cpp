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

	vi v;
	int x, y;
	cin >> x >> y;
	rep(i, 1, n) {
		int s, t;
		cin >> s >> t;
		v.push_back(abs(x - s) + abs(y - t));
		tie(x, y) = make_pair(s, t);
	}

	int l = 1, r = v[0] - 1;
	for (int x : v) {
		tie(l, r) = make_pair(max(1ll, x - r), min(x - 1, x - l));
		if (l > r) {
			cout << -1 << endl;
			return;
		}
	}
	reverse(all(v));
	for (int x : v) {
		tie(l, r) = make_pair(max(1ll, x - r), min(x - 1, x - l));
	}
	cout << r << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
