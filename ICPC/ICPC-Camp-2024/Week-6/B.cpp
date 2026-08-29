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

const int MOD = (int) 1e9 + 7;


void solve() {
	int n, m;
	cin >> n >> m;

	vector<set<int>> radj(n);
	set<pii> s;
	while (m--) {
		int u, v;
		cin >> u >> v;

		radj[v - 1].insert(u - 1);
		s.insert({u - 1, v - 1});
	}

	queue<int> q;
	vi b(n, false);
	rep(i, 0, n) {
		if (sz(radj[i]) == 1) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (radj[u].empty()) {
			break;
		}

		b[u] = true;
		int v = *radj[u].begin();
		radj[u].erase(v);

		if (s.count({u, v})) {
			radj[v].erase(u);
			if (!b[v] and sz(radj[v]) == 1) {
				q.push(v);
			}
		}
	}

	rep(i, 0, n) {
		if (!b[i] and radj[i].empty()) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
