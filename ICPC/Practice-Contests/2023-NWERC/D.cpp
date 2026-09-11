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
    int b, n;
	cin >> b >> n;

	int k = 1, z = b;
	rep(i, 0, n) {
		int c = z % n;
		if (c == 0) {
			cout << 1 << ' ' << k << endl;
			return;
		}
		if (c == 1) {
			cout << 2 << ' ' << k << endl;
			return;
		}
		if (c == n - 1) {
			cout << 3 << ' ' << k << endl;
			return;
		}
		k++;
		z = z * b % n;
	}
	cout << 0 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
