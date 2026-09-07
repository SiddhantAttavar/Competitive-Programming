#include <bits/stdc++.h>
using namespace std;

#define int __int128_t
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	ll x;
	cin >> x;

	int res = 0;
	if (x > 0) {
		res = 1;
		rep(j, 0, x + 1) {
			res = 10 * res;
		}
	}

	rep(i, 1, 10) {
		ll x;
		cin >> x;

		int z = 0;
		rep(j, 0, x + 1) {
			z = 10 * z + i;
		}
		res = min(res, z);
	}

	cout << (ll) (res - 1) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
