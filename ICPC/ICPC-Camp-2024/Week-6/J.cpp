#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 

const int MOD = (int) 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	vi c(n);
	rep(i, 0, n) {
		cin >> c[i];
	}

	vector<vi> a(n);
	rep(i, 0, n) {
		a[c[i] - 1].push_back(i);
	}

	vi v(n, -2);
	int res = 0;
	rep(i, 0, n) {
		rep(j, 0, sz(a[i]) / 2) {
			v[a[i][j]] = a[i][sz(a[i]) - j - 1];
			v[a[i][sz(a[i]) - j - 1]] = -1;
			res += a[i][sz(a[i]) - j - 1] - a[i][j];
		}
	}

	ordered_set o;
	rep(i, 0, n) {
		if (v[i] >= 0) {
			res -= o.order_of_key(v[i]);
			o.insert(v[i]);
		}
		else if (v[i] == -1) {
			o.erase(i);
		}
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
