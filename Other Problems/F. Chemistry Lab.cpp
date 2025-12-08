#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	double k;
	cin >> n >> k;
	k /= 100;

	vector<array<int, 3>> v(n);
	rep(i, 0, n) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	sort(v.begin(), v.end());

	vector<double> dp(n);
	rep(i, 0, n) {
		dp[i] = -v[i][1];
		rep(j, 0, i) {
			dp[i] = max(dp[i], dp[j] + k * (v[i][0] - v[j][0]) * (v[i][2] + v[j][2]) / 2 - v[i][1]);
		}
	}

	cout << fixed << setprecision(15);
	cout << max(0.0, *max_element(dp.begin(), dp.end())) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
