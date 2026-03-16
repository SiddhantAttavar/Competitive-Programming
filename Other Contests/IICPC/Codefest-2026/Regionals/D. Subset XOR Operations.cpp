#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD = 998244353;

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

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

const int N = 1000;
vi pow2(N + 1, 1);

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	k = min(k, m);

	vi dp(k + 1, 0);
	dp[0] = 1;
	rep(i, 0, n) {
		vi ndp(k + 1, 0);
		ndp[0] = 1;
		rep(x, 1, k + 1) {
			ndp[x] = (dp[x] * pow2[x] + dp[x - 1]) % MOD;
		}
		dp = ndp;
	}
	// rep(i, 0, k + 1) {
	// 	cout << dp[i] << ' ';
	// }
	// cout << endl;

	int res = 0, y = 1;
	rep(i, 0, k + 1) {
		// cout << dp[i] << ' ' << y << endl;
		res = (res + dp[i] * y) % MOD;
		y = y * (pow2[m] - pow2[i] + MOD) % MOD;
	}
	cout << res << endl;
}

signed main() {
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
}
