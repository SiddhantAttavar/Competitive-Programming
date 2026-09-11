#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int f(int x) {
	int res = 0;
	x >>= 1;
	while (x) {
		res += x;
		x >>= 1;
	}
	return res;
}

void solve() {
    int a, b;
	cin >> a >> b;

	int res = 0;
	rep(i, max(0ll, a - 60), a) {
		rep(j, max(0ll, b - 60), b) {
			res = max(res, i + j + f(i) + f(j) - f(i + j) + 1);
		}
	}
	cout << mpow(2, res) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
