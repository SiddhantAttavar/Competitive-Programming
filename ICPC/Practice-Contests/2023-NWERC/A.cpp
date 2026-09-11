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
    int x, k;
	cin >> x >> k;

	vector<queue<pii>> v(k);
	rep(i, 0, k) {
		int l;
		cin >> l;

		int c = 0, z = 0;
		rep(j, 0, l) {
			int a;
			cin >> a;
			c += a;
			z = min(z, c);
			if (c > 0) {
				v[i].push({z, c});
				c = 0;
				z = 0;
			}
		}
	}

	priority_queue<array<int, 3>> pq;
	rep(i, 0, k) {
		if (!v[i].empty()) {
			auto [z, c] = v[i].front();
			v[i].pop();
			pq.push({z, c, i});
		}
	}

	while (!pq.empty()) {
		auto [z, c, i] = pq.top();
		pq.pop();

		if (x + z < 0) {
			break;
		}

		x += c;
		if (!v[i].empty()) {
			auto [z, c] = v[i].front();
			v[i].pop();
			pq.push({z, c, i});
		}
	}
	cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
