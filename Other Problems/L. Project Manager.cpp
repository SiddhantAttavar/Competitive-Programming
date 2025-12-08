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

void add(int u, vector<vector<int>> &v, vector<queue<int>> &w, priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> &pq, int i = 1e18) {
	int d = 1e18;
	for (int j : v[u]) {
		d = min(d, w[j].front());
	}
	pq.push({d, i, u});
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	map<string, int> day = {
		{"Sunday", 0},
		{"Monday", 1},
		{"Tuesday", 2},
		{"Wednesday", 3},
		{"Thursday", 4},
		{"Friday", 5},
		{"Saturday", 6},
	};

	vector<vector<int>> v(n);
	rep(i, 0, n) {
		int l;
		cin >> l;
		while (l--) {
			string s;
			cin >> s;
			v[i].push_back(day[s]);
		}
	}

	const int N = 1e7;
	vector<bool> h(N + 1, false);
	rep(i, 0, m) {
		int x;
		cin >> x;
		if (x <= N) {
			h[x] = true;
		}
	}

	vector<vector<int>> p(k);
	rep(i, 0, k) {
		int l;
		cin >> l;
		p[i].resize(l);
		rep(j, 0, l) {
			cin >> p[i][j];
			p[i][j]--;
		}
	}

	vector<queue<int>> w(7);
	rep(i, 1, N + 1) {
		if (!h[i]) {
			w[i % 7].push(i);
		}
	}

	vector<int> res(k, 0), b(k, 0);
	vector<bool> d(n, false);
	vector<priority_queue<int, vector<int>, greater<int>>> a(n);
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
	rep(i, 0, k) {
		add(p[i][0], v, w, pq, i);
	}

	while (!pq.empty()) {
		auto [c, i, u] = pq.top();
		pq.pop();

		if (i < 1e18) {
			a[u].push(i);
			if (!d[u]) {
				add(u, v, w, pq);
				d[u] = true;
			}
			continue;
		}

		rep(j, 0, 7) {
			while (w[j].front() <= c) {
				w[j].pop();
			}
		}

		i = a[u].top();
		a[u].pop();
		b[i]++;

		if (b[i] == p[i].size()) {
			res[i] = c;
		}
		else {
			add(p[i][b[i]], v, w, pq, i);
		}

		if (a[u].empty()) {
			d[u] = false;
		}
		else {
			add(u, v, w, pq);
		}
	}

	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
