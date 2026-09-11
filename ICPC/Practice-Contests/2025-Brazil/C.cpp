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

	int x = 0;
	rep(i, 0, n + 1) {
		int y;
		cin >> y;
		x = 2 * x + y;
	}

	int res = 0;
	while (x > 1) {
		res++;
		if (x & 1) {
			x ^= (x << 1) ^ 1;
		}
		else {
			x >>= 1;
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
