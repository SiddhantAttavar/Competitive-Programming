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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void solve() {
	int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vi> graph(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vector<pii> d(n, {-1, -1});
    queue<int> q;
    rep(i, 0, n) {
        if (s[i] == '1') {
            d[i] = {0, i};
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (d[v].first == -1) {
                d[v] = {d[u].first + 1, d[u].second};
                q.push(v);
            }
        }
    }

    UF u(n);
    vector<array<int, 3>> l;
    rep(i, 0, n) {
        for (int j : graph[i]) {
            l.push_back({d[i].first + d[j].first + 1, d[i].second, d[j].second});
        }
    }
    sort(all(l));
    int res = 0;
    for (auto [w, i, j] : l) {
        if (u.join(i, j)) {
            res += w;
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
