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
    int n, m, s, t;
	cin >> n >> m >> s >> t;

	s--;
	t--;

	vector<vi> graph(5 * n);
	rep(i, 0, m) {
		int u, v, o;
		cin >> u >> v >> o;

		u--;
		v--;

		if (o == 1) {
			graph[u].push_back(v + n);
			graph[u + n].push_back(v + 2 * n);
            graph[u + 3 * n].push_back(v + n);
            graph[u + 4 * n].push_back(v + n);

            graph[v].push_back(u + n);
			graph[v + n].push_back(u + 2 * n);
            graph[v + 3 * n].push_back(u + n);
            graph[v + 4 * n].push_back(u + n);
		}
		else {
			graph[u].push_back(v + 3 * n);
			graph[u + 3 * n].push_back(v + 4 * n);
            graph[u + n].push_back(v + 3 * n);
            graph[u + 2 * n].push_back(v + 3 * n);

            graph[v].push_back(u + 3 * n);
			graph[v + 3 * n].push_back(u + 4 * n);
            graph[v + n].push_back(u + 3 * n);
            graph[v + 2 * n].push_back(u + 3 * n);
		}
	}

	vi d(5 * n, 1e18);
	d[s] = 0;
	queue<int> q;
    q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	int res = min({d[t], d[t + n], d[t + 2 * n], d[t + 3 * n], d[t + 4 * n]});
	if (res == 1e18) {
		cout << -1 << endl;
	}
	else {
		cout << res << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
