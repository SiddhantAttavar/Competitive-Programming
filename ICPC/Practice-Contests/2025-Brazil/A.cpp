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
    int n, m;
	cin >> n >> m;

	vector<vi> g(m, vi(n));
	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> g[j][i];
		}
	}

	int res = 0;
	rep(i, 0, m) {
		res += *max_element(all(g[i]));
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
