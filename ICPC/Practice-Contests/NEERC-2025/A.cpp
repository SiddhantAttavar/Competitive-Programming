#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2000, K = 500;

void solve() {
    int n;
	cin >> n;

	vector<array<int, 3>> a(n);
	rep(i, 0, n) {
		char c;
		int x;
		string s;
		cin >> c >> x >> s;
		a[i] = {x, c == '+', s == "sync"};
	}
	a.insert(a.begin(), {0, false, true});
	n++;

	int u = 0;
	rep(i, 0, n) {
		if (!a[i][1]) {
			u = i;
		}
	}

	vi s(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		s[i] = s[i + 1] + a[i][0];
	}

	bitset<N * K + 1> dp1 = 1, dp2 = 0, res = 0;
	rep(i, 0, n) {
		if (i >= u) {
			dp2 |= dp1 << s[i + 1];
		}
		if (i == u) {
			res |= dp2 << a[i][0];
		}
		if (!a[i][2] and a[i][1]) {
			dp1 |= dp1 << a[i][0];
		}
	}

	rep(i, 0, n) {
		if (!a[i][1] and !a[i][2]) {
			res |= dp2 << a[i][0];
		}
	}
	cout << res.count() << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
