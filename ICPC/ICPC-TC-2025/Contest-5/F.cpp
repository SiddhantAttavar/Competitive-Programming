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

	vector<int> a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}

	vector<int> s(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		s[i] = (s[i + 1] + a[i]) % 10;
	}

	vector<vi> v(10);
	rep(i, 0, n + 1) {
		v[s[i]].push_back(i);
	}

	vector<int> res(n);
	rep(i, 0, n) {
		int j = lower_bound(v[s[i]].begin(), v[s[i]].end(), i) - v[s[i]].begin();
		if (j == sz(v[s[i]]) - 1) {
			cout << -1 << ' ';
		}
		else {
			cout << v[s[i]][j + 1] - i << ' ';
		}
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
